
#include <opencv2/opencv.hpp>
#include <iostream>


void help(char** argv) {
	std::cout << "\n"
		<< "\nexample 2-10. The same object can load videos from a camera or a file"
		<< "\nCall:\n"
		<< argv[0] << " [path/image]\n"
		<< "\nor, read from camera:\n"
		<< argv[0]
		<< "\nFor example:\n"
		<< argv[0] << " ../test.avi\n"
		<< std::endl;
}


int main(int argc, char** argv) {

	help(argv);



	cv::namedWindow("video", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("video-frame_output_gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("video-frame_edge_detection", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;


	if (argc == 1) {
		std::cerr << "Should input a vidoe path as argv." << std::endl;
	}
	else {
		cap.open(argv[1]);
	}

	if (!cap.isOpened()) { // check if we succeeded
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	cv::Mat frame;
	cv::Mat frame_output_gray;
	cv::Mat frame_edge_detection;

	

	for (;;) {
		cap >> frame;

		if (frame.empty()) break; // Ran out of film

		cv::cvtColor(frame, frame_output_gray, cv::COLOR_BGR2GRAY);
		cv::Canny(frame, frame_edge_detection, 50, 500, 3, true);

		cv::imshow("video", frame);
		cv::imshow("video-frame_output_gray", frame_output_gray);
		cv::imshow("video-frame_edge_detection", frame_edge_detection);

		if ((char)cv::waitKey(33) >= 0) break;

	}

	cv::destroyWindow("video");
	cv::destroyWindow("video-frame_output_gray");
	cv::destroyWindow("video-frame_edge_detection");

	return 0;

}
