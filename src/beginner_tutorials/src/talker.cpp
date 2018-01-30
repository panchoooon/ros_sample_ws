#include "ros/ros.h" //ROSの基本パッケージ 
#include "std_msgs/String.h" //

#include <sstream>

int main(int argc, char **argv)
{

    ros::init(argc, argv, "talker"); //ノード初期化. "ノード名"

    ros::NodeHandle n; //ノードを操作するのに必要


    //"chatter"というトピックに，std_msgs::StringString
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);
    
    //printf("talker.py!");

    ros::Rate loop_rate(10); //10回/1sでpublishする

    int count = 0;
    while (ros::ok())
    {
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world" << count;

        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);//msgを"chatter"topicとしてw実際にpublish

        ros::spinOnce();//callbackする時には必要.今回は必要ではない

        loop_rate.sleep();
        ++count;
    }

    return(0);

}

