#include "vfh/vfh_algorithm.h"

VFH_Algorithm::VFH_Algorithm(float robot_radius,
                             float cell_width,
                             int window_diameter,
                             int sectors_number
                            )
{
    ROBOT_RADIUS     = robot_radius;
    CELL_WIDTH       = cell_width;
    WINDOW_DIAMETER  = window_diameter;
    SECTORS_NUMBER   = sectors_number;

    CENTER_X = 0;
    CENTER_Y = 0;

    Init();
}

// Convención angular:
// 0 rad  -> +X (adelante)
// π/2    -> +Y (izquierda)
// π      -> -X (atrás)
// 3π/2   -> -Y (derecha)
// sentido antihorario

int VFH_Algorithm::Init()
{
    // Centro del grid
    CENTER_X = WINDOW_DIAMETER / 2;
    CENTER_Y = WINDOW_DIAMETER / 2;

    sector_angle = 2.0 * M_PI / SECTORS_NUMBER;

    HIST_SIZE = SECTORS_NUMBER;

    Hist_primary.resize(HIST_SIZE);
    Hist_binary.resize(HIST_SIZE);
    Hist_masked.resize(HIST_SIZE);

    // Reservar memoria
    Cell_Direction.assign(WINDOW_DIAMETER,
                          std::vector<float>(WINDOW_DIAMETER, 0.0f));

    Cell_Base_Mag.assign(WINDOW_DIAMETER,
                         std::vector<float>(WINDOW_DIAMETER, 0.0f));

    Cell_Mag.assign(WINDOW_DIAMETER,
                    std::vector<float>(WINDOW_DIAMETER, 0.0f));

    Hist_primary.assign(HIST_SIZE, 0.0f);
    Hist_binary.assign(HIST_SIZE, 0.0f);
    Last_Binary_Hist.assign(HIST_SIZE, 0.0f);
    Hist_masked.assign(HIST_SIZE, 0.0f);

    // Radio máximo del grid
    const float max_radius =
        (WINDOW_DIAMETER / 2.0f) * CELL_WIDTH;

    // Inicialización geométrica
    for(int x = 0; x < WINDOW_DIAMETER; ++x)
    {
        for(int y = 0; y < WINDOW_DIAMETER; ++y)
        {
            float dx = (x - CENTER_X) * CELL_WIDTH;
            float dy = (y - CENTER_Y) * CELL_WIDTH;

            float dist = std::hypot(dx, dy);

            // Peso base normalizado
            float norm = std::max(max_radius - dist, 0.0f) / max_radius;
            Cell_Base_Mag[x][y] = std::pow(norm, 4);

            // Dirección en radianes [0, 2π)
            float angle = std::atan2(dy, dx);
            if(angle < 0.0f)
                angle += 2.0f * static_cast<float>(M_PI);

            Cell_Direction[x][y] = angle;

            // Magnitud inicial
            Cell_Mag[x][y] = 0.0f;
        }
    }

        std::cout << "Init finished!" << std::endl;


    return 1;
}

//------------------------------------------------------------------------
//------------------------Auxiliar Functions------------------------------
//------------------------------------------------------------------------

static inline float wrap_2pi(float a)
{
    const float two_pi = 2.0f * static_cast<float>(M_PI);
    a = std::fmod(a, two_pi);
    if (a < 0.0f) a += two_pi;
    return a;
}

// delta = a2 - a1 envuelto a (-pi, pi]
static inline float delta_angle(float a1, float a2)
{
  float diff;

  diff = a2 - a1;

  if (diff > M_PI) {
    diff -= 2*M_PI;
  } else if (diff < -M_PI) {
    diff += 2*M_PI;
  }

  return(diff);
}



static inline float normalizeAngle(float angle) {
    return std::atan2(std::sin(angle), std::cos(angle));
}


//---------------------------------------------------------------------
//-----------------------------Update VFH -----------------------------
//---------------------------------------------------------------------


int VFH_Algorithm::Update_VFH(const std::vector<double>& laser_ranges, double laser_resolution, float robot_linear_vel, float desired_angle, float desired_dist)
{

    laser_res = laser_resolution;
    linear_vel = robot_linear_vel;
    Desired_Angle = desired_angle;
    Desired_Dist = desired_dist;

    if (Build_Primary_Polar_Histogram(laser_ranges)==0)
    {
      std::cout << "Warning! Too close" << std::endl;
    }

    Build_Binary_Polar_Histogram();
    selectDirection();

    if(desired_dist < MAX_DIST)
    {
        max_speed = (desired_dist/MAX_DIST)*MAX_SPEED;
    }

    else if(desired_dist < MIN_DIST)    
    {
        max_speed = 0.0;
        std::cout << "Stopping" << std::endl;
    }

    else
    {
        max_speed = MAX_SPEED;
    }



    Chosen_Speed = std::min(last_chosen_speed + speed_incr, max_speed);

    last_chosen_speed = Chosen_Speed;

    return(1);
}


//----------------------------------------------------------------------
//-------------------PPH Primary Polar Histogram -----------------------
//---------------------------------------------------------------------


int VFH_Algorithm::Build_Primary_Polar_Histogram(
    const std::vector<double>& laser_ranges)
{
    std::fill(Hist_primary.begin(), Hist_primary.end(), 0.0f);

    const float r_eff = ROBOT_RADIUS;

    for(int x = 0; x < WINDOW_DIAMETER; ++x)
    {
        for(int y = 0; y < WINDOW_DIAMETER; ++y)
        {
            // ----------- CALCULAR OCUPACIÓN CELDA -----------
            
            // 
            float dx = (x - CENTER_X) * CELL_WIDTH;
            float dy = (y - CENTER_Y) * CELL_WIDTH;

            float dist = std::hypot(dx, dy);

            if(dist < 1e-3)
                continue;

            // Índice del láser correspondiente
            int idx = std::floor(Cell_Direction[x][y] / laser_res);

            idx = (idx % laser_ranges.size() + laser_ranges.size()) % laser_ranges.size();

            float laser_dist = laser_ranges[idx];

            float cell_limit = dist + CELL_WIDTH * 0.5f;

            if(cell_limit > laser_dist)
            {
                Cell_Mag[x][y] = Cell_Base_Mag[x][y];
            }
            else
            {
                Cell_Mag[x][y] = 0.0f;
            }

            if(Cell_Mag[x][y] == 0.0f)
                continue;

            // ----------- ENLARGE DINÁMICO -----------

            float enlarge = 0.0f;

            if(dist > r_eff)
            {
                float ratio = r_eff / dist;
                ratio = std::clamp(ratio, -1.0f, 1.0f);
                enlarge = std::asin(ratio);
            }
            else
            {
                enlarge = M_PI;  // demasiado cerca → bloquea todo
            }

            float angle = Cell_Direction[x][y];

            float a_min = angle - enlarge;
            float a_max = angle + enlarge;

            int s_min = std::floor(a_min / sector_angle);
            int s_max = std::floor(a_max / sector_angle);

            for(int s = s_min; s <= s_max; ++s)
            {
                int sector = (s % HIST_SIZE + HIST_SIZE) % HIST_SIZE;
                Hist_primary[sector] += Cell_Mag[x][y];
            }
        }
        
    }

    return 1;
}


//----------------------------------------------------------------------
//-------------------BPH Binary Polar Histogram -----------------------
//---------------------------------------------------------------------

int VFH_Algorithm::Build_Binary_Polar_Histogram()
{
    const float TH_HIGH = 0.6f;  // bloqueo
    const float TH_LOW  = 0.4f;  // liberación

    for(int i = 0; i < HIST_SIZE; ++i)
    {
        if(Hist_primary[i] > TH_HIGH)
        {
            Hist_binary[i] = 1.0f;
        }
        else if(Hist_primary[i] < TH_LOW)
        {
            Hist_binary[i] = 0.0f;
        }
        else
        {
            Hist_binary[i] = Last_Binary_Hist[i];
        }
    
    Last_Binary_Hist[i] = Hist_binary[i];
    //std::cout << Hist_binary[i] << std::endl;
    }
    return 1;
}


int VFH_Algorithm::Select_Candidate_Angle()
{
  unsigned int i;
  float weight, min_weight;

  if (Candidate_Angle.size() == 0)
  {
      Picked_Angle = Last_Picked_Angle;
      Last_Picked_Angle = Picked_Angle;
      return(1);
  }

  Picked_Angle = 0.0;
  min_weight = 10000000;

  for(i=0;i<Candidate_Angle.size();i++)
  {
     
      weight = U1 * fabs(delta_angle(Desired_Angle, Candidate_Angle[i])) +
          U2 * fabs(delta_angle(Last_Picked_Angle, Candidate_Angle[i]));
      if (weight < min_weight)
      {
          min_weight = weight;
          Picked_Angle = Candidate_Angle[i];
      }
  }

  Last_Picked_Angle = Picked_Angle;

  return(1);
}


int VFH_Algorithm::selectDirection()
{
    const float two_pi = 2.0f * static_cast<float>(M_PI);

    auto wrap_2pi = [&](float a) -> float {
        a = std::fmod(a, two_pi);
        if (a < 0.0f) a += two_pi;
        return a;
    };

    auto clampf = [&](float x, float lo, float hi) -> float {
        return std::max(lo, std::min(x, hi));
    };

    // ---- Normaliza Desired_Angle por seguridad (trabajamos en [0, 2pi))
    Desired_Angle = wrap_2pi(Desired_Angle);

    Candidate_Angle.clear();

    
    //--------------- Obtenemos los huecos ----------------------------
    //-----------------------------------------------------------------

    struct OpeningCont {
        float a_start; // continuo (puede ser negativo si cruza 0)
        float a_end;   // continuo, siempre > a_start
    };

    std::vector<std::pair<int,int>> zero_runs; // [start_idx, end_idx] inclusivos
    bool in_run = false;
    int run_start = 0;

    for (int i = 0; i < HIST_SIZE; ++i)
    {
        const int occ = Hist_binary[i]; // 0 libre, 1 ocupado
        if (!in_run && occ == 0) {
            in_run = true;
            run_start = i;
        }
        else if (in_run && occ == 1) {
            in_run = false;
            zero_runs.push_back({run_start, i-1});
        }
    }
    
    if (in_run) {
        zero_runs.push_back({run_start, HIST_SIZE-1});
    }


    // si todo el binario está libre-> Picked_Angle = Desired_Angle
    if (zero_runs.size() == 1 && zero_runs[0].first == 0 && zero_runs[0].second == HIST_SIZE-1)
    {
        Picked_Angle = Desired_Angle;
        Last_Picked_Angle = Picked_Angle;
        return 1;
    }

    // Fusionar run que cruza 0 (si empieza en 0 y termina en HIST_SIZE-1)
    // Ej: [0..a] y [b..H-1] => un solo hueco continuo con start negativo.
    std::vector<OpeningCont> openings;
    if (!zero_runs.empty())

    {
        // Si hay run al inicio y al final, fusión wrap-around
        //Comprobamos si hay 2 o más (ya que si solo hay uno en zero_runs, significa que todo está)
        if (zero_runs.size() >= 2 && zero_runs.front().first == 0 && zero_runs.back().second == HIST_SIZE-1)
        {
            auto first = zero_runs.front(); // [0..e0]
            auto last  = zero_runs.back();  // [s1..H-1]

            // start continuo negativo, end continuo positivo
            OpeningCont o;
            o.a_start = (static_cast<float>(last.first) * sector_angle) - two_pi;
            o.a_end   = (static_cast<float>(first.second) * sector_angle);
            openings.push_back(o);

            // mete las runs intermedias (si hay)
            for (size_t k = 1; k + 1 < zero_runs.size(); ++k)
            {
                OpeningCont oi;
                oi.a_start = static_cast<float>(zero_runs[k].first) * sector_angle;
                oi.a_end   = static_cast<float>(zero_runs[k].second) * sector_angle;
                openings.push_back(oi);
            }
        }
        else
        {
            // Sin wrap-around: cada run es un opening
            for (auto &zr : zero_runs)
            {
                OpeningCont o;
                o.a_start = static_cast<float>(zr.first) * sector_angle;
                o.a_end   = static_cast<float>(zr.second) * sector_angle;
                openings.push_back(o);
            }
        }
    }

    // Si no hay huecos, no hay candidato: mantén último y sal
    if (openings.empty())
    {
        Picked_Angle = Last_Picked_Angle;
        return 1;
    }

    // ============================================================
    // 2) Generar candidatos de manera estable (sin discontinuidades)
    //    - siempre centro del hueco
    //    - extras con offset progresivo (no umbral duro 80°)
    //    - añadir Desired_Angle si cae dentro del hueco
    // ============================================================
    const float min_opening = 2.0f * static_cast<float>(M_PI) / 180.0f;  // 10°
    const float max_offset  = 5.0f * static_cast<float>(M_PI) / 180.0f;  // 40°
    const float margin      = 1.0f  * static_cast<float>(M_PI) / 180.0f;  // 5° margen a borde

    for (const auto &op : openings)
    {
        const float span = op.a_end - op.a_start; // continuo
        if (span < min_opening) continue;

        // Centro
        float center = op.a_start + 0.5f * span;
        Candidate_Angle.push_back(wrap_2pi(center));

        // Offset progresivo: cuanto mayor el hueco, más sentido añadir laterales
        // offset = min(40°, 0.25*span) y además respeta margen
        float offset = std::min(max_offset, 0.25f * span);

        // Asegura que quedan laterales dentro del hueco con margen
        if (span > 2.0f * (offset + margin))
        {
            float left  = op.a_start + offset;
            float right = op.a_end   - offset;

            Candidate_Angle.push_back(wrap_2pi(left));
            Candidate_Angle.push_back(wrap_2pi(right));
        }

        // ¿Desired dentro del hueco?
        // Lleva Desired a la misma rama continua que op.a_start..op.a_end
        float d = Desired_Angle;              // [0, 2pi)
        if (d < op.a_start) d += two_pi;      // para openings con start negativo
        if (d >= op.a_start && d <= op.a_end)
        {
            Candidate_Angle.push_back(Desired_Angle);
        }
    }

    // Quita duplicados aproximados (candidatos muy cercanos)
    // (Opcional pero ayuda a estabilidad numérica)
    {
        auto ang_dist = [&](float a, float b) {
            return std::fabs(delta_angle(a, b));
        };

        std::vector<float> unique;
        const float eps = 2.0f * static_cast<float>(M_PI) / static_cast<float>(HIST_SIZE); // ~ 1 sector
        for (float a : Candidate_Angle)
        {
            bool ok = true;
            for (float u : unique)
            {
                if (ang_dist(a, u) < eps) { ok = false; break; }
            }
            if (ok) unique.push_back(a);
        }
        Candidate_Angle.swap(unique);
    }

    // ============================================================
    // 3) Selección por coste
    // ============================================================
    const float prev_picked = Last_Picked_Angle;
    Select_Candidate_Angle(); // deja Picked_Angle y Last_Picked_Angle (según tu implementación)

    // ============================================================
    // 4) Rate limit del ángulo final para evitar saltos radicales
    // ============================================================
    {
        const float max_step = 10.0f * static_cast<float>(M_PI) / 180.0f; // 10° por iteración (ajusta)
        float raw = Picked_Angle;

        float d = delta_angle(prev_picked, raw);         // (-pi, pi]
        d = clampf(d, -max_step, +max_step);

        float limited = wrap_2pi(prev_picked + d);

        Picked_Angle = limited;
        Last_Picked_Angle = Picked_Angle;
    }

    return 1;
}
