#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    
    //ノード初期化
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    //subscribeし，chatterCallback関数を呼ぶ
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    ros::spin();//spinすることで Callback関数を繰り返し呼ぶことができる



    return(0);
}
