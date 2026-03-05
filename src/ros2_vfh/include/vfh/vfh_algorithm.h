#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>


class VFH_Algorithm
{
public:

    // Parámetros configurables
    float ROBOT_RADIUS;
    float CELL_WIDTH;
    int WINDOW_DIAMETER;
    int SECTORS_NUMBER;
    
    
    float MAX_SPEED=0.21;
    float MAX_DIST=1.5;
    float MIN_DIST=0.05;

    float sector_angle;
    
    int HIST_SIZE;

    int CENTER_X;
    int CENTER_Y;

    double laser_res;
    float linear_vel;

    float phi_left_f;
    float phi_right_f;
    float R;

    float U1 = 5.0;
    float U2 = 1.0;

    float blocked_radius;

    float Picked_Angle = 0.0;
    float Desired_Angle = 0.0;
    float Desired_Dist = 0.0;
    float Last_Picked_Angle = 0.0;

    float NARROW_OPENING_THRESHOLD = 10.0f * M_PI / 180.0f;
    float WIDE_OPENING_THRESHOLD   = 50.0f * M_PI / 180.0f;


    float Chosen_Speed;
    float last_chosen_speed;
    float speed_incr = 0.05;
    float max_speed;

    // Grid
    std::vector<std::vector<float>> Cell_Direction;
    std::vector<std::vector<float>> Cell_Base_Mag;
    std::vector<std::vector<float>> Cell_Mag;

    // Histogramas
    std::vector<float> Hist_primary;
    std::vector<float> Last_Binary_Hist;
    std::vector<float> Hist_binary;
    std::vector<float> Hist_masked;

    // Dynamics
    std::vector<float> Candidate_Angle;

    // Constructor
    VFH_Algorithm(float robot_radius,
                  float cell_size,
                  int window_diameter,
                  int sectors_number
                  );

    int Init();

    int Update_VFH(const std::vector<double>& laser_ranges, double laser_resolution, float robot_linear_vel, float desired_angle, float desired_dist);
    int Build_Primary_Polar_Histogram(const std::vector<double>& laser_ranges);
    int Build_Binary_Polar_Histogram();
    int Build_Masked_Polar_Histogram(float linear_vel);
    int selectDirection();
    int Select_Candidate_Angle();


};
