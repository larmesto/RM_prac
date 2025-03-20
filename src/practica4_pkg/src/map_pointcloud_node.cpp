#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include "laser_geometry/laser_geometry.hpp"
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include "geometry_msgs/msg/transform_stamped.hpp"
#include <tf2_sensor_msgs/tf2_sensor_msgs.hpp>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class LaserToPointCloud : public rclcpp::Node {
public:
    LaserToPointCloud() : Node("map_pointcloud_node") {

        rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
        qos_profile.best_effort();
        // Inicializar el buffer y TFlistener
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        laser_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", qos_profile, std::bind(&LaserToPointCloud::scan_callback, this, std::placeholders::_1));

        frame_id = this->declare_parameter<std::string>("frame_id","odom");
        child_frame_id = this->declare_parameter<std::string>("child_frame_id","base_scan");

        // Publicador de la nube de puntos transformada
        cloud_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("/map_cloud", 10);
    }

private:
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        std::string source_frame = frame_id;  // Marco de referencia fijo
        std::string target_frame = child_frame_id; // Frame del LiDAR

        // Obtener la transformacion
        geometry_msgs::msg::TransformStamped transform_stamped;
        try {
            transform_stamped = tf_buffer_->lookupTransform(
                source_frame, target_frame, tf2::TimePointZero
            );
        } catch (tf2::TransformException &ex) {
            RCLCPP_WARN(this->get_logger(), "No se pudo obtener la transformación: %s", ex.what());
            return;
        }

        sensor_msgs::msg::PointCloud2 cloud;
        projector.projectLaser(*msg, cloud);

        sensor_msgs::msg::PointCloud2 cloud_transformed;
        tf2::doTransform(cloud, cloud_transformed, transform_stamped);

        pcl::PointCloud<pcl::PointXYZ> pcl_cloud;
        pcl::fromROSMsg(cloud_transformed, pcl_cloud);

        // Acumulaar la nube de puntos
        pcl_map += pcl_cloud;

        // Convertir a PointCloud2 para publicar
        sensor_msgs::msg::PointCloud2 cloud_output;
        pcl::toROSMsg(pcl_map, cloud_output);
        cloud_output.header.frame_id = frame_id; 
        cloud_output.header.stamp = msg->header.stamp;
        
        cloud_pub_->publish(cloud_output);

        // Publicar la nube de puntos transformada
        //cloud_transformed.header.frame_id = "map";
        //cloud_transformed.header.stamp = msg->header.stamp;
        //cloud_pub_->publish(cloud_transformed);
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr cloud_pub_;
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    laser_geometry::LaserProjection projector;
    sensor_msgs::msg::PointCloud2 map_cloud;
    pcl::PointCloud<pcl::PointXYZ> pcl_map;

    std::string frame_id,child_frame_id;

};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LaserToPointCloud>());
    rclcpp::shutdown();
    return 0;
}
