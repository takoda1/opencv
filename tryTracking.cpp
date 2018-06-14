#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

	RCVideoCapture video("./Moving Dot Motion Blur Test-QkWE94l-txI.mp4");

	if(!video.isOpened())
	{
		cout << "Could not read video file" << endl;
		return 1;
	}
	Mat frame;
	video.grab(1);
	
	return 0;
}