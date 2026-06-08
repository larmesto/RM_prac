#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include <csignal> //interruptions

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>


class CmdVelPublisher : public rclcpp::Node
{
  public:
    CmdVelPublisher()
    : Node("cmd_vel_publisher")
    {
      cmd_vel_publisher = this->create_publisher<geometry_msgs::msg::TwistStamped>("cmd_vel", 10);

      odom_subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
      "odom", 10, std::bind(&CmdVelPublisher::odom_data_callback, this,std::placeholders::_1));

      timer = this->create_wall_timer(
      std::chrono::milliseconds(100), std::bind(&CmdVelPublisher::cmd_vel_callback, this));
    }

    void stop_to_cmd_vel(){

    geometry_msgs::msg::TwistStamped stop_msg;
	stop_msg.header.stamp = this->now();
	stop_msg.header.frame_id = "base_link";
    stop_msg.twist.linear.x = 0.0;
    stop_msg.twist.angular.z = 0.0;
  
    cmd_vel_publisher->publish(stop_msg);
    
    RCLCPP_INFO(this->get_logger(),"Stop command sent");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }



  private:
    void cmd_vel_callback()
    {
        //TODO: Publish on cmd_vel topic
    		geometry_msgs::msg::TwistStamped cmd_vel_msg = geometry_msgs::msg::TwistStamped();
    		rclcpp::Time time = this->now();
    		double t=time.seconds();
    		(void)t; // This is to avoid a warning when the code is empty
			cmd_vel_msg.header.stamp = time;
    		cmd_vel_msg.header.frame_id = "base_link";
			cmd_vel_msg.twist.linear.x=0.0;
    		cmd_vel_msg.twist.angular.z=0.2;
    		cmd_vel_publisher->publish(cmd_vel_msg);
    }

    void odom_data_callback(const nav_msgs::msg::Odometry::SharedPtr odom_msg){
      //TODO: Print positions x,y and linear velocities x,y  and angle theta
      RCLCPP_INFO(this->get_logger(),"x: %f",odom_msg->pose.pose.position.x);
    }
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr cmd_vel_publisher;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber;
};


std::shared_ptr<CmdVelPublisher> node = nullptr;

void signal_handler(int signum) {

    if (rclcpp::ok()) {
        node->stop_to_cmd_vel();
    }
    rclcpp::shutdown();
    exit(signum);
}

int main(int argc, char *argv[]){

    rclcpp::init(argc,argv);

    node = std::make_shared<CmdVelPublisher>();

    std::signal(SIGINT, signal_handler);

    rclcpp::spin(node);

    return 0;
}
