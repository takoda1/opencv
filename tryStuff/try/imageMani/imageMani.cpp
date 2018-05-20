#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main (int argc, char** argv)
{
    if ( argc > 2){
        cout << "too many picutures been passed through" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1],IMREAD_COLOR);

    if (image.empty()){
        cout << "this image could not be found" << endl;
        return -1;
    }
    namedWindow("Display windows",WINDOW_AUTOSIZE);
    imshow("Display window", image);
    waitKey(0);
    return 0;
}