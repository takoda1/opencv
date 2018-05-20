// this program loads one input video file 
//and turns it into a special video with effects
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

using namespace cv;
using namespace std;

int main (int argc, char** argv) 
{ 
    if (argc > 2){
        cout << "Too many videos \n";
        return -1;
    }
    VideoCapture capture(argv[1]);
    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        capture >> frame; // get a new frame from camera
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}