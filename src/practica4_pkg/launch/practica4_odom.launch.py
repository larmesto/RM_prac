from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument,GroupAction

def generate_launch_description():

    frame_id = LaunchConfiguration('frame_id')
    publish_tf = LaunchConfiguration('publish_tf')

    declare_frame_id_cmd = DeclareLaunchArgument(
        'frame_id',
        default_value='odom',
        description='Frame to refer the pointcloud'
    )  

    declare_publish_tf_cmd = DeclareLaunchArgument(
        'publish_tf',
        default_value='true',
        description='Set true to publish scm_odom frame related to odom frame on tf topic'
    )

    actions=[

        declare_frame_id_cmd,
        declare_publish_tf_cmd,

        Node(
            package='practica4_pkg',
            executable='map_pointcloud_node',
            name='map_pointcloud_node',
            output='screen',
            parameters=[{'frame_id': frame_id}]
        ),
    ]

    scan_cmd_group = GroupAction(actions)

    ld = LaunchDescription()
    ld.add_action(scan_cmd_group)

    return ld
