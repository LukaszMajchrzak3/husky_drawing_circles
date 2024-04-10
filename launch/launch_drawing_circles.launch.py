from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Declare a launch argument for the parameter value
    my_parameter = DeclareLaunchArgument('my_parameter', default_value='0.0')  # Use a string for the argument name
    ang_velocity = DeclareLaunchArgument('ang_velocity', default_value='0.0') 
    run_the_code = DeclareLaunchArgument('run_the_code', default_value='false')

    # Define the node and pass the parameter as a command-line argument
    my_node = Node(
        package='drawing_circles',
        executable='dr_circles_node',
        name='dr_circles_node',
        parameters=[{'my_parameter': LaunchConfiguration('my_parameter')},
        {'run_the_code': LaunchConfiguration('run_the_code')},
        {'ang_velocity': LaunchConfiguration('ang_velocity')}]
    )


    # Create a LaunchDescription and add the nodes and launch arguments
    return LaunchDescription([
        my_parameter,
        ang_velocity,
        run_the_code,
        my_node
    ])
