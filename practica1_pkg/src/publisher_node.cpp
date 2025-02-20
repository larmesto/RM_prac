#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

using namespace std::chrono_literals;

class PosePublisher : public rclcpp::Node
{
  public:
    PosePublisher()
    : Node("publisher_pose")
    {
      publisher_pose_topic = this->create_publisher<geometry_msgs::msg::PoseStamped>("topic_pose", 10);
      timer_ = this->create_wall_timer(
      1000ms, std::bind(&PosePublisher::timer_callback, this));

      //Declare parameters
      frame = this->declare_parameter<std::string>("frame", "robot_frame");

      pos_x = this->declare_parameter<double>("pos_x", 0.0);
      pos_y = this->declare_parameter<double>("pos_y", 0.0);
      pos_z = this->declare_parameter<double>("pos_z", 0.0);

      roll = this->declare_parameter<double>("roll", 0.0);
      pitch = this->declare_parameter<double>("pitch", 0.0);
      yaw = this->declare_parameter<double>("yaw", 0.0);

      parameter_callback_handle_ = this->add_on_set_parameters_callback(
            std::bind(&PosePublisher::on_parameter_changed, this, std::placeholders::_1));
    }

  private:
    void timer_callback()
    {
      auto msg = geometry_msgs::msg::PoseStamped();
      msg.header.stamp = this->now();
      msg.header.frame_id = frame;
      msg.pose.position.x = pos_x;
      msg.pose.position.y = pos_y;
      msg.pose.position.z = pos_z;

      tf2::Quaternion q;
      q.setRPY(roll,pitch,yaw);

      msg.pose.orientation.x = q.x();
      msg.pose.orientation.y = q.y();
      msg.pose.orientation.z = q.z();
      msg.pose.orientation.w = q.w();

      double pose_timestamp = msg.header.stamp.sec + msg.header.stamp.nanosec*1e-9;

      RCLCPP_INFO(this->get_logger(), "Publish Pose:");
      RCLCPP_INFO(this->get_logger(), "Pose Time: %.5f", pose_timestamp);
      RCLCPP_INFO(this->get_logger(), "Frame: '%s'", frame.c_str());
      RCLCPP_INFO(this->get_logger(), "Position:");
      RCLCPP_INFO(this->get_logger(), "x: '%.2f'", pos_x);
      RCLCPP_INFO(this->get_logger(), "y: '%.2f'", pos_y);
      RCLCPP_INFO(this->get_logger(), "z: '%.2f'", pos_z);

      RCLCPP_INFO(this->get_logger(), "Orientation:");
      RCLCPP_INFO(this->get_logger(), "Roll: '%.2f'", roll);
      RCLCPP_INFO(this->get_logger(), "Pitch: '%.2f'", pitch);
      RCLCPP_INFO(this->get_logger(), "Yaw: '%.2f'", yaw);


      publisher_pose_topic->publish(msg);
    }

    //Setear los parametros en tiempo de ejecución
    rcl_interfaces::msg::SetParametersResult on_parameter_changed(const std::vector<rclcpp::Parameter> &parameters)
    {
        for (const auto &parameter : parameters)
        {
            if (parameter.get_name() == "pos_x")
            {
                pos_x = parameter.as_double();
                RCLCPP_INFO(this->get_logger(),"Parameter 'pos_x' Updated");
            }
            else if (parameter.get_name() == "pos_y")
            {
                pos_y = parameter.as_double();
                RCLCPP_INFO(this->get_logger(),"Parameter 'pos_y' Updated");
            }
            else if (parameter.get_name() == "pos_z")
            {
                pos_z = parameter.as_double();
                RCLCPP_INFO(this->get_logger(),"Parameter 'pos_z' Updated");
            }
            else if (parameter.get_name() == "roll")
            {
                roll = parameter.as_double();
                RCLCPP_INFO(this->get_logger(),"Parameter 'Roll' Updated");
            }
            else if (parameter.get_name() == "pitch")
            {
                pitch = parameter.as_double();
                RCLCPP_INFO(this->get_logger(),"Parameter 'Pitch' Updated");
            }
            else if (parameter.get_name() == "yaw")
            {
                yaw = parameter.as_double();
                RCLCPP_INFO(this->get_logger(),"Parameter 'Yaw' Updated");
            }
            else if (parameter.get_name() == "frame")
            {
                frame = parameter.as_string();
                RCLCPP_INFO(this->get_logger(),"Parameter 'Frame' Updated");
            }
        }

        rcl_interfaces::msg::SetParametersResult result;
        result.successful = true; // Indica que los parámetros se han actualizado correctamente
        result.reason = "Parameters updated successfully";
        return result;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    double pose_timestamp;
    double pos_x, pos_y, pos_z, roll, pitch, yaw;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_pose_topic;
    std::string frame;

    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr parameter_callback_handle_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PosePublisher>());
  rclcpp::shutdown();
  return 0;
}