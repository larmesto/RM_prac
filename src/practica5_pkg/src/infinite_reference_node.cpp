#include <functional>
#include <memory>
#include <string>
#include <chrono>
#include <math.h>

#include "rclcpp/rclcpp.hpp"

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp> //Uso de tf2 para pasar de RPY a Quaternios

#include "tf2_ros/transform_broadcaster.h" //Uso del broadcaster

#include "practica5_pkg/msg/reference.hpp"

#include "visualization_msgs/msg/marker.hpp"


class ReferenceNode : public rclcpp::Node
{
    public:
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster;

    ReferenceNode() : Node("reference_node")
    {
        // Creacion del Timer
        std::chrono::milliseconds period = std::chrono::milliseconds(50);
        timer = this->create_wall_timer(period, std::bind(&ReferenceNode::timer_callback, this));
        
        // Tomamos el tiempo inicial
        init_time = this->get_clock()->now();

        // Publicador
        ref_pub = this->create_publisher<practica5_pkg::msg::Reference>("reference", 10);
        
        marker_pub = this->create_publisher<visualization_msgs::msg::Marker>("reference_marker",10);

    }

    private:

    void timer_callback()
    {
        rclcpp::Time time = this->get_clock()->now();
        rclcpp::Duration diff = time - init_time;

        double t = diff.seconds()+diff.nanoseconds()*1e-9; //This time takes the value with t=0 when the node starts
        (void)t; //to avoid warning when the code is empty 
        
        double x=0.0;
        double y=0.0;
        double theta=0.0;

        double xp=0.0;
        double yp=0.0;
        double thetap=0.0;

        //TODO: Implement the reference to compute x, y and theta and their velocities


        //Publicamos la referencia
        publish_reference(x,y,theta,xp,yp,thetap);
        //Publicamos la transformacion
        reference_marker(x,y,theta);       
    }

    void publish_reference(double x, double y, double theta, double xp, double yp, double thetap)
    {
        tf2::Quaternion q;
        double roll=0.0;
        double pitch=0.0;
        q.setRPY(roll,pitch,theta);

        geometry_msgs::msg::Pose pose_msg;
        pose_msg.position.x = x;
        pose_msg.position.y = y;
        pose_msg.orientation.x = q.x();
        pose_msg.orientation.y = q.y();
        pose_msg.orientation.z = q.z();
        pose_msg.orientation.w = q.w();
        
        geometry_msgs::msg::Twist vel_msg;
        vel_msg.linear.x = xp;
        vel_msg.linear.y = yp;
        vel_msg.angular.z = thetap;

        practica5_pkg::msg::Reference ref_msg;
        ref_msg.pose = pose_msg;
        ref_msg.velocity = vel_msg;

        //Publicamos
        ref_pub->publish(ref_msg);
    }

    void reference_marker(double x, double y, double theta)
    {
        geometry_msgs::msg::Point start_tf, end_tf;
        start_tf.x = x;
        start_tf.y = y;
        start_tf.z = 0.0;
        
        end_tf.x = x+0.25*cos(theta);
        end_tf.y = y+0.25*sin(theta);
        end_tf.z = 0;       

        visualization_msgs::msg::Marker marker_msg;
        marker_msg.header.stamp = this->get_clock()->now();  
        marker_msg.header.frame_id = "odom";
        marker_msg.points.push_back(start_tf);
        marker_msg.points.push_back(end_tf); 
        marker_msg.ns = "marker_arrow";
        marker_msg.id = 0;
        marker_msg.type = visualization_msgs::msg::Marker::ARROW;
        marker_msg.action = visualization_msgs::msg::Marker::ADD;
        marker_msg.scale.x = 0.05;
        marker_msg.scale.y = 0.1;
        marker_msg.scale.z = 0.1;
        marker_msg.color.a = 1.0;
        marker_msg.color.r = 0.0;
        marker_msg.color.g = 1.0;
        marker_msg.color.b = 0.0;        

        marker_pub->publish(marker_msg);

    }
    
    rclcpp::Time init_time;
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<practica5_pkg::msg::Reference>::SharedPtr ref_pub;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub;


};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ReferenceNode>());
   
    rclcpp::shutdown();
    return 0;
}