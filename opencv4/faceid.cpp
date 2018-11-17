/*
 * faceid.c
 * 
 * Copyright 2018  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{
	CascadeClassifier faceCascader , eyeCascader;
	String filename = "/home/pi/Downloads/opencv-3.4.3/data/haarcascades/haarcascade_frontalface_alt.xml";
	if (!faceCascader.load(filename))
	{
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	namedWindow("output", WINDOW_AUTOSIZE);
	VideoCapture capture;
	char filename1[100];
	capture.open("work1.avi");
	if (!capture.isOpened())
	{
		return -1;
	}
	Mat frame, gray, faceROI, src;
	vector<Rect> faces, eyes;
	int k = 0;
	while (capture.read(frame))
	{
		src = frame;
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		equalizeHist(gray, gray);
		faceCascader.detectMultiScale(gray, faces, 1.2, 3, 0, Size(100, 100));
		for (int i = 0; i < faces.size(); i++)
		{
			Rect roi;
			roi.x = faces[static_cast<int>(i)].x + 2;
			roi.y = faces[static_cast<int>(i)].y + 2;
			roi.width = faces[static_cast<int>(i)].width - 2;
			roi.height = faces[static_cast<int>(i)].height - 2;
			//人脸区域
			
			rectangle(frame, faces[static_cast<int>(i)], Scalar(0, 255, 0), 1, 8, 0);
			faceROI=gray(faces[i]);
			Mat faceOrg=frame(faces[i]);
			blur(faceOrg,faceOrg,Size(25,25));
			
			//将人脸图像的大小统一调整为150*150
			resize(faceROI, faceROI, Size(150, 150));
			
			
		}
		char q = waitKey(1);
		if (q == 27)
		{
			break;
		}
		imshow("input", frame);
		imshow("output", faceROI);

	}
	waitKey(0);
	capture.release();
	return 0;
}

