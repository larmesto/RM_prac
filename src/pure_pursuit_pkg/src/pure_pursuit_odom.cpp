#include <chrono>   //milliseconds
#include <functional> // std::bind
#include <memory>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

#include <csignal> //interruptions

#include "pure_pursuit_pkg/WayPointPathTools.hpp"

#include <rclcpp/rclcpp.hpp>
    #include <rclcpp/qos.hpp>

#include <nav_msgs/msg/odometry.hpp>

#include "std_msgs/msg/header.hpp"

#include "builtin_interfaces/msg/time.hpp"

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "pure_pursuit_pkg/msg/way_point_path.hpp"

#include "visualization_msgs/msg/marker.hpp"



class PurePursuitOdom : public rclcpp::Node	
{

public: PurePursuitOdom() : Node("pure_pursuit")
{
	rclcpp::QoS qos_profile(10);
        qos_profile.reliability(RMW_QOS_POLICY_RELIABILITY_RELIABLE); 
        qos_profile.durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);

    std::chrono::milliseconds period_control = std::chrono::milliseconds(50);
    timer_controller = this->create_wall_timer(period_control,std::bind(&PurePursuitOdom::controller,this));

    odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom",10,std::bind(&PurePursuitOdom::odom_callback,this,std::placeholders::_1));
		
	isPathReceived=false;

    waypoint_subs = this->create_subscription<pure_pursuit_pkg::msg::WayPointPath>(
        "waypoints",qos_profile,std::bind(&PurePursuitOdom::waypoint_callback, this, std::placeholders::_1));

    cmd_vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10);

	marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("marker_path_controller",qos_profile);

}

void stop_to_cmd_vel(){

    geometry_msgs::msg::Twist stop_msg;
    stop_msg.linear.x = 0.0;
    stop_msg.angular.z = 0.0;
  
    cmd_vel_pub->publish(stop_msg);

    RCLCPP_INFO(this->get_logger(),"Stop command sent");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

private:

    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr odom_msg){
        if (!initialized_odom){

        	x_rob_0 = odom_msg->pose.pose.position.x;
        	y_rob_0 = odom_msg->pose.pose.position.y;

        	tf2::Quaternion q( 
        	    odom_msg->pose.pose.orientation.x,
        	    odom_msg->pose.pose.orientation.y,
        	    odom_msg->pose.pose.orientation.z,
        	    odom_msg->pose.pose.orientation.w);

        	double roll, pitch, yaw;
        	tf2::Matrix3x3 m(q);
        	m.getRPY(roll,pitch,yaw);

        	theta_rob_0 = yaw;
			initialized_odom = true;
		}
		x_rob = odom_msg->pose.pose.position.x;
        y_rob = odom_msg->pose.pose.position.y;

        tf2::Quaternion q( 
            odom_msg->pose.pose.orientation.x,
            odom_msg->pose.pose.orientation.y,
            odom_msg->pose.pose.orientation.z,
            odom_msg->pose.pose.orientation.w);

        double roll, pitch, yaw;
        tf2::Matrix3x3 m(q);
        m.getRPY(roll,pitch,yaw);
		
        theta_rob = yaw;
    }

    void waypoint_callback(const pure_pursuit_pkg::msg::WayPointPath::SharedPtr waypoint_path_msg){
		if (initialized_odom)
		{
		path.points.clear();
		for (unsigned int i=0;i<waypoint_path_msg->points.size();i++)
		{
			geometry_msgs::msg::Point p;
			p.x=cos(theta_rob_0)*waypoint_path_msg->points[i].x-sin(theta_rob_0)*waypoint_path_msg->points[i].y+x_rob_0;
			p.y=sin(theta_rob_0)*waypoint_path_msg->points[i].x+cos(theta_rob_0)*waypoint_path_msg->points[i].y+y_rob_0;
			path.points.push_back(p);
		}
		path.closed_path.data = waypoint_path_msg->closed_path.data;
		isPathReceived=true;
		path_marker(path);

		}
    }

	void path_marker(pure_pursuit_pkg::msg::WayPointPath path)
    {
		
        visualization_msgs::msg::Marker marker_msg;
        marker_msg.header.stamp = this->get_clock()->now();  
        marker_msg.header.frame_id = "odom";
		marker_msg.points= path.points;
        if(path.closed_path.data){
            marker_msg.points.push_back(marker_msg.points[0]);
        }
        marker_msg.ns = "marker_line";
        marker_msg.id = 0;
        marker_msg.type = visualization_msgs::msg::Marker::LINE_STRIP;
        marker_msg.action = visualization_msgs::msg::Marker::ADD;
        marker_msg.scale.x = 0.05;
        marker_msg.scale.y = 0.1;
        marker_msg.scale.z = 0.1;
        marker_msg.color.a = 1.0;
        marker_msg.color.r = 0.0;
        marker_msg.color.g = 1.0;
        marker_msg.color.b = 0.0;  
         

        marker_pub_->publish(marker_msg);
    }

    void controller(){

		geometry_msgs::msg::Point goalPoint;
		double dClosest;
        
        (void)dClosest; //To avoid warning "unused variable" during compilation proccess
		
        //TODO: Instantiate an object belong to WayPointPathTools class

		if (isPathReceived)
		{
			//TODO: compute closest point to the path, implement pure pursuit controller
			//		based on latest pose of the robot and waypoints	and publish a Twist message 
			// 		on /cmd_vel with the linear and angular velocites
		}

    }

rclcpp::TimerBase::SharedPtr timer_controller;
rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber;
rclcpp::Subscription<pure_pursuit_pkg::msg::WayPointPath>::SharedPtr waypoint_subs;
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub;

rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;

bool isPathReceived;
pure_pursuit_pkg::msg::WayPointPath path;
double x_rob,y_rob,theta_rob,x_rob_0,y_rob_0,theta_rob_0;
double b = (0.16/2);
double L=0.25;
double v_ref = 0.1;
bool initialized_odom = false;
};

std::shared_ptr<PurePursuitOdom> node = nullptr;

void signal_handler(int signum) {

    if (rclcpp::ok()) {
        node->stop_to_cmd_vel();
    }
    rclcpp::shutdown();
    exit(signum);
}


int main(int argc, char *argv[]){

    rclcpp::init(argc,argv);

    node = std::make_shared<PurePursuitOdom>();

    std::signal(SIGINT, signal_handler);

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}

