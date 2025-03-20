#!/usr/bin/env python3

from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import GroupAction



def generate_launch_description():   

    #Acciones a llevar a cabo por el launch
    actions = [ 
        
        Node(
            package='practica1_pkg',
            executable='publisher',
            name='publisher_pose',
            output='screen', 
        ),
        Node(
            package='practica1_pkg',
            executable='subscriber',
            name='subscriber_pose',
            output='screen', 
        ),
    ]

    practica1_cmd_group = GroupAction(actions)

    ld = LaunchDescription()

    ld.add_action(practica1_cmd_group)

    return ld
