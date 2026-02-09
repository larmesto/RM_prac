#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>


class CmdVelPublisher : public rclcpp::Node
{
  public:
    CmdVelPublisher()
    : Node("cmd_vel_publisher")
    {
      cmd_vel_publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

      odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
      "odom", 10, std::bind(&CmdVelPublisher::odom_data_callback, this,std::placeholders::_1));

      timer = this->create_wall_timer(
      std::chrono::milliseconds(100), std::bind(&CmdVelPublisher::cmd_vel_callback, this));
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
  rclcpp::spin(std::make_shared<CmdVelPublisher>());
  rclcpp::shutdown();
  return 0;
}
