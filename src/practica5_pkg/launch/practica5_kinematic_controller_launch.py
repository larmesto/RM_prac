from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument,GroupAction

def generate_launch_description():

    actions=[

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