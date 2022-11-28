#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int threshold1 = 10, threshold2 = 100;
int apertureSize=3;// 1,3,5,7
bool l2gradient = true;
Mat image, imageOut;

void on_trackbar(int, void*) {
    cout << "threshold1:" << threshold1 << ",threshold2:" << threshold2<< ",l2gradient:"<< l2gradient << endl;
    Canny(image, imageOut, threshold1, threshold2, apertureSize, l2gradient);
    imshow("Display window2", imageOut); // Show our image inside it.

}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << " Usage: " << argv[0] << " ImageToLoadAndDisplay" << endl;
        return -1;
    }

    
    
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if (image.empty()) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    namedWindow("Display window", WINDOW_GUI_EXPANDED); // Create a window for display.
    namedWindow("Display window2", WINDOW_GUI_EXPANDED);
    imshow("Display window", image); // Show our image inside it.
    Canny(image, imageOut, threshold1, threshold2, apertureSize, l2gradient);
    imshow("Display window2", imageOut); // Show our image inside it.

    createTrackbar("threshold1", "Display window", &threshold1, 1000, on_trackbar);
    createTrackbar("threshold2", "Display window", &threshold2, 1000, on_trackbar);

    waitKey(0); // Wait for a keystroke in the window
    return 0;
}