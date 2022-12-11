#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << " Usage: " << argv[0] << " ImageToLoadAndDisplay" << endl;
        return -1;
    }
    Mat image,gray_img,solbe_x_img, solbe_x_show_img, solbe_y_img, solbe_y_show_img,solbe_show_img;
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if (image.empty()) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    // 先转成灰度图
    cvtColor(image,gray_img,COLOR_RGB2GRAY);

    Sobel(gray_img, solbe_x_img, CV_16S,1,0);
    Sobel(gray_img, solbe_y_img, CV_16S, 0, 1);

    convertScaleAbs(solbe_x_img, solbe_x_show_img);
    convertScaleAbs(solbe_y_img, solbe_y_show_img);

    addWeighted(solbe_x_show_img, 0.5, solbe_y_show_img, 0.5, 1,solbe_show_img);



    namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("Display window", image); // Show our image inside it.
    namedWindow("gray_img", WINDOW_AUTOSIZE);
    imshow("gray_img", gray_img);
    namedWindow("solbe_x_show_img", WINDOW_AUTOSIZE);
    imshow("solbe_x_show_img", solbe_x_show_img);
    namedWindow("solbe_y_show_img", WINDOW_AUTOSIZE);
    imshow("solbe_y_show_img", solbe_y_show_img);
    namedWindow("solbe_show_img", WINDOW_AUTOSIZE);
    imshow("solbe_show_img", solbe_show_img);

    waitKey(0); // Wait for a keystroke in the window
    return 0;
}