#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "move_group_interface_tutorial");
	ros::NodeHandle node_handle;
	ros::AsyncSpinner spinner(1);
	spinner.start();

	static const std::string PLANNING_GROUP = "arm";
	moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
	moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
	const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);


	namespace rvt = rviz_visual_tools;
	moveit_visual_tools::MoveItVisualTools visual_tools("odom_combined");
	visual_tools.deleteAllMarkers();
	visual_tools.loadRemoteControl();
	Eigen::Affine3d text_pose = Eigen::Affine3d::Identity();
	text_pose.translation().z() = 1.75; // above head of PR2
	visual_tools.publishText(text_pose, "MoveGroupInterface Demo", rvt::WHITE, rvt::XLARGE);
	visual_tools.trigger();

	ROS_INFO_NAMED("tutorial", "Reference frame: %s",
	move_group.getPlanningFrame().c_str());
	ROS_INFO_NAMED("tutorial", "End effector link: %s",
	move_group.getEndEffectorLink().c_str());

	geometry_msgs::Pose target_pose1;
	target_pose1.orientation.w = 1.0;
	target_pose1.position.x = 0.28;
	target_pose1.position.y = -0.7;
	target_pose1.position.z = 1.0;
	move_group.setPoseTarget(target_pose1);
	moveit::planning_interface::MoveGroupInterface::Plan my_plan;

	bool success = move_group.plan(my_plan);
	
	ROS_INFO_NAMED("tutorial", "Visualizing plan 1 (pose goal) %s", success ? "" :"FAILED");

	ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");
	visual_tools.publishAxisLabeled(target_pose1, "pose1");
	visual_tools.publishText(text_pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
	visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
	visual_tools.trigger();
	visual_tools.prompt("next step");
	
	moveit::core::RobotStatePtr current_state = move_group.getCurrentState();
	std::vector<double> joint_group_positions;
	current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
	joint_group_positions[0] = -1.0; // radians
	move_group.setJointValueTarget(joint_group_positions);
	
	success = move_group.plan(my_plan);
	ROS_INFO_NAMED("tutorial", "Visualizing plan 2 (joint space goal) %s", success ? "" :
	"FAILED");
	visual_tools.deleteAllMarkers();
	visual_tools.publishText(text_pose, "Joint Space Goal", rvt::WHITE, rvt::XLARGE);
	visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
	visual_tools.trigger();
	visual_tools.prompt("next step");
	
	moveit_msgs::OrientationConstraint ocm;
	ocm.link_name = "r_wrist_roll_link";
	ocm.header.frame_id = "base_link";
	ocm.orientation.w = 1.0;
	ocm.absolute_x_axis_tolerance = 0.1;
	ocm.absolute_y_axis_tolerance = 0.1;
	ocm.absolute_z_axis_tolerance = 0.1;
	ocm.weight = 1.0;
	moveit_msgs::Constraints test_constraints;
	test_constraints.orientation_constraints.push_back(ocm);
	move_group.setPathConstraints(test_constraints);
	robot_state::RobotState start_state(*move_group.getCurrentState());
	geometry_msgs::Pose start_pose2;
	start_pose2.orientation.w = 1.0;
	start_pose2.position.x = 0.55;
	start_pose2.position.y = -0.05;
	start_pose2.position.z = 0.8;
	start_state.setFromIK(joint_model_group, start_pose2);
	move_group.setStartState(start_state);
	move_group.setPoseTarget(target_pose1);
	move_group.setPlanningTime(10.0);
	
	success = move_group.plan(my_plan);
	ROS_INFO_NAMED("tutorial", "Visualizing plan 3 (constraints) %s", success ? "" : "FAILED");


	visual_tools.deleteAllMarkers();
	visual_tools.publishAxisLabeled(start_pose2, "start");
	visual_tools.publishAxisLabeled(target_pose1, "goal");
	visual_tools.publishText(text_pose, "Constrained Goal", rvt::WHITE, rvt::XLARGE);
	visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
	visual_tools.trigger();
	visual_tools.prompt("next step");
	move_group.clearPathConstraints();


	ros::shutdown();
	return 0;
}
