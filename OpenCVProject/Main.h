#pragma once
/*

//�����汾����  https://sourceforge.net/projects/opencvlibrary/files/opencv-win/

��C:\Program Files\OpenCV\opencv\build\x64\vc14\binĿ¼�����
opencv_world341.dll��opencv_world341d.dll
�ļ����Ƶ�C:\Windows\SysWOW64����ļ������漴��


��C:\Program Files\OpenCV\opencv\build\x64\vc14\binĿ¼�����
opencv_ffmpeg341_64.dll
���Ƶ�C:\Windows\System32����ļ�������


���û�������ʱ,��Ҫ��vc140 ��vc150��������,��Ȼ�б���ĳ�ͻ

���� =�� ���� =������������ֻ���� opencv_world410d.lib  һ���ļ�

������� opencv_world410.lib  ���� opencv_world410d.lib
��d ����Debug�汾

//ʵ��Begin
	// Read the image file
	Mat image = imread("C:\\Users\\Administrator\\Desktop\\ANYTOOL\\OpenGL_PlusPlusVersion\\1.jpg");

	if (image.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
		return -1;
	}

	String windowName = "My HelloWorld Window"; //Name of the window

	namedWindow(windowName); // Create a window

	imshow(windowName, image); // Show our image inside the created window.

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); //destroy the created window
//ʵ��End
*/
#include <iostream>
#define Main main


#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

#pragma comment(lib,"opencv_world410d.lib")
