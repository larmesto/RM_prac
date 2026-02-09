#!/usr/bin/env python3

from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import GroupAction



def generate_launch_description():   

    #Acciones a llevar a cabo por el launch
    actions = [ 
        
        Node(
            package='intro_ros_pkg',
            executable='publisher',
            name='publisher1',
            output='screen',
            remappings=[{'/topic_pose','/pose1'}] 
            
        ),
        Node(
            package='intro_ros_pkg',
            executable='publisher',
            name='publisher2',
            output='screen',
            remappings=[{'/topic_pose','/pose2'}] 

        ),
    ]

    intro_ros_cmd_group = GroupAction(actions)

    ld = LaunchDescription()

    ld.add_action(intro_ros_cmd_group)

    return ld
