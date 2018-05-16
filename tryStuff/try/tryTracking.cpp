#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

	Ptr<TrackerKCF> tracker;

	tracker = TrackerKCF::create();

	VideoCapture video("./Super Negative Swimmers-aOmIk7Q4bBU.mkv");

	if(!video.isOpened())
	{
		cout << "Could not read video file" << endl;
		return 1;
	}
	Mat frame;
	video.read(frame);

	Rect2d bbox(900, 200, 500, 600);

	rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);

	namedWindow("Tracking", WINDOW_AUTOSIZE);
	imshow("Tracking", frame);

	tracker->init(frame, bbox);

	while(video.read(frame)){
		double timer = (double)getTickCount();

		bool ok = tracker->update(frame, bbox);

		float fps = getTickFrequency() / ((double)getTickCount() - timer);

		if(ok){
			rectangle(frame, bbox, Scalar(255, 0, 0), 2, 1);
		}
		else{
			waitKey(0);
			break;
		}

		imshow("Tracking", frame);

		int k = waitKey(1);
		if(k == 27){
			break;
		}
	}
	return 0;
}