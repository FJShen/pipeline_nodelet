#ifndef PIPELINE_NODELET__MI_NODES_H_
#define PIPELINE_NODELET__MI_NODES_H_

#include "ros/ros.h"
#include "helper.h"
#include <iostream>
#include <nodelet/nodelet.h>
#include "std_msgs/UInt8.h"

namespace pipeline_nodelet{

    class Level1 : public nodelet::Nodelet{
    public:
	virtual void onInit(){
	    ros::NodeHandle& n = getPrivateNodeHandle();
	    pub = n.advertise<std_msgs::UInt8>("pipe_l1_output", 5);
	    ROS_INFO("Level1 node created\n");
	    timer = n.createTimer(ros::Duration(0.25), &Level1::timerCallback, this);
	};

    private:
	ros::Publisher pub;
	ros::Timer timer;
	unsigned char count=0;
	void timerCallback(const ros::TimerEvent& event){
	    ROS_INFO("timeout triggered\n");
	    std_msgs::UInt8 msg;
	    msg.data = count;
	    pub.publish(msg);
	    count+=1;
	}
    };
    
}


#endif
