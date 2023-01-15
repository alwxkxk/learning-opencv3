#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
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
    Mat image, image_blur3, image_blur5, image_blur9, image_blur11, image_blur5_double;
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if (image.empty()) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        getchar();
        return -1;
    }
    
    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", image); 

    blur(image, image_blur3, Size(3, 3));
    namedWindow("image_blur3", WINDOW_AUTOSIZE);
    imshow("image_blur3", image_blur3);

    blur(image, image_blur5, Size(5, 5));
    namedWindow("image_blur5", WINDOW_AUTOSIZE);
    imshow("image_blur5", image_blur5);

    blur(image_blur5, image_blur5_double, Size(5, 5));
    namedWindow("image_blur5_double", WINDOW_AUTOSIZE);
    imshow("image_blur5_double", image_blur5_double);

    blur(image, image_blur9, Size(9, 9));
    namedWindow("image_blur9", WINDOW_AUTOSIZE);
    imshow("image_blur9", image_blur9);

    blur(image, image_blur11, Size(11, 11));
    namedWindow("image_blur11", WINDOW_AUTOSIZE);
    imshow("image_blur11", image_blur11);
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}