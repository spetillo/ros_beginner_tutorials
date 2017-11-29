#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ctd_sim");

  ros::NodeHandle n;

  ros::Publisher ctd_pub = n.advertise<std_msgs::String>("ctddata", 1000);

   ros::Rate loop_rate(10);

   int count = 0;
   int T0 = 15;
  while (ros::ok())
  {
    //This is a message object. You stuff it with data, and then publish it.
    std_msgs::String msg;

    std::stringstream ss;
    
    if (T0 <= 21)
      {
	ss << "T = "<<T0 <<" degC";
	T0++;
	if (T0 == 21)
	  {
	    T0=15;
	  }
      }
    else
      {
	
	ss << "T = "<<T0 <<" degC";
	T0--;
      }
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    // Publish
    ctd_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    ++count;
  }


  return 0; 
}
