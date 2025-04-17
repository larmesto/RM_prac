import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import IncludeLaunchDescription
from launch.actions import DeclareLaunchArgument,GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    frame_id = LaunchConfiguration('frame_id')
    scan_topic = LaunchConfiguration('scan_topic')
    publish_markers = LaunchConfiguration('publish_markers')
    bearing_std_dev = LaunchConfiguration('bearing_std_dev')
    range_std_dev = LaunchConfiguration('range_std_dev')
    least_sq_angle_thresh = LaunchConfiguration('least_sq_angle_thresh')
    least_sq_radius_thresh = LaunchConfiguration('least_sq_radius_thresh')
    max_line_gap = LaunchConfiguration('max_line_gap')
    min_line_length = LaunchConfiguration('min_line_length')
    min_range = LaunchConfiguration('min_range')
    max_range = LaunchConfiguration('max_range')
    min_split_dist = LaunchConfiguration('min_split_dist')
    outlier_dist = LaunchConfiguration('outlier_dist')
    min_line_points = LaunchConfiguration('min_line_points')

    declare_frame_id_cmd = DeclareLaunchArgument(
        'frame_id',
        default_value='base_scan',
        description='Frame to refer the line segments'
    )  

    declare_scan_topic_cmd = DeclareLaunchArgument(
        'scan_topic',
        default_value='scan',
        description='Laser scan topic name'
    )
    
    declare_publish_markers_cmd = DeclareLaunchArgument(
        'publish_markers',
        default_value='true',
        description='If true, publish markers topic'
    )
    
    declare_bearing_std_dev_cmd = DeclareLaunchArgument(
        'bearing_std_dev',
        default_value='1e-5',
        description=''
    )
    
    declare_range_std_dev_cmd = DeclareLaunchArgument(
        'range_std_dev',
        default_value='0.012',
        description=''
    )
    
    declare_least_sq_angle_thresh_cmd = DeclareLaunchArgument(
        'least_sq_angle_thresh',
        default_value='0.0001',
        description=''
    )
    
    declare_least_sq_radius_thresh_cmd = DeclareLaunchArgument(
        'least_sq_radius_thresh',
        default_value='0.0001',
        description=''
    )
    
    declare_max_line_gap_cmd = DeclareLaunchArgument(
        'max_line_gap',
        default_value='0.35',
        description=''
    )
    
    declare_min_line_length_cmd = DeclareLaunchArgument(
        'min_line_length',
        default_value='0.5',
        description=''
    )
    
    declare_min_range_cmd = DeclareLaunchArgument(
        'min_range',
        default_value='0.25',
        description=''
    )
    
    declare_max_range_cmd = DeclareLaunchArgument(
        'max_range',
        default_value='100.0',
        description=''
    )
    
    declare_min_split_dist_cmd = DeclareLaunchArgument(
        'min_split_dist',
        default_value='0.04',
        description=''
    )
    
    declare_outlier_dist_cmd = DeclareLaunchArgument(
        'outlier_dist',
        default_value='0.06',
        description=''
    )
    
    declare_min_line_points_cmd = DeclareLaunchArgument(
        'min_line_points',
        default_value='8',
        description=''
    )

    actions=[
        declare_frame_id_cmd,
        declare_scan_topic_cmd,
        declare_publish_markers_cmd,
        declare_bearing_std_dev_cmd,
        declare_range_std_dev_cmd,
        declare_least_sq_angle_thresh_cmd,
        declare_least_sq_radius_thresh_cmd,
        declare_max_line_gap_cmd,
        declare_min_line_length_cmd,
        declare_min_range_cmd,
        declare_max_range_cmd,
        declare_min_split_dist_cmd,
        declare_outlier_dist_cmd,
        declare_min_line_points_cmd,
        Node(
            package='laser_line_extraction',
            executable='line_extraction_node',
            name='line_extractor',
            output='screen',
            parameters=[{'frame_id': frame_id,'scan_topic': scan_topic, 'publish_markers' : publish_markers, 'bearing_std_dev': bearing_std_dev, 'range_std_dev': range_std_dev, 'least_sq_angle_thresh': least_sq_angle_thresh, 'least_sq_radius_thresh': least_sq_radius_thresh, 'max_line_gap': max_line_gap, 'min_line_length': min_line_length, 'min_range': min_range, 'max_range': max_range, 'min_split_dist': min_split_dist, 'outlier_dist': outlier_dist, 'min_line_points': min_line_points}]
        ),
    ]

    cmd_group = GroupAction(actions)

    ld = LaunchDescription()
    ld.add_action(cmd_group)

    return ld