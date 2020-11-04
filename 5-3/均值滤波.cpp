#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
int main()
{

	VideoCapture cap;
	cap.open(0);

	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat dst;
		cv::Mat frame;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			GaussianBlur(frame, dst, Size(5,5), 1, 0);
			cv::imshow("dst", dst);

		}
		waitKey(30);
	}
}