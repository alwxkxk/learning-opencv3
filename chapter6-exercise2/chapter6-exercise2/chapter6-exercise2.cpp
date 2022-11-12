// Example 2-2. Same as Example 2-1 but employing the “using namespace” directive

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

void help(char** argv) {
	std::cout << "\n"
		<< "2.2: Like 2.1, but 'using namespace cv: \n"
		<< argv[0] << " <path/image>\n"
		<< "For example:\n"
		<< argv[0] << " ../fruits.jpg\n"
		<< std::endl;
}


int main(int argc, char** argv) {

	if (argc != 2) {
		help(argv);
		return 0;
	}

	Mat img = imread(argv[1], -1);
	Mat img2;

	if (img.empty()) return -1;
	// 使用cvtcolor 转换成灰阶图
	cvtColor(img,img2,COLOR_BGR2GRAY);

	namedWindow("Example 2-2", cv::WINDOW_AUTOSIZE);

	imshow("Example 2-2", img);

	namedWindow("Example 2-2-gray", cv::WINDOW_AUTOSIZE);

	imshow("Example 2-2-gray", img2);

	waitKey(0);

	destroyWindow("Example 2-2");
	destroyWindow("Example 2-2-gray");
}
