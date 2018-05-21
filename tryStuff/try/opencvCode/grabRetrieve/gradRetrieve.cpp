#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/video.hpp>

using namespace cv;
using namespace std;

int main (int argc, char** argv)
{
    if (argc > 2){
        throw "This program only accept one argument";
    }

    Mat frame;

    VideoCapture cap;
    cap.open(argv[1]);

    for (; ;){
        if (cap.grab()){
            cap.retrieve(frame);
        } else throw "This no image";

        namedWindow("show video",1);
        imshow("frame", frame);
        if (waitKey(30) >= 0) break;

    }
    return 0;
}