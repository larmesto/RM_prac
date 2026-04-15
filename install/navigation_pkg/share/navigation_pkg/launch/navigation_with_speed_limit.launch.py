import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction,
                            IncludeLaunchDescription, ExecuteProcess)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Get the launch directory
    navigation_pkg = get_package_share_directory('turtlebot3_navigation2')
    navigation_dir = os.path.join(navigation_pkg, 'launch')

    # Arguments
    map = LaunchConfiguration('map')
    params_file = LaunchConfiguration('params_file')

    declare_map_cmd = DeclareLaunchArgument(
        'map',
        default_value='',)
    
    declare_params_file_cmd = DeclareLaunchArgument(
        'params_file',
        default_value='',)

    # Specify the actions
    localization_cmd = GroupAction([

        ExecuteProcess(
            cmd=[['ros2 topic pub --once /initialpose geometry_msgs/msg/PoseWithCovarianceStamped """{header: {frame_id: """map"""}, pose: {pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}},covariance: [0.01,0.0,0.0,0.0,0.0,0.0,0.0,0.01,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0076]} }"""']],
            shell=True
        ),

        declare_map_cmd,

        declare_params_file_cmd,

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(navigation_dir,'navigation2.launch.py')),
            launch_arguments={'map': map,
                              'params_file':params_file}.items()
           ),
    ])

    # Create the launch description and populate
    ld = LaunchDescription()

    # Add the actions to launch all of the navigation nodes
    ld.add_action(localization_cmd)

    return ld