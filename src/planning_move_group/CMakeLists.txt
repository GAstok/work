cmake_minimum_required(VERSION 2.8.3)
project(planning_move_group)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rosmsg
  rospy
  tf2_eigen


  moveit_visual_tools
  moveit_ros_planning
  moveit_ros_planning_interface
  geometric_shapes
  tf2_ros
  tf2_geometry_msgs
)

# find_package(Eigen REQUIRED)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES planning_move_group
#  CATKIN_DEPENDS roscpp rosmsg rospy
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/planning_move_group.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(planning_node src/planning_tutorial.cpp)

target_link_libraries(planning_node ${catkin_LIBRARIES} ${Boost_LIBRARIES} )
