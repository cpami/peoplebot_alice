#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

int main(int argc, char* argv[])
{
	ros::init(argc,argv,"camera_node");
	ros::NodeHandle nh;
	image_transport::ImageTransport imgT(nh);
	image_transport::Publisher pubz = imgT.advertise("camera/image",1);
	ROS_INFO("Opening Camera \n");
	cv::VideoCapture camera(0);
	if (!camera.isOpened())
	{
		ROS_INFO("Failed to open camera");
		return -1;
	}
	else
	{
		ROS_INFO("Camera Opened \n");
	}
	cv::Mat image;
	ros::Rate fps(30);
	while(nh.ok())
	{
		camera >> image;
		cv::flip(image,image,-1);
		cv::waitKey(2);
		if (!image.empty())
		{
			std_msgs::Header header;
			header.frame_id="camera";
			sensor_msgs::ImagePtr msg = cv_bridge::CvImage(header,"bgr8", image).toImageMsg();
			pubz.publish(msg);
			cv::waitKey(1);
		}
		else
			ROS_INFO("can't read camera");
		ros::spinOnce();
		fps.sleep();
	}
}
