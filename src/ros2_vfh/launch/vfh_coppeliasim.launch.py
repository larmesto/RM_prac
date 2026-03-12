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
    vfh_pkg = get_package_share_directory('ros2_vfh')
    vfh_dir = os.path.join(vfh_pkg, 'launch')
    
    coppeliasim_pkg = get_package_share_directory('turtlebot3_coppeliasim')
    coppeliasim_dir = os.path.join(coppeliasim_pkg, 'launch')
    
    # Specify the actions
    vfh_cmd = GroupAction([
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([vfh_dir, '/vfh.launch.py'])),
            
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([coppeliasim_dir, '/turtlebot3_coppeliasim_no_rviz2.launch.py'])),
    ])

    # Create the launch description and populate
    ld = LaunchDescription()

    # Add the actions to launch all of the navigation nodes
    ld.add_action(vfh_cmd)

    return ld