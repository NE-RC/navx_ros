cmake_minimum_required(VERSION 2.8.3)
project(navx_ros)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

###########
## Build ##
###########

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  navXTimeSync
)

set (NAVX_SRCS
	navXTimeSync/AHRS.cpp
	navXTimeSync/ContinuousAngleTracker.cpp
	navXTimeSync/InertialDataIntegrator.cpp
	navXTimeSync/OffsetTracker.cpp
	navXTimeSync/SerialIO.cpp
	navXTimeSync/SerialPort.cpp )

add_executable(navx_node src/test.cpp ${NAVX_SRC})
target_link_libraries(navx_node ${catkin_LIBRARIES})
