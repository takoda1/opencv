#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
	Mat image;
image = imread("./1920px-Killerwhales_jumping.jpg", IMREAD_COLOR);

namedWindow("Display", WINDOW_AUTOSIZE);

imshow("Display", image);

waitKey(0);
return 0;
}
