#include <rclcpp/rclcpp.hpp>
#include "practica6_pkg/msg/way_point_path.hpp"

#include "visualization_msgs/msg/marker.hpp"

#include <ament_index_cpp/get_package_share_directory.hpp>
#include <yaml-cpp/yaml.h>
using namespace std::chrono_literals;

typedef struct Point
{
    double x;
    double y;
}Point_t;


class WayPointsNode : public rclcpp::Node{

    public: WayPointsNode() : Node("waypoints_node"){

        rclcpp::QoS qos_profile(10);
        qos_profile.reliability(RMW_QOS_POLICY_RELIABILITY_RELIABLE); 
        qos_profile.durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);

        waypoint_pub_ = this->create_publisher<practica6_pkg::msg::WayPointPath>("waypoints",qos_profile);
        //marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("marker_path",qos_profile);

        path_yaml = this->declare_parameter<std::string>("path_file", ament_index_cpp::get_package_share_directory("practica6_pkg") + "/config/path.yaml");

        get_path();

        timer_waypoint_ = this->create_wall_timer(1s,std::bind(&WayPointsNode::timer_waypoints_callback, this));
        //create_waypoints();
    }

    void timer_waypoints_callback(){

        practica6_pkg::msg::WayPointPath path_msg;
        geometry_msgs::msg::Point p;
        int n = points.size();

        for(int i=0;i<n;i++){

            p.x=points[i].x;
            p.y=points[i].y;

            path_msg.points.push_back(p);

            RCLCPP_INFO(this->get_logger(),"Path: x: %.2f y: %.2f",path_msg.points[i].x,path_msg.points[i].y);
        }
        path_msg.closed_path.data=true;

        waypoint_pub_->publish(path_msg);
        //path_marker(path_msg);
    }

    void get_path(){

        try {
            YAML::Node config = YAML::LoadFile(path_yaml);
            YAML::Node points_node = config["points"];
    
            for (const auto& point : points_node) {
                if (point.IsSequence() && point.size() == 2) {
                    points.push_back({point[0].as<double>(), point[1].as<double>()});
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Error al leer el fichero: " << e.what() << std::endl;
        }
    }

    /*
    void path_marker(practica6_pkg::msg::WayPointPath path)
    {
    
        visualization_msgs::msg::Marker marker_msg;
        marker_msg.header.stamp = this->get_clock()->now();  
        marker_msg.header.frame_id = "odom";
        marker_msg.points= path.points;
        if(path.closed_path.data){
            marker_msg.points.push_back(path.points[0]);
        }
        marker_msg.ns = "marker_line";
        marker_msg.id = 0;
        marker_msg.type = visualization_msgs::msg::Marker::LINE_STRIP;
        marker_msg.action = visualization_msgs::msg::Marker::ADD;
        marker_msg.scale.x = 0.05;
        marker_msg.scale.y = 0.1;
        marker_msg.scale.z = 0.1;
        marker_msg.color.a = 1.0;
        marker_msg.color.r = 0.0;
        marker_msg.color.g = 1.0;
        marker_msg.color.b = 0.0;  
         

        marker_pub_->publish(marker_msg);
    }
    */

    rclcpp::Publisher<practica6_pkg::msg::WayPointPath>::SharedPtr waypoint_pub_;
    //rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
    rclcpp::TimerBase::SharedPtr timer_waypoint_;

    //std::vector<Point_t> points = {{0.0,1.0},{1.0,1.0},{2.0,0.0},{2.0,-1.0},{1.0,-2.0},{0.0,-2.0},{-1.0,-1.0},{-1.0,0.0}};    
    std::vector<Point_t> points;
    std::string path_yaml;
};

int main(int argc, char* argv[]){

    rclcpp::init(argc,argv);

    WayPointsNode::SharedPtr node;
    node = std::make_shared<WayPointsNode>();
    
    rclcpp::spin(node);
 
    return 0;   
}
