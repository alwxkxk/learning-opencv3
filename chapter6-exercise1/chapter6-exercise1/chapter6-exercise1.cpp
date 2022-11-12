#include <opencv2/opencv.hpp>


int main(int argc, char** argv) {
	// 创建一个底色图片，scalar前三数值分别对应 蓝绿红（与rgb反过来了）
	cv::Mat img(500, 1000, CV_8UC4, cv::Scalar(0, 0, 0, 0));

	if (img.empty()) return -1;
	// 画一个红色的圈
	cv::circle(img, cv::Point(100, 100), 20, cv::Scalar(0, 0, 255, 0));
	// 画一条绿线
	cv::line(img, cv::Point(150, 150), cv::Point(200, 150), cv::Scalar(0, 255, 0, 0));
	// 画一个矩形
	cv::rectangle(img, cv::Point(200, 200), cv::Point(250, 250), cv::Scalar(255, 0, 0));
	// 字体，不支持utf8，所以要写中文要用第三方库。
	cv::putText(
		img,
		"english",
		cv::Point(300, 300),
		cv::FONT_HERSHEY_SIMPLEX,
		1,
		cv::Scalar(0, 0, 255, 0)
	);


	cv::namedWindow("chapter4-exercise1", cv::WINDOW_AUTOSIZE);
	cv::imshow("chapter4-exercise1", img);
	cv::waitKey(0);
	cv::destroyWindow("chapter4-exercise1");

	return 0;
}
