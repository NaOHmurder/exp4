// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	VideoCapture capture(0);
	capture.set(CAP_PROP_FRAME_HEIGHT, 480);
	capture.set(CAP_PROP_FRAME_WIDTH, 640);
	capture.set(CAP_PROP_FPS, 25.0);
	VideoWriter writer("work.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 25.0, Size(640, 480), true);
	Mat videoPlay;
	namedWindow("Camera", WINDOW_NORMAL);
	while (capture.isOpened()) {
		capture >> videoPlay;
		writer << videoPlay;
		imshow("Camera", videoPlay);
		waitKey(1000 / 30);
	}
	writer.release();
	capture.release();
	destroyWindow("Camera");

	/*Mat edges; //定义一个Mat变量，用于存储每一帧的图像
			   //【2】循环显示每一帧
	while (1)
	{
		Mat frame; //定义一个Mat变量，用于存储每一帧的图像
		capture >> frame;  //读取当前帧                        
		if (frame.empty())
		{
			printf("--(!) No captured frame -- Break!");
			//break;                
		}
		else
		{
			cvtColor(frame, edges, CV_BGR2GRAY);//彩色转换成灰度
			blur(edges, edges, Size(7, 7));//模糊化
			Canny(edges, edges, 0, 30, 3);//边缘化
			imshow("读取被边缘后的视频", frame); //显示当前帧

		}

		waitKey(30); //延时30ms
	}*/
    return 0;
}

