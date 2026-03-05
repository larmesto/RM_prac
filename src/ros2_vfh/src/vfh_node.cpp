
#include <functional> 
#include <memory> 
#include <string> 
#include <math.h> 
#include <array>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp> 
#include "geometry_msgs/msg/twist.hpp"
#include "tf2_ros/transform_listener.h" 
#include "tf2_ros/buffer.h" 
#include "tf2/exceptions.h"
#include <tf2/LinearMath/Quaternion.h>

#include <cmath>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/float64.hpp>
#include "vfh/vfh_node.h"

#include "visualization_msgs/msg/marker.hpp"
#include <visualization_msgs/msg/marker_array.hpp>

#include <geometry_msgs/msg/point.hpp>


VFH_node::VFH_node()
: Node("vfh_node")
{

    m_robot_radius   = this->declare_parameter("m_robot_radius",0.18);
    m_cell_size      = this->declare_parameter("m_cell_size",0.05);   
    m_window_diameter= this->declare_parameter("m_window_diameter",60);
    m_sectors_number   = this->declare_parameter("sectors_number",72);

    

    m_vfh = std::make_unique<VFH_Algorithm>(
        m_robot_radius,    
        m_cell_size,
        m_window_diameter,
		m_sectors_number
    );
	
	sector_angle = 2.0 * M_PI / m_sectors_number;
	
    RCLCPP_INFO(this->get_logger(),"Starting VFH");

	rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
	auto scan_qos = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort();

	tf_buffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());
	tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer);
	
	//-------------- Suscriptors ---------------------

	laser_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", scan_qos, std::bind(&VFH_node::scanCallback, this, std::placeholders::_1));
			
	odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odom", qos_profile, std::bind(&VFH_node::odomCallback, this, std::placeholders::_1));

	goalPose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/goal_pose", qos_profile, std::bind(&VFH_node::goalPose_callback, this, std::placeholders::_1));
	

	//-------------- Publishers -----------------------

	cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10);
		
	goal_line_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("goal_line_marker", 10);

	vfh_markers_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("vfh_visualization", 10);

}


VFH_node::~VFH_node(){}


void VFH_node::goalPose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr goal_pose_msg)
{
	RCLCPP_INFO(this->get_logger(),"Got goal pose.");
 	goal_position = goal_pose_msg->pose.position;
	doTransform();
	RCLCPP_INFO(this->get_logger(),"Desired Distance: %.3f; Desired Angle: %.3f", desired_dist, desired_angle);

	goal_flag = true;
}


void VFH_node::doTransform()
{
  std::string target_frame = "odom";
  std::string source_frame = "base_footprint";
  geometry_msgs::msg::TransformStamped transform;
  rclcpp::Time now = this->get_clock()->now();
  try
  {
    transform = tf_buffer->lookupTransform(source_frame, target_frame, rclcpp::Time(0));
    tf2::doTransform(goal_position, p_out, transform);
	desired_dist = sqrt(pow(p_out.x,2)+pow(p_out.y,2));
 	desired_angle = atan2(p_out.y,p_out.x);
	if (desired_angle < 0)
	{
    	desired_angle = desired_angle + 2*M_PI;
	}

	if (desired_angle > 2*M_PI)
	{
		desired_angle = desired_angle - 2*M_PI;
	}
	

  }
  catch (const tf2::TransformException & ex)
  {
    RCLCPP_WARN(this->get_logger(),"We could not obtain the transform");
  }
}


void VFH_node::odomCallback (const nav_msgs::msg::Odometry::SharedPtr odom_msg)
{
	doTransform();
	robot_linear_vel = odom_msg->twist.twist.linear.x;
	robot_angular_vel = odom_msg->twist.twist.angular.z;	
}

void VFH_node::scanCallback (const sensor_msgs::msg::LaserScan::SharedPtr scan_msg)
{	
	int n = scan_msg->ranges.size();

	m_laser_ranges.resize(n);

	laser_resolution = scan_msg->angle_increment;

	m_laser_ranges.assign(n, std::numeric_limits<double>::infinity());

	for (int i = 0; i < n; ++i)
	{
	    double r = scan_msg->ranges[i];

	    if (!std::isfinite(r) || r < scan_msg->range_min || r > scan_msg->range_max)
	    {
	        continue;
	    }
	    m_laser_ranges[i] = r;
	}

	update();
}


//-----------------------------------

void VFH_node::update()
{
	m_vfh->Update_VFH(m_laser_ranges,laser_resolution, robot_linear_vel, desired_angle, desired_dist);
	
	publishVFHVisualization();

	if (m_vfh->selectDirection() && goal_flag)
	{
		publishCommand(m_vfh->Picked_Angle,m_vfh->Chosen_Speed);
	}

	publishGoalPosition();
}



void VFH_node::publishVFHVisualization()
{
	visualization_msgs::msg::MarkerArray array;
	int id = 0;
	auto stamp = rclcpp::Time(0);

    // Opcional: borrar todo antes
    visualization_msgs::msg::Marker clear;
    clear.action = visualization_msgs::msg::Marker::DELETEALL;
    array.markers.push_back(clear);

    // Añadir cada bloque
    addReferenceCircle(array, stamp, id);
    addReferenceSectors(array, stamp, id);
    addPrimaryHistogram(array, stamp, id);
    addBinaryHistogram(array, stamp, id);
    addCandidateDirections(array, stamp, id);
    addPickedDirection(array, stamp, id);

    vfh_markers_pub_->publish(array);
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

static inline float wrap_pi(float a)
{
  while (a >  M_PI) a -= 2.0f * M_PI;
  while (a <= -M_PI) a += 2.0f * M_PI;
  return a;
}

void VFH_node::publishCommand(float picked_angle, float chosen_speed)
{
    geometry_msgs::msg::Twist cmd;

    // 1) normaliza error angular
    const float e = wrap_pi(picked_angle);

    // 2) parámetros (ajustables)
    const float deadband     = 0.03f;  // rad ~ 1.7°
    const float align_thresh = 0.35f;  // rad ~ 20° (por encima, gira en el sitio)
    const float k_omega_go   = 3.0f;   // ganancia cuando avanza
    const float k_omega_align= 5.0f;   // ganancia cuando alinea
    const float max_omega    = 2.0f;   // rad/s
    const float min_v        = 0.05f;  // m/s (opcional)
    const float max_v        = chosen_speed;
	const float min_dist	 = 0.05;

    // 3) deadband (evita micro-oscilación)
    float e_db = (std::fabs(e) < deadband) ? 0.0f : e;

    // 4) modo align: si el error es grande, NO avances (evitas espirales y giro errático)
    if (std::fabs(e_db) > align_thresh)
    {
        cmd.linear.x  = 0.0;
        float omega = k_omega_align * e_db;
        omega = std::clamp(omega, -max_omega, max_omega);
        cmd.angular.z = omega;
    }

	if ((std::fabs(e_db) > align_thresh) && (desired_dist < min_dist))
	{
		cmd.linear.x = 0.0;
		cmd.angular.z = 0.0;
	}

    else
    {
        // modo go: avanza, pero reduce v con el error angular (respuesta más rápida)
        float v = max_v * std::cos(e_db);          // 1 en e=0, baja al crecer |e|
        v = std::clamp(v, 0.0f, max_v);
        if (v > 0.0f) v = std::max(v, min_v);      // opcional
	
        float omega = k_omega_go * e_db;
        omega = std::clamp(omega, -max_omega, max_omega);
	
        cmd.linear.x  = v;
        cmd.angular.z = omega;
    }

    cmd_vel_pub_->publish(cmd);
}


	//--------------------------------------------------------------
	//------------------- Circle Max Radius ------------------------
	//--------------------------------------------------------------

	void VFH_node::addReferenceCircle(visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id)
	{
	    visualization_msgs::msg::Marker circle;

	    circle.header.frame_id = "base_footprint";
	    circle.header.stamp = stamp;

	    circle.ns = "vfh_reference_circle";
	    circle.id = id++;

	    circle.type = visualization_msgs::msg::Marker::LINE_STRIP;
	    circle.action = visualization_msgs::msg::Marker::ADD;

	    circle.pose.orientation.w = 1.0;

	    circle.scale.x = 0.02;  // grosor de línea

	    // Color: gris claro
	    circle.color.r = 0.8f;
	    circle.color.g = 0.8f;
	    circle.color.b = 0.8f;
	    circle.color.a = 1.0f;

	    // Radio máximo del VFH (en metros)
	    const double R_max =
	        (m_window_diameter / 2.0) *
	        m_cell_size;

		const int N = m_sectors_number; //segmentos del círculo

	    for (int i = 0; i <= N; ++i)
	    {
	        double theta = i * sector_angle;

	        geometry_msgs::msg::Point p;
	        p.x = R_max * std::cos(theta);
	        p.y = R_max * std::sin(theta);
	        p.z = 0.0;

	        circle.points.push_back(p);
	    }

		array.markers.push_back(circle);
	}

	//--------------------------------------------------------------
	//------------------- Sectors ----------------------------------
	//--------------------------------------------------------------

	void VFH_node::addReferenceSectors(visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id)
	{
	    visualization_msgs::msg::Marker sectors;

	    sectors.header.frame_id = "base_footprint";
	    sectors.header.stamp = stamp;

	    sectors.ns = "vfh_reference_sectors";
	    sectors.id = id++;

	    sectors.type = visualization_msgs::msg::Marker::LINE_LIST;
	    sectors.action = visualization_msgs::msg::Marker::ADD;

	    sectors.pose.orientation.w = 1.0;

	    sectors.scale.x = 0.01;  // grosor de línea

	    // Color: verde
	    sectors.color.r = 0.0f;
	    sectors.color.g = 1.0f;
	    sectors.color.b = 0.0f;
	    sectors.color.a = 0.6f;

	    const double R_max = (m_window_diameter / 2.0) * m_cell_size;


	    for (int i = 0; i < m_sectors_number; ++i)
	    {
	        double theta = i * sector_angle;

	        geometry_msgs::msg::Point p0, p1;

	        // Origen (robot)
	        p0.x = 0.0;
	        p0.y = 0.0;
	        p0.z = 0.0;

	        // Borde del círculo
	        p1.x = R_max * std::cos(theta);
	        p1.y = R_max * std::sin(theta);
	        p1.z = 0.0;

	        sectors.points.push_back(p0);
	        sectors.points.push_back(p1);
	    }

		array.markers.push_back(sectors);
	}


	//--------------------------------------------------------------
	//------------------- PPH Primary Polar Histogram --------------
	//--------------------------------------------------------------

	void VFH_node::addPrimaryHistogram(visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id)
	{

	    visualization_msgs::msg::Marker marker;

	    marker.header.frame_id = "base_footprint";
	    marker.header.stamp = stamp;

	    marker.ns = "vfh_primary_histogram";
	    marker.id = id++;

	    marker.type = visualization_msgs::msg::Marker::TRIANGLE_LIST;
	    marker.action = visualization_msgs::msg::Marker::ADD;

	    marker.pose.orientation.w = 1.0;

		// Cuidado con la escala del marker. Si dejamos a cero algun componente se quejará RViz2
	    marker.scale.x = 1.0;   // tamaño del punto
	    marker.scale.y = 1.0;
		marker.scale.z = 1.0;

	    marker.color.r = 0.0f;
	    marker.color.g = 0.0f;
	    marker.color.b = 1.0f;
	    marker.color.a = 1.0f;

		hist_size = m_sectors_number;

	    // Radio máximo del VFH
	    const double R_max =
	        (m_window_diameter / 2.0) *  m_cell_size; //

	    // Normalización
	    double max_val = 0.0;
	    for (int i = 0; i < hist_size; ++i)
	        max_val = std::max(max_val, static_cast<double>(m_vfh->Hist_primary[i]));

	    if (max_val < 1e-6){
			max_val = 1.0;
		}
	

		geometry_msgs::msg::Point center;
		center.x = 0.0;
		center.y = 0.0;
		center.z = 0.0;


	    for (int i = 0; i < hist_size; ++i)
	    {	
			// Lo escalamos
			double r =
	            (m_vfh->Hist_primary[i] / max_val) * R_max;

	        double theta_center = (i + 0.5) * sector_angle;
			double half_angle   = sector_angle / 2.0;

			geometry_msgs::msg::Point p_left, p_right;



			p_left.x  = r * cos(theta_center - half_angle);
			p_left.y  = r * sin(theta_center - half_angle);
			p_left.z  = 0.0;

			p_right.x = r * cos(theta_center + half_angle);
			p_right.y = r * sin(theta_center + half_angle);
			p_right.z = 0.0;

			marker.points.push_back(center);
			marker.points.push_back(p_left);
			marker.points.push_back(p_right);
	    }

		array.markers.push_back(marker);
	}

	//--------------------------------------------------------------
	//------------------- BPH Binary Polar Histogram --------------
	//--------------------------------------------------------------

	void VFH_node::addBinaryHistogram(visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id)
	{
	    visualization_msgs::msg::Marker marker;

	    // -------------------------------------------------
	
	    marker.header.frame_id = "base_footprint";
	    marker.header.stamp = stamp;

	    marker.ns = "vfh_binary_histogram";
	    marker.id = id++;

	    marker.type = visualization_msgs::msg::Marker::LINE_LIST;
	    marker.action = visualization_msgs::msg::Marker::ADD;

	    marker.pose.orientation.w = 1.0;

	    // -------------------------------------------------
	
	    marker.scale.x = 0.15;   // grosor del arco en metros
	    marker.scale.y = 1.0;
	    marker.scale.z = 1.0;

	    // -------------------------------------------------

		hist_size = m_sectors_number;

		const double EPS = 0.02 * sector_angle; // 2 % del sector

	    // Radio máximo coherente con el grid VFH
	    const double R_max =
	        (m_window_diameter / 2.0) * m_cell_size;   // mm → m

	    const int ARC_STEPS = 6;     // suavidad del arco

	    // -------------------------------------------------
	    for (int i = 0; i < hist_size; ++i)
	    {
	        // Color según estado binario
	        std_msgs::msg::ColorRGBA color;
	        if (m_vfh->Hist_binary[i] > 0.5) {
	            // Sector bloqueado rojo
	            color.r = 1.0f;
	            color.g = 0.0f;
	            color.b = 0.0f;
	            color.a = 1.0f;
	        } else {
	            // Sector libre verde
	            color.r = 0.0f;
	            color.g = 1.0f;
	            color.b = 0.0f;
	            color.a = 1.0f;
	        }

	        // Límites del sector en ángulo
	        const double theta_start = i * sector_angle + EPS;
	        const double theta_end   = (i + 1) * sector_angle - EPS;


	        // división en pequeños segmentos
	        for (int k = 0; k < ARC_STEPS; ++k)
	        {
	            const double t0 = static_cast<double>(k) / ARC_STEPS;
	            const double t1 = static_cast<double>(k + 1) / ARC_STEPS;

	            const double a0 = theta_start + t0 * (theta_end - theta_start);
	            const double a1 = theta_start + t1 * (theta_end - theta_start);

	            geometry_msgs::msg::Point p0, p1;

	            p0.x = R_max * std::cos(a0);
	            p0.y = R_max * std::sin(a0);
	            p0.z = 0.05;

	            p1.x = R_max * std::cos(a1);
	            p1.y = R_max * std::sin(a1);
	            p1.z = 0.05;

	            marker.points.push_back(p0);
	            marker.points.push_back(p1);

	            marker.colors.push_back(color);
	            marker.colors.push_back(color);
	        }
	    }

		array.markers.push_back(marker);
	}
	

	void VFH_node::addCandidateDirections(visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id)
	{
		for (size_t i = 0; i < m_vfh->Candidate_Angle.size(); ++i)
		{
		    visualization_msgs::msg::Marker marker;

		    marker.header.frame_id = "base_footprint";
		    marker.header.stamp = stamp;
		    marker.ns = "vfh_candidates";
		    marker.id = id++;
		    marker.type = visualization_msgs::msg::Marker::ARROW;
		    marker.action = visualization_msgs::msg::Marker::ADD;

		    marker.pose.position.x = 0.0;
		    marker.pose.position.y = 0.0;
		    marker.pose.position.z = 0.0;

		    tf2::Quaternion q;
		    q.setRPY(0.0, 0.0, m_vfh->Candidate_Angle[i]);
		    marker.pose.orientation = tf2::toMsg(q);

		    marker.scale.x = 1.0;
		    marker.scale.y = 0.05;
		    marker.scale.z = 0.05;

		    marker.color.r = 0.0;
		    marker.color.g = 1.0;
		    marker.color.b = 0.0;
		    marker.color.a = 0.8;

		    marker.lifetime = rclcpp::Duration(0, 0);  // ← infinito

			array.markers.push_back(marker);
		}
	}

	//--------------------------------------------------
	//--------------- Picked Direction -----------------
	//--------------------------------------------------

	void VFH_node::addPickedDirection(visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id)
{
    visualization_msgs::msg::Marker marker;

    marker.header.frame_id = "base_footprint";
    marker.header.stamp = stamp;

    marker.ns = "vfh_picked";
    marker.id = id++;
    marker.type = visualization_msgs::msg::Marker::ARROW;
    marker.action = visualization_msgs::msg::Marker::ADD;

    // Posición base
    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0.0;

    // Orientación (rotación Z)
    tf2::Quaternion q;
    q.setRPY(0.0, 0.0, m_vfh->Picked_Angle);
    marker.pose.orientation = tf2::toMsg(q);

    // Escala (ligeramente más grande que las verdes)
    marker.scale.x = 1.2;   // longitud
    marker.scale.y = 0.08;
    marker.scale.z = 0.08;

    // Color rojo intenso
    marker.color.r = 1.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0f;

	array.markers.push_back(marker);
}

//------------------------------------------------
//-------------- Goal Position -------------------
//------------------------------------------------

void VFH_node::publishGoalPosition()
{
	visualization_msgs::msg::Marker line_marker;
	line_marker.header.frame_id = "base_footprint";  // La línea está en este frame
	line_marker.header.stamp = this->get_clock()->now();
	line_marker.ns = "goal_line";
	line_marker.id = 0;
	line_marker.type = visualization_msgs::msg::Marker::LINE_STRIP;
	line_marker.action = visualization_msgs::msg::Marker::ADD;
	line_marker.scale.x = 0.02;  // Grosor de la línea

	// Color: verde translúcido
	line_marker.color.r = 0.0;
	line_marker.color.g = 1.0;
	line_marker.color.b = 0.0;
	line_marker.color.a = 1.0;

	// Punto 1: origen (base_footprint)
	geometry_msgs::msg::Point start;
	start.x = 0.0;
	start.y = 0.0;
	start.z = 0.0;

	// Punto 2: goal transformado en base_footprint
	geometry_msgs::msg::Point end = p_out;
	end.z = 0.0;  // mantener en el plano

	line_marker.points.push_back(start);
	line_marker.points.push_back(end);

	goal_line_pub_->publish(line_marker);	
}


int main(int argc, char** argv)
{
	rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VFH_node>());
    rclcpp::shutdown();
    return 0;
}
