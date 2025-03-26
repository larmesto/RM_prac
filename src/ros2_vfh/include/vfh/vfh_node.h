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

#ifndef VFH_NODE_H_
#define VFH_NODE_H_

#include <rclcpp/rclcpp.hpp>
#include "vfh/vfh_algorithm.h"
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/pose2_d.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
//#include <tf/transform_datatypes.h>
//#include "tf2_ros/transform_listener.h" 
//#include "tf2_ros/transform_broadcaster.h" 

#define DEG2RAD(a) ((a) * M_PI / 180.0)

std::string scan_topic_  = "base_scan";
std::string odom_topic_  = "odom";

class VFH_node: public rclcpp::Node
{
public:
	VFH_node();
	~VFH_node();
	void update();
private:
	VFH_Algorithm *m_vfh;

	double m_cell_size;			// 100 mm
	int m_window_diameter;		// cells
	int m_sector_angle;			// in deg
	double m_safety_dist_0ms;
	double m_safety_dist_1ms;
	int m_max_speed;
	int m_max_speed_narrow_opening;
	int m_max_speed_wide_opening;
	int m_max_acceleration;
	int m_min_turnrate;
	int m_max_turnrate_0ms;
	int m_max_turnrate_1ms;
	double m_min_turn_radius_safety_factor;
	double m_free_space_cutoff_0ms;
	double m_obs_cutoff_0ms;
	double m_free_space_cutoff_1ms;
	double m_obs_cutoff_1ms;
	double m_weight_desired_dir;
	double m_weight_current_dir;

	double m_robot_radius;
	double m_robotVel;
    double m_laser_ranges[360];

	int chosen_speed,chosen_turnrate;

	// ros
	rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub_;
	rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
	rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub; 
	rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr selected_direction_pub;
	rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr candidate_directions_pub;
	
    void scanCallback (const sensor_msgs::msg::LaserScan::SharedPtr scan_msg);
    void odomCallback (const nav_msgs::msg::Odometry::SharedPtr odom_msg);
};

#endif /* VFH_NODE_H_ */
