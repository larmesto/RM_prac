import os

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument,GroupAction
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():

    path_file = LaunchConfiguration('path_file')

    declare_path_file_cmd = DeclareLaunchArgument(
        'path_file',
        default_value=os.path.join(
            get_package_share_directory('pure_pursuit_controller_pkg'),
            'config','path.yaml'),
            description='To select the amount of points to define the trajectory')

    actions=[

        declare_path_file_cmd,

        Node(
            package='pure_pursuit_controller_pkg',
            executable='waypoints_node',
            name='waypoints_node',
            output='screen',
            parameters=[{'path_file': path_file}],
        ),

        Node(
            package='pure_pursuit_controller_pkg',
            executable='pure_pursuit_odom',
            name='pure_pursuit_odom',
            output='screen',
        ),
    ]

    pure_pursuit_controller_cmd_group = GroupAction(actions)

    ld = LaunchDescription()
    ld.add_action(pure_pursuit_controller_cmd_group)

    return ld