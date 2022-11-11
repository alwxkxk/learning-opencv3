
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std::chrono;

//C++(标准库):10---Clock和Timer（chrono库）
// https://blog.csdn.net/qq_41453285/article/details/105464872


void help(char** argv) {
	std::cout << "\n"
		<< "\nexample 2-10. The same object can load videos from a camera or a file"
		<< "\nCall:\n"
		<< argv[0] << " [path/image]\n"
		<< "\nor, read from camera:\n"
		<< argv[0]
		<< "\nFor example:\n"
		<< argv[0] << " ../tree.avi\n"
		<< std::endl;
}


int main(int argc, char** argv) {

	help(argv);



	cv::namedWindow("Example 2-10", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	

	if (argc == 1) {
		cap.open(0); // open the first camera
	}
	else {
		cap.open(argv[1]);
	}

	if (!cap.isOpened()) { // check if we succeeded
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	cv::Mat frame;
	double currentFrame;
	double currentTime;

	steady_clock::time_point now = steady_clock::now();
	steady_clock::time_point t1 = steady_clock::now();

	for (;;) {
		//
		cap >> frame;

		if (frame.empty()) break; // Ran out of film
		// 计算fps
		steady_clock::time_point t2 = steady_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - now);
		duration<double> time_tick = duration_cast<duration<double>>(t2 - t1);

		t1 = steady_clock::now();
		// 总用时
		cv::putText(
			frame,
			std::to_string(time_span.count()),
			cv::Point(16,48),
			cv::FONT_HERSHEY_COMPLEX,
			1,
			cv::Scalar(0,0,255)
		);
		// FPS
		cv::putText(
			frame,
			"FPS:"+std::to_string(1 / time_tick.count()),
			cv::Point(16, 96),
			cv::FONT_HERSHEY_COMPLEX,
			1,
			cv::Scalar(0, 0, 255)
		);

		cv::imshow("Example 2-10", frame);
		

		if ((char)cv::waitKey(33) >= 0) break;

	}

	return 0;

}
