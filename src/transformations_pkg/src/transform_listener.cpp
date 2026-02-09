#include <functional> 
#include <memory> 
#include <string> 
#include <math.h> 

#include "rclcpp/rclcpp.hpp" 

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp> 
#include "geometry_msgs/msg/twist.hpp"
#include "tf2_ros/transform_listener.h" 
#include "tf2_ros/buffer.h" 
#include "tf2/exceptions.h" 

class TransformListener : public rclcpp::Node 

{ 
  public: 

  TransformListener() : Node("transform_listener_node") 
  { 

    tf_buffer = std::make_unique<tf2_ros::Buffer>(this->get_clock()); 
    tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer); 
    
    bill_subscriber = this->create_subscription<geometry_msgs::msg::Point>( 
    "bill",10,std::bind(&TransformListener::camera_callback,this,std::placeholders::_1)); 
    
    cmd_vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel",10); 
  } 
  private: 

  void camera_callback(const geometry_msgs::msg::Point::SharedPtr bill_pos_cam_msg) 

  { 
    (void)bill_pos_cam_msg; // This is to avoid a warning when the code is empty

    std::string target_frame = "camera_link"; 
    std::string source_frame = "base_footprint"; 

    geometry_msgs::msg::TransformStamped transform; 

    rclcpp::Time now = this->get_clock()->now(); 

    try{ 
      transform = tf_buffer->lookupTransform(source_frame, target_frame, now); 

      RCLCPP_INFO(this->get_logger(), "Transform: '%s' referred to '%s'", target_frame.c_str(), source_frame.c_str());
    } 

    catch (const tf2::TransformException & ex){ 

      RCLCPP_WARN(this->get_logger(),"We could not obtain the transform");} 

    //TODO: do transform of bill_pose_cam_msg; compute linear and angular velocities; publish  

    //geometry_msgs::msg::Twist message on cmd_vel topic; 

  } 

  std::unique_ptr<tf2_ros::Buffer> tf_buffer; 
  std::shared_ptr<tf2_ros::TransformListener> tf_listener; 
  rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr bill_subscriber; 
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub; 

}; 

int main(int argc, char * argv[]) 
{  
  rclcpp::init(argc, argv); 
  rclcpp::spin(std::make_shared<TransformListener>()); 
  rclcpp::shutdown(); 
  return 0; 
} 
