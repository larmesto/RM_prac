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
    : Node("NODE_NAME")
    {
      cmd_vel_publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

      odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
      "odom", 10, std::bind(&PublisherTrajectory::odom_data_callback, this,std::placeholders::_1));

      timer = this->create_wall_timer(
      std::chrono::milliseconds(100), std::bind(&PublisherTrajectory::cmd_vel_callback, this));
    }

  private:
    void cmd_vel_callback()
    {
        //TODO: Publish on cmd_vel topic
    }

    void odom_data_callback(const nav_msgs::msg::Odometry::SharedPtr odom_msg){

      (void)odom_msg; // This is to avoid a warning when the code is empty

      //TODO: Print positions x,y and linear velocities x,y  and angular velocity z
      //Hint: Use RCLCPP_INFO
    }
    rclcpp::TimerBase::SharedPtr timer;
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
