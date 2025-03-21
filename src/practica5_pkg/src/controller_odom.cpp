#include <chrono>   //milliseconds
#include <functional> // std::bind
#include <memory>
#include <string>
#include <math.h>

#include <rclcpp/rclcpp.hpp>

#include <nav_msgs/msg/odometry.hpp>

#include "std_msgs/msg/header.hpp"

//#include "std_msgs/msg/float64_multi_array.hpp"

#include "builtin_interfaces/msg/time.hpp"

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>


//lookup_transform
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2/exceptions.h"

//msg reference
#include "practica5_pkg/msg/reference.hpp"


class ControllerOdom : public rclcpp::Node
{

public: ControllerOdom() : Node("controller")
{
    std::chrono::milliseconds period_control = std::chrono::milliseconds(50);
    timer_controller = this->create_wall_timer(period_control,std::bind(&ControllerOdom::controller,this));

    odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom",10,std::bind(&ControllerOdom::odom_callback,this,std::placeholders::_1));

    ref_subs = this->create_subscription<practica5_pkg::msg::Reference>(
        "reference",10,std::bind(&ControllerOdom::reference_callback, this, std::placeholders::_1));

    cmd_vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10);

}

private:


    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr odom_msg){

        std::string parent_frame = odom_msg->header.frame_id;
        std::string child_frame = odom_msg->child_frame_id;

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

    void reference_callback(const practica5_pkg::msg::Reference::SharedPtr ref_msg){

        x_ref = ref_msg->pose.position.x;
        y_ref = ref_msg->pose.position.y; 
        tf2::Quaternion q(
            ref_msg->pose.orientation.x,
            ref_msg->pose.orientation.y,
            ref_msg->pose.orientation.z,
            ref_msg->pose.orientation.w);
        tf2::Matrix3x3 m(q);
        double roll,pitch,yaw;
        m.getRPY(roll,pitch,yaw);
        theta_ref = yaw;

        xp_ref = ref_msg->velocity.linear.x;
        yp_ref = ref_msg->velocity.linear.y;
    }

    void controller(){

       //TODO: Implement kinematic controller based on latest pose of the robot and reference
       //TODO: Publish a Twist message on /cmd_vel with the linear and angular velocites
    }

rclcpp::TimerBase::SharedPtr timer_controller;
rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber;
rclcpp::Subscription<practica5_pkg::msg::Reference>::SharedPtr ref_subs;
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub;

double x_rob,y_rob,theta_rob;
double x_ref,y_ref,theta_ref,xp_ref,yp_ref;
double b = (0.16/2);
};

int main(int argc, char *argv[]){

    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<ControllerOdom>());
    rclcpp::shutdown();
    return 0;

}