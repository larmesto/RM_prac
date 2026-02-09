import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler, LogInfo, GroupAction, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.event_handlers import OnProcessStart
from ament_index_python.packages import get_package_share_directory

def launch_setup(context, *args, **kwargs):
    path_file = LaunchConfiguration('path_file').perform(context)

    pure_pursuit_node = Node(
        package='pure_pursuit_controller_pkg',
        executable='pure_pursuit_odom',
        name='pure_pursuit_odom',
        output='screen',
        remappings=[('/odom','/amcl_odom')]
    )

    waypoints_node = Node(
        package='pure_pursuit_controller_pkg',
        executable='waypoints_node',
        name='waypoints_node',
        output='screen',
        parameters=[{'path_file': path_file}],
        
    )

    return [
        pure_pursuit_node,
        RegisterEventHandler(
            OnProcessStart(
                target_action=pure_pursuit_node,
                on_start=[
                    LogInfo(msg='Controller ready, launching waypoints path'),
                    waypoints_node
                ]
            )
        )
    ]

def generate_launch_description():
    declare_path_file_cmd = DeclareLaunchArgument(
        'path_file',
        default_value=os.path.join(
            get_package_share_directory('pure_pursuit_controller_pkg'),
            'config', 'path.yaml'),
        description='To select the amount of points to define the trajectory'
    )

    return LaunchDescription([
        declare_path_file_cmd,
        OpaqueFunction(function=launch_setup)
    ])
