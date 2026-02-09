import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction,
                            IncludeLaunchDescription, ExecuteProcess)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Get the launch directory

    localization_pkg = get_package_share_directory('nav2_bringup')
    localiation_dir = os.path.join(localization_pkg, 'launch')

    # Arguments
    map = LaunchConfiguration('map')

    declare_map_cmd = DeclareLaunchArgument(
        'map',
        default_value='',)

    # Specify the actions
    localization_cmd = GroupAction([

        ExecuteProcess(
            cmd=[['ros2 topic pub --once /initialpose geometry_msgs/msg/PoseWithCovarianceStamped """{header: {frame_id: """map"""}, pose: {pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}},covariance: [0.01,0.0,0.0,0.0,0.0,0.0,0.0,0.01,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0076]} }"""']],
            shell=True
        ),

        declare_map_cmd,

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(localiation_dir,'localization_launch.py')),
            launch_arguments={'map': map}.items()
           ),
        
        Node(
            package='slam_pkg',
            executable='amcl_odom',
            name='amcl_odom',
            output='screen',
        ),
    ])

    # Create the launch description and populate
    ld = LaunchDescription()

    # Add the actions to launch all of the navigation nodes
    ld.add_action(localization_cmd)

    return ld