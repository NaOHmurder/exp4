// ConsoleApplication3.cpp : �������̨Ӧ�ó������ڵ㡣
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

	/*Mat edges; //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
			   //��2��ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame; //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;  //��ȡ��ǰ֡                        
		if (frame.empty())
		{
			printf("--(!) No captured frame -- Break!");
			//break;                
		}
		else
		{
			cvtColor(frame, edges, CV_BGR2GRAY);//��ɫת���ɻҶ�
			blur(edges, edges, Size(7, 7));//ģ����
			Canny(edges, edges, 0, 30, 3);//��Ե��
			imshow("��ȡ����Ե�����Ƶ", frame); //��ʾ��ǰ֡

		}

		waitKey(30); //��ʱ30ms
	}*/
    return 0;
}

