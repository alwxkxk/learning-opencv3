#include <opencv2/opencv.hpp>


int main(int argc, char** argv) {
	// ����һ����ɫͼƬ��scalarǰ����ֵ�ֱ��Ӧ ���̺죨��rgb�������ˣ�
	cv::Mat img(500, 1000, CV_8UC4, cv::Scalar(0, 0, 0, 0));

	if (img.empty()) return -1;
	// ��һ����ɫ��Ȧ
	cv::circle(img, cv::Point(100, 100), 20, cv::Scalar(0, 0, 255, 0));
	// ��һ������
	cv::line(img, cv::Point(150, 150), cv::Point(200, 150), cv::Scalar(0, 255, 0, 0));
	// ��һ������
	cv::rectangle(img, cv::Point(200, 200), cv::Point(250, 250), cv::Scalar(255, 0, 0));
	// ���壬��֧��utf8������Ҫд����Ҫ�õ������⡣
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
