#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

using std::placeholders::_1;

class PoseSubscriber : public rclcpp::Node
{
  public:
    PoseSubscriber()
    : Node("subscriber_pose")
    {
      subscription_pose_topic = this->create_subscription<geometry_msgs::msg::PoseStamped>(
      "topic_pose", 10, std::bind(&PoseSubscriber::data_topic_callback, this, _1));
    }

  private:
    void data_topic_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) const
    {
        //Almacenamos en variables locales los datos que recibimos en el mensaje accediendo a los campos de este
        double pose_timestamp = msg->header.stamp.sec + msg->header.stamp.nanosec*1e-9;

        double x_position = msg->pose.position.x;
        double y_position = msg->pose.position.y;
        double z_position = msg->pose.position.z;

        tf2::Quaternion q(
        msg->pose.orientation.x,
        msg->pose.orientation.y,
        msg->pose.orientation.z,
        msg->pose.orientation.w);
        
        tf2::Matrix3x3 m(q);
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);
        
      RCLCPP_INFO(this->get_logger(), "Pose recibida en el tiempo: '%.5f'", pose_timestamp);
      RCLCPP_INFO(this->get_logger(), "Position_x: '%.2f' ", x_position);
      RCLCPP_INFO(this->get_logger(), "Position_y: '%.2f' ", y_position);
      RCLCPP_INFO(this->get_logger(), "Position_z: '%.2f' ", z_position);
      RCLCPP_INFO(this->get_logger(), "Roll: '%.2f'", roll);
      RCLCPP_INFO(this->get_logger(), "Pitch: '%.2f'", pitch);
      RCLCPP_INFO(this->get_logger(), "Yaw: '%.2f'", yaw);
    }
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_pose_topic;
    double x_position,y_position,z_position;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PoseSubscriber>());
  rclcpp::shutdown();
  return 0;
}