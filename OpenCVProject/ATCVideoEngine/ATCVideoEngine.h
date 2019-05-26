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
	#include <opencv2/opencv.hpp>
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

#include <map>
#include <string>
#include <iostream>
#include <Windows.h>

#include "ATBAudioEngine/ATBAudioEngine.h"

//#include <opencv2/gapi.hpp>
//#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

#pragma comment(lib,"opencv_world410d.lib")

#define ATV ATCVE::GetInstance()

//AT OPENCV VIDEO ENGINE
class ATCVE
{
	BOOL m_IsPlayVideo = FALSE;

	map<string, VideoCapture> m_VideoMap;

	string m_CurPlayVideo;

public:
	static ATCVE *GetInstance();
	BOOL LoadVideo(string VideoFileName);
	BOOL PlayVideo(string VideoFileName);
	BOOL PlayVideo(string VideoFileName,string WindowName);


	BOOL PauseVideo(string VideoFileName);

	BOOL StopVideo();
	BOOL StopVideo(string VideoFileName);

	void FreeATC();
	void FreeWindow(string WindowName);
	void FreeAllWindow();
private:
	ATCVE();
	~ATCVE();
};