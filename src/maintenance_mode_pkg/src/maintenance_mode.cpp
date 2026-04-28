#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/msg/battery_state.hpp>
#include <std_srvs/srv/empty.hpp>
#include <turtlebot3_msgs/srv/sound.hpp>

using namespace std::chrono_literals;
//ros2 service call /sound turtlebot3_msgs/srv/Sound "{value: 0}"
//ros2 service call /shutdown_robot std_srvs/srv/Empty 
class MaintenanceMode : public rclcpp::Node
{
  public:
    MaintenanceMode()
    : Node("maintenance_mode")
    {
      cmd_vel_publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

      bat_subscriber = this->create_subscription<sensor_msgs::msg::BatteryState>(
      "battery_state", 10, std::bind(&MaintenanceMode::bat_data_callback, this,std::placeholders::_1));

      timer = this->create_wall_timer(
      std::chrono::milliseconds(100), std::bind(&MaintenanceMode::cmd_vel_callback, this));
	  
	  shutdown_srv = this->create_client<std_srvs::srv::Empty>("shutdown_robot");
	  sound_srv = this->create_client<turtlebot3_msgs::srv::Sound>("sound");
    }

void stop_to_cmd_vel(){

    geometry_msgs::msg::Twist stop_msg;
    stop_msg.linear.x = 0.0;
    stop_msg.angular.z = 0.0;
  
    cmd_vel_publisher->publish(stop_msg);
    
    RCLCPP_INFO(this->get_logger(),"Stop command sent");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

  private:
    void cmd_vel_callback()
    {
        //TODO: Publish on cmd_vel topic
    		geometry_msgs::msg::Twist cmd_vel_msg = geometry_msgs::msg::Twist();
    		rclcpp::Time time = this->get_clock()->now();
    		double t=time.seconds();
    		(void)t; // This is to avoid a warning when the code is empty
    		cmd_vel_msg.linear.x=0.1*sin(t);
    		cmd_vel_msg.angular.z=0.1*cos(t);
    		cmd_vel_publisher->publish(cmd_vel_msg);
    }

    void bat_data_callback(const sensor_msgs::msg::BatteryState::SharedPtr bat_msg){
      //TODO: Print positions x,y and linear velocities x,y  and angle theta
      RCLCPP_INFO(this->get_logger(),"Bat: %.2f ",bat_msg->percentage);
	  if (bat_msg->percentage<80 && !sound_played)
	  {
		  geometry_msgs::msg::Twist cmd_vel_msg = geometry_msgs::msg::Twist();
    	  cmd_vel_msg.linear.x=0;
    	  cmd_vel_msg.angular.z=0;
    	  cmd_vel_publisher->publish(cmd_vel_msg);
		  if (!sound_srv->service_is_ready()) {
			  RCLCPP_WARN(this->get_logger(), "Sound service not ready");
			  return;
			}

			auto request = std::make_shared<turtlebot3_msgs::srv::Sound::Request>();
			request->value = 2;

			sound_srv->async_send_request(
			  request,
			  [this](rclcpp::Client<turtlebot3_msgs::srv::Sound>::SharedFuture future) {
				  auto response = future.get();
				  if (response->success)
					RCLCPP_INFO(this->get_logger(),response->message.c_str());
				this->sound_played = true;
			  });
			  
		if (!shutdown_srv->service_is_ready()) {
		  RCLCPP_WARN(this->get_logger(), "Shutdown service not available");
		  return;
		}

		auto request1 = std::make_shared<std_srvs::srv::Empty::Request>();

		shutdown_srv->async_send_request(request1);
	  }
    }
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher;
    rclcpp::Subscription<sensor_msgs::msg::BatteryState>::SharedPtr bat_subscriber;
	rclcpp::Client<std_srvs::srv::Empty>::SharedPtr shutdown_srv;
	rclcpp::Client<turtlebot3_msgs::srv::Sound>::SharedPtr sound_srv;
	bool sound_played = false;
};

std::shared_ptr<MaintenanceMode> node = nullptr;

void signal_handler(int signum) {

    if (rclcpp::ok()) {
        node->stop_to_cmd_vel();
    }
    rclcpp::shutdown();
    exit(signum);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MaintenanceMode>());
  rclcpp::shutdown();
  return 0;
}
