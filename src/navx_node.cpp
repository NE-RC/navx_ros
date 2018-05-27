#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "sensor_msgs/Imu.h"
#include <AHRS.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "navx_node");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<sensor_msgs::Imu>("Imu", 10);
	ros::Rate period(100);

	AHRS navx = AHRS("/dev/ttyACM0");

	while(ros::ok()){
		sensor_msgs::Imu imu;		

		//orientation
		imu.orientation.x = navx.GetQuaternionX();
		imu.orientation.y = navx.GetQuaternionY();
		imu.orientation.z = navx.GetQuaternionZ();
		imu.orientation.w = navx.GetQuaternionW();

		//angular velocity

		//linear acceleration
		imu.linear_acceleration.x = navx.GetWorldLinearAccelX();
		imu.linear_acceleration.y = navx.GetWorldLinearAccelY();
		imu.linear_acceleration.z = navx.GetWorldLinearAccelZ();
		

		pub.publish(imu);
		ros::spinOnce();
		period.sleep();
	}
	return 0;
}
