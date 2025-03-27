import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import IncludeLaunchDescription
from launch.actions import DeclareLaunchArgument,GroupAction
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    rviz_dir = LaunchConfiguration(
        'rviz_dir',
        default=os.path.join(
            get_package_share_directory('practica5_pkg'), 'launch'))

    actions=[
    
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([rviz_dir, '/rviz2.launch.py'])),

        Node(
            package='practica5_pkg',
            executable='infinite_reference_node',
            name='infinite_reference_node',
            output='screen',
        ),

        Node(
            package='practica5_pkg',
            executable='controller_odom',
            name='controller_odom',
            output='screen',
        ),
    ]

    kinematic_controller_cmd_group = GroupAction(actions)

    ld = LaunchDescription()
    ld.add_action(kinematic_controller_cmd_group)

    return ld