#include<opencv2/opencv.hpp>
#include<iostream>
#include <windows.h>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture video;
	video.open("D:/opencvpicture/Bad Apple.FLV");
	if (!video.isOpened())
	{
		cout << "ÊÓÆµ´ò¿ªÊ§°Ü" << endl;
		return -1;
	}
	Mat frame = imread("E:/opencvpicture/delta_002.jpg");
	int fps = video.get(CAP_PROP_FPS);
	int s = 1000 / fps;
	int time;
	int width, height;
	int col, row;
	int i;
	width = video.get(CAP_PROP_FRAME_WIDTH);
	height = video.get(CAP_PROP_FRAME_HEIGHT);
	const int fcount = video.get(CAP_PROP_FRAME_COUNT);
	int count = 0;
	time = fcount / fps;
	string video_stirng;
	unsigned char codeLib[2] = { '.',' '};
	char keyword = '\0';
	int temp;
	Mat dst;

	while (true)
	{
		if (!video.read(frame))
		{
			break;
		}
		cvtColor(frame, frame, CV_BGR2GRAY);
		resize(frame, frame, Size(frame.cols/5 ,frame.rows/11), 0, 0, INTER_LINEAR);
		video_stirng = "";
		for (row = 0; row < frame.rows; row++)
		{
			for (col = 0; col < frame.cols; col++)
			{
				temp = frame.at<uchar>(row, col) /255;
				/*cout << codeLib[temp];*/
				video_stirng += codeLib[temp];
			}
			video_stirng += '\n';
			cout << endl;
		}
	waitKey(30);
		cout << video_stirng<<endl;
		system("cls");
	}
	
	system("pause");
	return 0;
}