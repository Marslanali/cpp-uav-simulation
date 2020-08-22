//
// Author: Ori Novanda (cargmax-at-gmail.com)
//

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
 
class cannyEdge {

	ros::NodeHandle nh;
	image_transport::ImageTransport it;    
	image_transport::Subscriber imgSub; 
	image_transport::Publisher imgPub;
	image_transport::Publisher imgPubOverlay;

	void publishOpenCVImage(image_transport::Publisher pub, Mat img) {
		cv_bridge::CvImage imgBridge = cv_bridge::CvImage(std_msgs::Header(), sensor_msgs::image_encodings::RGB8, img);
		sensor_msgs::Image msg;
		imgBridge.toImageMsg(msg);
		pub.publish(msg);
	}

  public:
	cannyEdge() : it(nh) {
		imgSub = it.subscribe("/image_raw", 1, &cannyEdge::process, this);
		imgPub = it.advertise("/camera/canny_edge",1);
		imgPubOverlay = it.advertise("/camera/canny_edge_overlay",1);
	}
  
	void process(const sensor_msgs::ImageConstPtr& srcImg) {
		cv_bridge::CvImagePtr cv_ptr;
    		try {
			cv_ptr = cv_bridge::toCvCopy(srcImg, sensor_msgs::image_encodings::BGR8);
		}
		catch (cv_bridge::Exception& e) {
			ROS_ERROR("cv_bridge exception: %s", e.what());
			return;
		}

		int theshold1 = 50;
		int theshold2 = 100; 
		int kernelSize = 3;

		Mat img;
		cvtColor(cv_ptr->image, img, CV_BGR2GRAY);
		GaussianBlur(img, img, Size(3, 3), 0, 0);
      		Canny(img, img, theshold1, theshold2, kernelSize);
		cvtColor(img, img, CV_GRAY2BGR);

		publishOpenCVImage(imgPub, img);
		publishOpenCVImage(imgPubOverlay, img+cv_ptr->image);
	}
};

int main(int argc, char** argv) {
	ros::init(argc, argv, "canny edge node");
	cannyEdge worker;
	ros::spin();

	return 0;
}
