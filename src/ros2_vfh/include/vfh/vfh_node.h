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

#include <functional> 
#include <memory> 
#include <string> 
#include <math.h> 
#include <array>
#include <numbers>
#include <algorithm>

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

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp> 
#include "geometry_msgs/msg/twist.hpp"
#include "tf2_ros/transform_listener.h" 
#include "tf2_ros/buffer.h" 
#include "tf2/exceptions.h"

#include "visualization_msgs/msg/marker.hpp"
#include <visualization_msgs/msg/marker_array.hpp>

#include <geometry_msgs/msg/point.hpp>

#define DEG2RAD(a) ((a) * M_PI / 180.0)

std::string scan_topic_  = "base_scan";
std::string odom_topic_  = "odom";

class VFH_node: public rclcpp::Node
{
public:
	VFH_node();
	~VFH_node();
	void update();

	double m_cell_size;			
	int m_window_diameter;			
	double m_robot_radius;
	int m_sectors_number;
	int hist_size;

	float sector_angle;

	std::unique_ptr<VFH_Algorithm> m_vfh;
    
	double laser_resolution = 0.0;
	float l=0.08;

	std::vector<double> m_laser_ranges;

	float robot_linear_vel;
	float robot_angular_vel;

	double safety_radio_mark = 0;

	geometry_msgs::msg::Point goal_position;
	geometry_msgs::msg::Point p_out;

	float desired_dist=0.0;
 	float desired_angle=0.0;
	bool goal_flag = false;

	int chosen_speed,chosen_turnrate;

	size_t last_marker_count_ = 0;

	// ros
	rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub_;
	rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
	rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goalPose_sub_;
	rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_; 
	
	// Visualización Markers

	rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr goal_line_pub_;
	rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr vfh_markers_pub_;


	std::unique_ptr<tf2_ros::Buffer> tf_buffer; 
  	std::shared_ptr<tf2_ros::TransformListener> tf_listener;
	
    void scanCallback (const sensor_msgs::msg::LaserScan::SharedPtr scan_msg);
    void odomCallback (const nav_msgs::msg::Odometry::SharedPtr odom_msg);
	void goalPose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr goal_pose_msg);
	void doTransform();
	void publishCommand(float picked_angle, float chosen_speed);

	// Visualización
		
	void publishVFHVisualization();

	void addReferenceCircle (visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id);
    void addReferenceSectors (visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id);
    void addPrimaryHistogram (visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id);
    void addBinaryHistogram (visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id);
    void addCandidateDirections (visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id);
    void addPickedDirection (visualization_msgs::msg::MarkerArray& array, const rclcpp::Time& stamp, int& id);	

	void publishGoalPosition();

};

#endif /* VFH_NODE_H_ */
