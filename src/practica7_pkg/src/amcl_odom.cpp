#include <chrono>   //milliseconds
#include <functional> // std::bind
#include <memory>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>


#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>

#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>

#include "std_msgs/msg/header.hpp"


#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>




class AmclOdom : public rclcpp::Node	
{

public: AmclOdom() : Node("amcl_odom")
{
	rclcpp::QoS qos_profile(10);
        qos_profile.reliability(RMW_QOS_POLICY_RELIABILITY_RELIABLE); 
        qos_profile.durability(RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL);

    odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom",10,std::bind(&AmclOdom::odom_callback,this,std::placeholders::_1));
    
    amcl_subscriber = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
        "amcl_pose",10,std::bind(&AmclOdom::amcl_callback,this,std::placeholders::_1));
    
    odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("amcl_odom",10);
		
}

private:

    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr odom_msg){
        if (initialized_odom)
        {
            x_odom = odom_msg->pose.pose.position.x - x_odom_0;
            y_odom = odom_msg->pose.pose.position.y - y_odom_0;

            tf2::Quaternion q( 
        	    odom_msg->pose.pose.orientation.x,
        	    odom_msg->pose.pose.orientation.y,
        	    odom_msg->pose.pose.orientation.z,
        	    odom_msg->pose.pose.orientation.w);

        	double roll, pitch, yaw;
        	tf2::Matrix3x3 m(q);
        	m.getRPY(roll,pitch,yaw);

            theta_odom = yaw - theta_odom_0;
    
            double inc_x_odom = cos(theta_odom_0) * (x_odom - last_odom_x) + sin(theta_odom_0) * (y_odom - last_odom_y);
            double inc_y_odom = -sin(theta_odom_0) * (x_odom - last_odom_x) + cos(theta_odom_0) * (y_odom - last_odom_y);
            double inc_theta_odom = theta_odom - last_odom_theta;
    
            x_rob += cos(inc_theta_odom) * inc_x_odom - sin(inc_theta_odom) * inc_y_odom;
            y_rob += sin(inc_theta_odom) * inc_x_odom + cos(inc_theta_odom) * inc_y_odom;
            theta_rob += inc_theta_odom;
    
            last_odom_x = x_odom;
            last_odom_y = y_odom;
            last_odom_theta = theta_odom;

            tf2::Quaternion q_msg;
            q_msg.setRPY(0.0,0.0,theta_rob);


            nav_msgs::msg::Odometry amcl_odom_msg = *odom_msg;

            amcl_odom_msg.header.frame_id = "map";
            amcl_odom_msg.header.stamp = this->get_clock()->now();
            amcl_odom_msg.child_frame_id = "base_footprint";
            amcl_odom_msg.pose.pose.position.x = x_rob;
            amcl_odom_msg.pose.pose.position.y = y_rob;

            amcl_odom_msg.pose.pose.orientation.x = q_msg.x();
            amcl_odom_msg.pose.pose.orientation.y = q_msg.y();
            amcl_odom_msg.pose.pose.orientation.z = q_msg.z();
            amcl_odom_msg.pose.pose.orientation.w = q_msg.w();


            odom_pub_->publish(amcl_odom_msg);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Reseting odometry");
            x_odom_0 = odom_msg->pose.pose.position.x;
            y_odom_0 = odom_msg->pose.pose.position.y;

            tf2::Quaternion q( 
        	    odom_msg->pose.pose.orientation.x,
        	    odom_msg->pose.pose.orientation.y,
        	    odom_msg->pose.pose.orientation.z,
        	    odom_msg->pose.pose.orientation.w);

        	double roll, pitch, yaw;
        	tf2::Matrix3x3 m(q);
        	m.getRPY(roll,pitch,yaw);

            theta_odom_0 = yaw;
            initialized_odom = true;
        }
    }

    void amcl_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr amcl_msg)
    {

        double time_amcl = amcl_msg->header.stamp.sec + amcl_msg->header.stamp.nanosec*1e-9;
        x_amcl = amcl_msg->pose.pose.position.x;
        y_amcl = amcl_msg->pose.pose.position.y;

        geometry_msgs::msg::Quaternion q_msg = amcl_msg->pose.pose.orientation;

        tf2::Quaternion q_amcl;
        tf2::fromMsg(q_msg,q_amcl);
        tf2::Matrix3x3 m(q_amcl);
        double roll,pitch,yaw;
        m.getRPY(roll,pitch,yaw);

        theta_amcl = yaw;

        x_rob = x_amcl;
        y_rob = y_amcl;
        theta_rob = theta_amcl;

        
        RCLCPP_INFO(this->get_logger(),"AMCL_0: Time: %.5f, x: %.5f, y: %.5f, theta: %.5f",time_amcl,x_amcl,y_amcl,theta_amcl);
    }

    



rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber; 
rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr amcl_subscriber; 

rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;

double x_rob,y_rob,theta_rob;
double x_odom,y_odom,theta_odom;
double x_amcl,y_amcl,theta_amcl;
double x_odom_0 = 0.0;
double y_odom_0 = 0.0;
double theta_odom_0 = 0.0;

double last_odom_x = 0.0;
double last_odom_y = 0.0;
double last_odom_theta = 0.0;

bool initialized_odom = false;
};

int main(int argc, char *argv[]){

    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<AmclOdom>());
    rclcpp::shutdown();
    return 0;

}