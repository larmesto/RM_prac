import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction,
                            IncludeLaunchDescription, ExecuteProcess)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch.substitutions import PathJoinSubstitution
from launch.conditions import IfCondition
from launch_ros.actions import Node


def generate_launch_description():
    # Get directories
    navigation_pkg = get_package_share_directory('nav2_bringup')
    localization_dir = os.path.join(navigation_pkg, 'launch')

    rviz_dir = LaunchConfiguration(
        'rviz_dir',
        default=os.path.join(
            get_package_share_directory('ros2_vfh'), 'launch'))

    # -------------------------
    # Launch configurations
    # -------------------------
    map = LaunchConfiguration('map')

    m_cell_size = LaunchConfiguration('m_cell_size')
    m_window_diameter = LaunchConfiguration('m_window_diameter')
    sectors_number = LaunchConfiguration('sectors_number')
    use_amcl = LaunchConfiguration('use_amcl')
    wandering_mode = LaunchConfiguration('wandering_mode')
    pub_cmd_vel = LaunchConfiguration('pub_cmd_vel')

    # -------------------------
    # Declare arguments
    # -------------------------
    declare_map_cmd = DeclareLaunchArgument(
        'map',
        default_value=''
    )

    declare_cell_size_cmd = DeclareLaunchArgument(
        'm_cell_size',
        default_value='0.05'
    )

    declare_window_cmd = DeclareLaunchArgument(
        'm_window_diameter',
        default_value='45'
    )

    declare_sectors_cmd = DeclareLaunchArgument(
        'sectors_number',
        default_value='72'
    )

    declare_use_amcl_cmd = DeclareLaunchArgument(
        'use_amcl',
        default_value='False'
    )

    declare_wandering_mode_cmd = DeclareLaunchArgument(
        'wandering_mode',
        default_value='False'
    )

    declare_pub_cmd_vel_cmd = DeclareLaunchArgument(
        'pub_cmd_vel',
        default_value='True'
    )

    # -------------------------
    # Actions
    # -------------------------
    vfh_cmd = GroupAction([

        declare_map_cmd,
        declare_cell_size_cmd,
        declare_window_cmd,
        declare_sectors_cmd,
        declare_use_amcl_cmd,
        declare_wandering_mode_cmd,
        declare_pub_cmd_vel_cmd,


        # Solo publicar initialpose si AMCL está activo
        ExecuteProcess(
            condition=IfCondition(use_amcl),
            cmd=[['ros2 topic pub --once /initialpose geometry_msgs/msg/PoseWithCovarianceStamped """{header: {frame_id: """map"""}, pose: {pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}},covariance: [0.01,0.0,0.0,0.0,0.0,0.0,0.0,0.01,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0076]} }"""']],
            shell=True,
        ),


        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([rviz_dir, 'rviz2_map.launch.py'])
                ),
                condition=IfCondition(use_amcl),
        ),


        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([rviz_dir, 'rviz2_odom.launch.py'])
                ),
                condition=IfCondition(PythonExpression(['not ', use_amcl])),

        ),


        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(localization_dir, 'localization_launch.py')),
            launch_arguments={'map': map}.items(),
            condition=IfCondition(use_amcl),
        ),

        # Nodo AMCL (también condicionado)
        Node(
            package='slam_pkg',
            executable='amcl_odom',
            name='amcl_odom',
            output='screen',
            condition=IfCondition(use_amcl),
        ),

        Node(
            package='ros2_vfh',
            executable='vfh_node',
            name='vfh_node',
            parameters=[{
                'm_cell_size': m_cell_size,
                'm_window_diameter': m_window_diameter,
                'sectors_number': sectors_number,
                'use_amcl': use_amcl,
                'wandering_mode':wandering_mode,
                'pub_cmd_vel': pub_cmd_vel
            }],
            output='screen'
        ),
    ])

    ld = LaunchDescription()
    ld.add_action(vfh_cmd)

    return ld