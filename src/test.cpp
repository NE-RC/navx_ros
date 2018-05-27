#include <iostream>
#include "AHRS.h"
#include "ros/ros.h"

int main(int argc, char **argv)
{

	ros::init(argc, argv, "navX");

	ros::NodeHandle nh;
	

	AHRS com = AHRS("/dev/ttyACM0");
	while (true){
		float vx = com.GetVelocityX();
		float vy = com.GetVelocityY();
		float vz = com.GetVelocityZ();
		std::cout << vx << " " << vy << " " << vz << std::endl;
	}
	return 0;
}
