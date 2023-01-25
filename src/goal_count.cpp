#include <ros/ros.h>
#include <follow_goal/GoalNumber.h>
#include "assignment_2_2022/PlanningActionResult.h"

using namespace std;

//global variables for status and number of goals reached and deleted
int status;
int reached_goal=0, deleted_goal=0;


/*#############################################
# 
# Get number of reached and deleted goals
# Send information on custom service result
# 
##############################################*/
bool goal_service_callback(follow_goal::GoalNumber::Request &req, follow_goal::GoalNumber::Response &res) {
	res.reached = reached_goal;
	res.deleted = deleted_goal;
	return true;
}


/*#############################################
# 
# Counts goals reached and deleted
# 
##############################################*/
void count_reach_delete_callback(const assignment_2_2022::PlanningActionResult::ConstPtr& msg) {
	
	status=msg->status.status;
	ROS_INFO("\nStatus goal:%d", status);
	
	// check if the current goal is succeeded
	if (status==3) 
		reached_goal++;
	
	// check if the current goal is preemptive
	else if (status==2) 
		deleted_goal++;
}


/*#############################################
# 
# Manage ROS init, NodeHandle, subscriber 
# and service
# 
##############################################*/
int main (int argc, char** argv) {
	
	//init
	ros::init(argc, argv, "goal_count");
	
	// NodeHandle is the main access point to communications with the ROS system
	ros::NodeHandle n;
	
	// Subscriber
	ros::Subscriber sub = n.subscribe("/reaching_goal/result", 1, count_reach_delete_callback);
	
	// Service
	ros::ServiceServer service = n.advertiseService("/result", goal_service_callback);
	
	sleep(1);
	ros::spin();
	return 0;
	
}

