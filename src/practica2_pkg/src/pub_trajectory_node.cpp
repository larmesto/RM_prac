#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>


class PublisherTrajectory : public rclcpp::Node
{
  public:
    PublisherTrajectory()
    : Node("pub_trajectory_node")
    {
      cmd_vel_publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

      odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
      "odom", 10, std::bind(&PublisherTrajectory::odom_data_callback, this,std::placeholders::_1));

      timer = this->create_wall_timer(
      std::chrono::milliseconds(100), std::bind(&PublisherTrajectory::timer_callback, this));

      init_time = this->get_clock()->now();
    }

  private:
    void timer_callback()
    {
        //auto cmd_vel_msg = geometry_msgs::msg::Twist();
        geometry_msgs::msg::Twist cmd_vel_msg;

        rclcpp::Time time = this->get_clock()->now();

        double t = time.seconds() - init_time.seconds();

        double linear_vel = sin(t);
        double angular_vel = cos(t); 
        
        cmd_vel_msg.linear.x = linear_vel;
        cmd_vel_msg.angular.z = angular_vel;

        RCLCPP_INFO(this->get_logger(), "Linear: '%.5f'",linear_vel);
        RCLCPP_INFO(this->get_logger(), "Angular: '%.5f'",angular_vel);

        // Publish cmd_vel
        cmd_vel_publisher->publish(cmd_vel_msg);

    }

    void odom_data_callback(const nav_msgs::msg::Odometry::SharedPtr odom_msg){

      double pos_x = odom_msg->pose.pose.position.x;
      double pos_y = odom_msg->pose.pose.position.y;

      tf2::Quaternion q(
        odom_msg->pose.pose.orientation.x,
        odom_msg->pose.pose.orientation.y,
        odom_msg->pose.pose.orientation.z,
        odom_msg->pose.pose.orientation.w);
        
      tf2::Matrix3x3 m(q);
      double roll, pitch, yaw;
      m.getRPY(roll, pitch, yaw);

      double vel_x = odom_msg->twist.twist.linear.x;
      double vel_y = odom_msg->twist.twist.linear.y;
      double theta_vel = odom_msg->twist.twist.angular.z;

      RCLCPP_INFO(this->get_logger(),"Position x: '%.5f'", pos_x);
      RCLCPP_INFO(this->get_logger(),"Position y: '%.5f'", pos_y);
      RCLCPP_INFO(this->get_logger(),"Theta: '%.5f'", yaw);

      RCLCPP_INFO(this->get_logger(),"Velocidad x: '%.5f'", vel_x);
      RCLCPP_INFO(this->get_logger(),"Velocidad y: '%.5f'", vel_y);

      RCLCPP_INFO(this->get_logger(),"Velocidad angular: '%.5f'", theta_vel);
    }
   
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Time init_time;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PublisherTrajectory>());
  rclcpp::shutdown();
  return 0;
}