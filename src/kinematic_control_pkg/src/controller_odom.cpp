#include <chrono>   //milliseconds
#include <functional> // std::bind
#include <memory>
#include <string>
#include <math.h>

#include <csignal> //interruptions


#include <rclcpp/rclcpp.hpp>

#include <nav_msgs/msg/odometry.hpp>

#include "std_msgs/msg/header.hpp"


#include "builtin_interfaces/msg/time.hpp"

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>


//msg reference
#include "kinematic_control_pkg/msg/reference.hpp"
#include "visualization_msgs/msg/marker.hpp"


class ControllerOdom : public rclcpp::Node
{

public: ControllerOdom() : Node("controller")
{
    std::chrono::milliseconds period_control = std::chrono::milliseconds(50);
    timer_controller = this->create_wall_timer(period_control,std::bind(&ControllerOdom::controller,this));

    odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom",10,std::bind(&ControllerOdom::odom_callback,this,std::placeholders::_1));

    ref_subs = this->create_subscription<kinematic_control_pkg::msg::Reference>(
        "reference",10,std::bind(&ControllerOdom::reference_callback, this, std::placeholders::_1));

    cmd_vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10);
	marker_pub = this->create_publisher<visualization_msgs::msg::Marker>("reference_marker",10);
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

    void reference_callback(const kinematic_control_pkg::msg::Reference::SharedPtr ref_msg){

        double x_ref_ = ref_msg->pose.position.x;
        double y_ref_ = ref_msg->pose.position.y; 
        tf2::Quaternion q(
            ref_msg->pose.orientation.x,
            ref_msg->pose.orientation.y,
            ref_msg->pose.orientation.z,
            ref_msg->pose.orientation.w);
        tf2::Matrix3x3 m(q);
        double roll,pitch,yaw;
        m.getRPY(roll,pitch,yaw);
        double theta_ref_ = yaw;

        x_ref=cos(theta_rob_0)*x_ref_-sin(theta_rob_0)*y_ref_+x_rob_0;
		y_ref=sin(theta_rob_0)*x_ref+cos(theta_rob_0)*y_ref+y_rob_0;

        theta_ref=theta_rob_0+theta_ref_;

        xp_ref=cos(theta_rob_0)*ref_msg->velocity.linear.x-sin(theta_rob_0)*ref_msg->velocity.linear.y;
		yp_ref=sin(theta_rob_0)*ref_msg->velocity.linear.x+cos(theta_rob_0)*ref_msg->velocity.linear.y;
		thetap_ref=ref_msg->velocity.angular.z;
		reference_marker(x_ref,y_ref,theta_ref);
    }
	
	void reference_marker(double x, double y, double theta)
    {
        geometry_msgs::msg::Point start_tf, end_tf;
        start_tf.x = x;
        start_tf.y = y;
        start_tf.z = 0.0;
        
        end_tf.x = x+0.25*cos(theta);
        end_tf.y = y+0.25*sin(theta);
        end_tf.z = 0;       

        visualization_msgs::msg::Marker marker_msg;
        marker_msg.header.stamp = this->get_clock()->now();  
        marker_msg.header.frame_id = "odom";
        marker_msg.points.push_back(start_tf);
        marker_msg.points.push_back(end_tf); 
        marker_msg.ns = "marker_arrow";
        marker_msg.id = 0;
        marker_msg.type = visualization_msgs::msg::Marker::ARROW;
        marker_msg.action = visualization_msgs::msg::Marker::ADD;
        marker_msg.scale.x = 0.05;
        marker_msg.scale.y = 0.1;
        marker_msg.scale.z = 0.1;
        marker_msg.color.a = 1.0;
        marker_msg.color.r = 0.0;
        marker_msg.color.g = 1.0;
        marker_msg.color.b = 0.0;        

        marker_pub->publish(marker_msg);

    }

    void controller(){

       //TODO: Implement kinematic controller based on latest pose of the robot and reference
       //TODO: Publish a Twist message on /cmd_vel with the linear and angular velocites
    }

rclcpp::TimerBase::SharedPtr timer_controller;
rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber;
rclcpp::Subscription<kinematic_control_pkg::msg::Reference>::SharedPtr ref_subs;
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub;
rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub;

double x_rob,y_rob,theta_rob;
double x_rob_0,y_rob_0,theta_rob_0;
double x_ref,y_ref,theta_ref,xp_ref,yp_ref,thetap_ref;
double b = (0.16/2);
bool initialized_odom = false;

};

std::shared_ptr<ControllerOdom> node = nullptr;

void signal_handler(int signum) {

    if (rclcpp::ok()) {
        node->stop_to_cmd_vel();
    }
    rclcpp::shutdown();
    exit(signum);
}

int main(int argc, char *argv[]){

    rclcpp::init(argc,argv);

    node = std::make_shared<ControllerOdom>();

    std::signal(SIGINT, signal_handler);

    rclcpp::spin(node);

    return 0;
}