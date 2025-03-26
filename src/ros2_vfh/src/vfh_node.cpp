/*
 * Copyright (c) 2012, Stefano Rosa, Luca Carlone
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
//#include "laser_geometry/msg/laser_geometry.hpp"
//#include <tf2_ros/transform_listener.h>
//#include <tf2_ros/buffer.h>
//#include "geometry_msgs/msg/transform_stamped.hpp"
//#include <tf2_sensor_msgs/tf2_sensor_msgs.hpp>
#include <cmath>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/float64.hpp>
#include "vfh/vfh_node.h"


VFH_node::VFH_node(): Node("vfh_node")
{
	RCLCPP_INFO(this->get_logger(),"Starting VFH");

	m_cell_size = 100;							// mm, cell dimension
	m_window_diameter = 60;						// number of cells
	m_sector_angle = 5;							// deg, sector angle

	
	this->m_safety_dist_0ms=this->declare_parameter("m_safety_dist_0ms",20.0);  // mm, double, safe distance at 0 m/s
	
	this->m_safety_dist_1ms=this->declare_parameter("m_safety_dist_1ms",20.0);  // mm, double, safe distance at 1 m/s
	
	this->m_max_speed=this->declare_parameter("m_max_speed",20.0);  // mm/sec, int, max speed

	this->m_max_speed_narrow_opening=this->declare_parameter("m_max_speed_narrow_opening",10);  // mm/sec, int, max speed in the narrow opening
	
	this->m_max_speed_wide_opening=this->declare_parameter("m_max_speed_wide_opening",20); // mm/sec, int, max speed in the wide opening

	this->m_max_acceleration=this->declare_parameter("m_max_acceleration",100);  // mm/sec^2, int, max acceleration
	
	//this->m_min_turnrate=this->declare_parameter("m_min_turnrate",40);  // deg/sec, int, min turn rate <--- not used
	
	this->m_max_turnrate_0ms=this->declare_parameter("m_max_turnrate_0ms",20);  // deg/sec, int, max turn rate at 0 m/s
	
	this->m_max_turnrate_1ms=this->declare_parameter("m_max_turnrate_1ms",20); // deg/sec, int, max turn rate at 1 m/s
	
	this->m_min_turn_radius_safety_factor = 1.0; 		// double ????

	this->m_free_space_cutoff_0ms=this->declare_parameter("m_free_space_cutoff_0ms",3000000.0); //double, low threshold free space at 0 m/s
	
	this->m_obs_cutoff_0ms=this->declare_parameter("m_obs_cutoff_0ms",7000000.0); //double, high threshold obstacle at 0 m/s

	this->m_free_space_cutoff_1ms=this->declare_parameter("m_free_space_cutoff_1ms",3000000.0); //double, low threshold free space at 1 m/s

	this->m_obs_cutoff_1ms=this->declare_parameter("m_obs_cutoff_1ms",7000000.0); //double, high threshold obstacle at 1 m/s
	
	this->m_weight_desired_dir=this->declare_parameter("m_weight_desired_dir",3.0); //double, weight desired direction
	
	this->m_weight_current_dir=this->declare_parameter("m_weight_current_dir",1.0); //double, weight current direction
	
	this->m_robot_radius=this->declare_parameter("m_robot_radius",80.0); // robot radius in mm

	m_vfh = new VFH_Algorithm(m_cell_size, m_window_diameter, m_sector_angle,
			m_safety_dist_0ms, m_safety_dist_1ms, m_max_speed,
			m_max_speed_narrow_opening, m_max_speed_wide_opening,
			m_max_acceleration, m_min_turnrate, m_max_turnrate_0ms,
			m_max_turnrate_1ms, m_min_turn_radius_safety_factor,
			m_free_space_cutoff_0ms, m_obs_cutoff_0ms, m_free_space_cutoff_1ms,
			m_obs_cutoff_1ms, m_weight_desired_dir, m_weight_current_dir);

	m_vfh->SetRobotRadius(m_robot_radius);
	m_vfh->Init();
	
	rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
	
	laser_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", qos_profile, std::bind(&VFH_node::scanCallback, this, std::placeholders::_1));
			
	odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odom", qos_profile, std::bind(&VFH_node::odomCallback, this, std::placeholders::_1));
	cmd_vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10); 
	selected_direction_pub = this->create_publisher<std_msgs::msg::Float32>("selected_direction",10);
	candidate_directions_pub = this->create_publisher<std_msgs::msg::Float64>("masked_histogram",10);

}

VFH_node::~VFH_node()
{
	// stop the robot
	geometry_msgs::msg::Twist cmd_vel;
	cmd_vel.linear.x=0.0;
	cmd_vel.angular.z=0.0;
	cmd_vel_pub->publish(cmd_vel);
	delete m_vfh;
}

void VFH_node::odomCallback (const nav_msgs::msg::Odometry::SharedPtr odom_msg)
{
	m_robotVel = odom_msg->twist.twist.linear.x * 1000.0;
	//std::cout << "m_robotVel: " << m_robotVel << std::endl;
}


void VFH_node::scanCallback (const sensor_msgs::msg::LaserScan::SharedPtr scan_msg)
{
	int n = scan_msg->ranges.size();
	//m_laser_ranges is a vector of 0.5 degrees resolution with 180º angle span
	for (int i = 0; i < 360; i++)
		m_laser_ranges[i] = -1;
	
	for (unsigned i = 0; i<180; i++)
	{
		int idx=(int)(((double)i*(M_PI/180.0)-M_PI/2+0.5-scan_msg->angle_min)/scan_msg->angle_increment);
		if (idx<0)
			idx=n+idx;
		else if (idx>n)
			idx=idx-n;
		//std::cout << idx << " ";
		if (!std::isnan(scan_msg->ranges[idx]))
		{
			double r = scan_msg->ranges[idx]*1000.0;
			m_laser_ranges[i*2] = r;
			m_laser_ranges[i*2 + 1] = r;
		}
	}	
	/*std::cout << "m_laser_ranges: " << std::endl;
	for (unsigned i=0;i<360;i++)
		std::cout << m_laser_ranges[i] << " " << std::endl;
	std::cout << std::endl;*/

	// perform vfh+
	update();
}


void VFH_node::update()
{
	float desiredAngle=0.0;
	float desiredDist=100000.0;
	float currGoalDistanceTolerance=250;

	m_vfh->Update_VFH(m_laser_ranges, (int) (m_robotVel), desiredAngle + 90.0,
			desiredDist, currGoalDistanceTolerance, chosen_speed,
			chosen_turnrate);

	geometry_msgs::msg::Twist cmd_vel;
	cmd_vel.linear.x=(float)(chosen_speed)/1000.0;
	cmd_vel.angular.z= DEG2RAD(chosen_turnrate);
	cmd_vel_pub->publish(cmd_vel);
	
	rclcpp::Time now = this->get_clock()->now();
	std_msgs::msg::Float32 selected_direction_msg;
	selected_direction_msg.data=m_vfh->GetPickedAngle();
	selected_direction_pub->publish(selected_direction_msg);
	
	//Pack histogram data into a 64-bit number
	int hist_size=m_vfh->GetHistSize();
	//int sector_angle=m_vfh->GetSectorAngle();
	uint64_t data=0;
	//std::cout << "Hist size: " << hist_size << std::endl;
	for (int i=0;i<hist_size/2;i++)
	{
		data |= (static_cast<uint64_t>(m_vfh->Hist[i]>0.5) << i);
	}
	//std::cout << "Data: " << data << std::endl;
	std_msgs::msg::Float64 candidate_directions_msg;
	candidate_directions_msg.data=data;
	candidate_directions_pub->publish(candidate_directions_msg);

	//ROS_DEBUG("chosen_speed %d, chosen_turnrate %d", chosen_speed,chosen_turnrate);

}

int main(int argc, char** argv)
{
	rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VFH_node>());
    rclcpp::shutdown();
    return 0;
}
