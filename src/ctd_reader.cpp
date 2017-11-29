#include "ros/ros.h"
#include "std_msgs/String.h"


void dataCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Temperature is: %s degC", msg->data.c_str());
}



int main(int argc, char **argv)
{
  ros::init(argc, argv, "ctd_reader");

  ros::NodeHandle n;

  //subscribe
  ros::Subscriber sub = n.subscribe("ctddata", 1000, dataCallback);

  ros::spin();

  return 0;
}
