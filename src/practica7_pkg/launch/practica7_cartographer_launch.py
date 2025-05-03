import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction,
                            IncludeLaunchDescription)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Get the launch directory
    coppeliasim_pkg = get_package_share_directory('turtlebot3_coppeliasim')
    coppeliasim_dir = os.path.join(coppeliasim_pkg, 'launch')

    cartographer_pkg = get_package_share_directory('turtlebot3_cartographer')
    cartographer_dir = os.path.join(cartographer_pkg, 'launch')

    # Arguments
    resolution = LaunchConfiguration('resolution')

    declare_resolution_cmd = DeclareLaunchArgument(
        'resolution',
        default_value='0.05',)

    # Specify the actions
    cartographer_cmd = GroupAction([
        
        declare_resolution_cmd,

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(coppeliasim_dir, 'turtlebot3_coppeliasim_no_rviz2.launch.py')),
            ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(cartographer_dir,'cartographer.launch.py')),
            launch_arguments={'resolution': resolution}.items()
           ),
    ])

    # Create the launch description and populate
    ld = LaunchDescription()

    # Add the actions to launch all of the navigation nodes
    ld.add_action(cartographer_cmd)

    return ld