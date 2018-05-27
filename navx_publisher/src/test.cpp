#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <AHRS.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "test");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::Float32>("test", 1000);
	ros::Rate period(10);

	while(ros::ok()){
		std_msgs::Float32 msg;		
		msg.data = 3256;
		pub.publish(msg);
		ros::spinOnce();
		period.sleep();
	}
	return 0;
}
