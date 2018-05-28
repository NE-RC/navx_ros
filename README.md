# navx_ros

Creates a ROS node that publishes to IMU.msg. <br />
Based off of FRC Team 900's [repository](https://github.com/FRC900/navXTimeSync)

## Directions for installing

1) Clone this project to your catkin's workspace src folder
2) Navigate into navx_ros directory and run `git submodule init` and `git submodule update`

## Direction for testing/visualizing

1) Install rviz_imu_plugin: [roswiki](http://wiki.ros.org/rviz_imu_plugin), [github](https://github.com/ccny-ros-pkg/imu_tools)
2) Start the imu node (including roscore) and run `rosrun rviz rviz`
3) Navigate to the bottom left corner and click 'add' and scroll down and add `Imu` under the 'rviz_imu_plugin' folder
4) On the left Display panel, add the IMU topic (default should be `/Imu`) and change the 'Fixed Frame' variable to `imu`
5) Change the settings for the box, axes, and acceleration as needed
