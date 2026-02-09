#!/usr/bin/env python3

from launch_ros.actions import Node
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import GroupAction, DeclareLaunchArgument



def generate_launch_description():   

    pos_x = LaunchConfiguration('pos_x')
    pos_y = LaunchConfiguration('pos_y')
    pos_z = LaunchConfiguration('pos_z')

    declare_pos_x_cmd = DeclareLaunchArgument(
        'pos_x',
        default_value='0.0',
        description='Robot position in x axis')
    
    declare_pos_y_cmd = DeclareLaunchArgument(
        'pos_y',
        default_value='0.0',
        description='Robot position in x axis')
    
    declare_pos_z_cmd = DeclareLaunchArgument(
        'pos_z',
        default_value='0.0',
        description='Robot position in x axis')

    #Acciones a llevar a cabo por el launch
    actions = [

        declare_pos_x_cmd,
        declare_pos_y_cmd,
        declare_pos_z_cmd,

        Node(
            package='intro_ros_pkg',
            executable='publisher',
            name='publisher_pose',
            output='screen',
            parameters=[{'pos_x': pos_x},
                        {'pos_y': pos_y},
                        {'pos_z': pos_z}] 
        ),

        Node(
            package='intro_ros_pkg',
            executable='subscriber',
            name='subscriber_pose',
            output='screen', 
        ),
    ]

    intro_ros_cmd_group = GroupAction(actions)

    ld = LaunchDescription()
    ld.add_action(intro_ros_cmd_group)
    

    return ld
