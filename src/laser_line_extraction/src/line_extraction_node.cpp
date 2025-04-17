#include <rclcpp/rclcpp.hpp>
#include <cmath>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <visualization_msgs/msg/marker.hpp>

#include "laser_line_extraction/msg/line_segment.hpp"
#include "laser_line_extraction/msg/line_segment_list.hpp"
#include "laser_line_extraction/line_extraction.h"
#include "laser_line_extraction/line.h"

namespace line_extraction
{
	
class LaserLineExtraction : public rclcpp::Node {
public:
    LaserLineExtraction() : Node("line_extraction_node") {

        rclcpp::QoS qos_profile(rclcpp::KeepLast(10));
        qos_profile.best_effort();
		
		std::string scan_topic;
		double bearing_std_dev, range_std_dev, least_sq_angle_thresh, least_sq_radius_thresh,
         max_line_gap, min_line_length, min_range, max_range, min_split_dist, outlier_dist;
  int min_line_points;
		
		RCLCPP_INFO(get_logger(), "Creating laser_line_extraction");
		add_parameter("frame_id", rclcpp::ParameterValue(std::string("base_scan")),
    "Which frame to use for the laser");
		add_parameter("scan_topic", rclcpp::ParameterValue(std::string("scan")),
    "topic name of the laser scan");
		add_parameter("publish_markers",rclcpp::ParameterValue(true),
    " If publish_markers");
		add_parameter("bearing_std_dev",rclcpp::ParameterValue(1e-3));
		add_parameter("range_std_dev",rclcpp::ParameterValue(0.02));
		add_parameter("least_sq_angle_thresh",rclcpp::ParameterValue(1e-4));
		add_parameter("least_sq_radius_thresh",rclcpp::ParameterValue(1e-4));
		add_parameter("max_line_gap",rclcpp::ParameterValue(0.4));
		add_parameter("min_line_length",rclcpp::ParameterValue(0.5));
		add_parameter("min_range",rclcpp::ParameterValue(0.4));
		add_parameter("max_range",rclcpp::ParameterValue(10000.0));
		add_parameter("min_split_dist",rclcpp::ParameterValue(0.05));
		add_parameter("outlier_dist",rclcpp::ParameterValue(0.05));
		add_parameter("min_line_points", rclcpp::ParameterValue(10));
	
		frame_id_=this->get_parameter("frame_id").as_string();
		RCLCPP_DEBUG(get_logger(), "Frame id %s",frame_id_.c_str());
		scan_topic=this->get_parameter("scan_topic").as_string();
		RCLCPP_DEBUG(get_logger(), "Scan topic %s",scan_topic.c_str());
		pub_markers_   = this->get_parameter("publish_markers").as_bool();
		RCLCPP_DEBUG(get_logger(), "Publish markers %d",pub_markers_);
		bearing_std_dev   = this->get_parameter("bearing_std_dev").as_double();
		RCLCPP_DEBUG(get_logger(), "Bearing standard deviation %f",bearing_std_dev);
		line_extraction_.setBearingVariance(bearing_std_dev * bearing_std_dev);
		range_std_dev   = this->get_parameter("range_std_dev").as_double();
		RCLCPP_DEBUG(get_logger(), "Range standard deviation %f",range_std_dev);
		line_extraction_.setRangeVariance(range_std_dev * range_std_dev);
		least_sq_angle_thresh= this->get_parameter("least_sq_angle_thresh").as_double();
		RCLCPP_DEBUG(get_logger(), "Least squares angle threshold %f",least_sq_angle_thresh);
		line_extraction_.setLeastSqAngleThresh(least_sq_angle_thresh);
		least_sq_radius_thresh= this->get_parameter("least_sq_radius_thresh").as_double();
		RCLCPP_DEBUG(get_logger(), "Least squares radius threshold %f",least_sq_radius_thresh);
		line_extraction_.setLeastSqRadiusThresh(least_sq_radius_thresh);
		max_line_gap= this->get_parameter("max_line_gap").as_double();
		RCLCPP_DEBUG(get_logger(), "Max line gap %f",max_line_gap);
		line_extraction_.setMaxLineGap(max_line_gap);
		min_line_length= this->get_parameter("min_line_length").as_double();
		RCLCPP_DEBUG(get_logger(), "Min line length %f",min_line_length);
		line_extraction_.setMinLineLength(min_line_length);
		min_range= this->get_parameter("min_range").as_double();
		RCLCPP_DEBUG(get_logger(), "Min range %f",min_range);
		line_extraction_.setMinRange(min_range);
		max_range= this->get_parameter("max_range").as_double();
		RCLCPP_DEBUG(get_logger(), "Max range %f",max_range);
		line_extraction_.setMaxRange(max_range);
		min_split_dist= this->get_parameter("min_split_dist").as_double();
		RCLCPP_DEBUG(get_logger(), "Min split distance %f",min_split_dist);
		line_extraction_.setMinSplitDist(min_split_dist);
		outlier_dist= this->get_parameter("outlier_dist").as_double();
		RCLCPP_DEBUG(get_logger(), "Outlier distance %f",outlier_dist);
		line_extraction_.setOutlierDist(outlier_dist);
		min_line_points= this->get_parameter("min_line_points").as_int();
		RCLCPP_DEBUG(get_logger(), "Min line points %d",min_line_points);
		line_extraction_.setMinLinePoints(static_cast<unsigned int>(min_line_points));
		
        laser_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            scan_topic, qos_profile, std::bind(&LaserLineExtraction::scan_callback, this, std::placeholders::_1));

        // Publicador de los segmentos de laser
		line_publisher_=this->create_publisher<laser_line_extraction::msg::LineSegmentList>("line_segments",1);
		
		if (pub_markers_)
		  {
			marker_publisher_ = this->create_publisher<visualization_msgs::msg::Marker>("line_markers", 1);
		  }
    }

private:

	void add_parameter(const std::string & name, const rclcpp::ParameterValue & default_value,
    const std::string & description= "", const std::string & additional_constraints= "", bool read_only= "")
	{
		auto descriptor = rcl_interfaces::msg::ParameterDescriptor();

		descriptor.name = name;
		descriptor.description = description;
		descriptor.additional_constraints = additional_constraints;
		descriptor.read_only = read_only;

		declare_parameter(descriptor.name, default_value, descriptor);
	}
	
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr scan_msg) {
		
		if (!data_cached_)
		{
			cacheData(scan_msg); 
			data_cached_ = true;
		}	
		std::vector<Line> lines;
		std::vector<double> ranges(scan_msg->ranges.begin(), scan_msg->ranges.end());
		line_extraction_.setRangeData(ranges);
		line_extraction_.extractLines(lines);
		
		// Populate message
		laser_line_extraction::msg::LineSegmentList msg;
		populateLineSegListMsg(lines,msg);

		// Publish the lines
		line_publisher_->publish(msg);

		// Also publish markers if parameter publish_markers is set to true
		if (pub_markers_)
		{
		visualization_msgs::msg::Marker marker_msg;
		populateMarkerMsg(lines, marker_msg);
		marker_publisher_->publish(marker_msg);
		}
		
    }
	
	///////////////////////////////////////////////////////////////////////////////
// Populate messages
///////////////////////////////////////////////////////////////////////////////
void populateLineSegListMsg(const std::vector<Line> &lines, laser_line_extraction::msg::LineSegmentList &line_list_msg)
{
  for (std::vector<Line>::const_iterator cit = lines.begin(); cit != lines.end(); ++cit)
  {
    laser_line_extraction::msg::LineSegment line_msg;
    line_msg.angle.data = cit->getAngle(); 
    line_msg.radius.data = cit->getRadius(); 
	boost::array<double, 4> cov = cit->getCovariance(); 
	for (int i=0;i<4;i++)
		line_msg.covariance[i].data=cov[i];
	boost::array<double, 2> s = cit->getStart();
	boost::array<double, 2> e = cit->getEnd();
	for (int i=0;i<2;i++)
	{
		line_msg.start[i].data=s[i];
		line_msg.end[i].data=e[i];
	}
    line_list_msg.line_segments.push_back(line_msg);
  }
  line_list_msg.header.frame_id = frame_id_;
  line_list_msg.header.stamp = this->get_clock()->now();
}

void populateMarkerMsg(const std::vector<Line> &lines, visualization_msgs::msg::Marker &marker_msg)
{
  marker_msg.ns = "line_extraction";
  marker_msg.id = 0;
  marker_msg.type = visualization_msgs::msg::Marker::LINE_LIST;
  marker_msg.scale.x = 0.1;
  marker_msg.color.r = 1.0;
  marker_msg.color.g = 0.0;
  marker_msg.color.b = 0.0;
  marker_msg.color.a = 1.0;
  for (std::vector<Line>::const_iterator cit = lines.begin(); cit != lines.end(); ++cit)
  {
    geometry_msgs::msg::Point p_start;
    p_start.x = cit->getStart()[0];
    p_start.y = cit->getStart()[1];
    p_start.z = 0;
    marker_msg.points.push_back(p_start);
    geometry_msgs::msg::Point p_end;
    p_end.x = cit->getEnd()[0];
    p_end.y = cit->getEnd()[1];
    p_end.z = 0;
    marker_msg.points.push_back(p_end);
  }
  marker_msg.header.frame_id = frame_id_;
  marker_msg.header.stamp = this->get_clock()->now();
}

///////////////////////////////////////////////////////////////////////////////
// Cache data on first LaserScan message received
///////////////////////////////////////////////////////////////////////////////
void cacheData(const sensor_msgs::msg::LaserScan::SharedPtr scan_msg)
{
  std::vector<double> bearings, cos_bearings, sin_bearings;
  std::vector<unsigned int> indices;
  const std::size_t num_measurements = std::ceil(
      (scan_msg->angle_max - scan_msg->angle_min) / scan_msg->angle_increment);
  for (std::size_t i = 0; i < num_measurements; ++i)
  {
    const double b = scan_msg->angle_min + i * scan_msg->angle_increment;
    bearings.push_back(b);
    cos_bearings.push_back(cos(b));
    sin_bearings.push_back(sin(b));
    indices.push_back(i);
  }

  line_extraction_.setCachedData(bearings, cos_bearings, sin_bearings, indices);
  //ROS_DEBUG("Data has been cached.");
}
    
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub_;
	rclcpp::Publisher<laser_line_extraction::msg::LineSegmentList>::SharedPtr line_publisher_;
	rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_publisher_;
    std::string frame_id_;
	
	bool pub_markers_;
	// Line extraction
	LineExtraction line_extraction_;
	bool data_cached_; // true after first scan used to cache data

};

}

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<line_extraction::LaserLineExtraction>());
    rclcpp::shutdown();
    return 0;
}
