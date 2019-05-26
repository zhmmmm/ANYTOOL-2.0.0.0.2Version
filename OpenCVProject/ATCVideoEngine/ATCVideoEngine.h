#pragma once
/*

//各个版本下载  https://sourceforge.net/projects/opencvlibrary/files/opencv-win/

将C:\Program Files\OpenCV\opencv\build\x64\vc14\bin目录下面的
opencv_world341.dll和opencv_world341d.dll
文件复制到C:\Windows\SysWOW64这个文件夹里面即可


将C:\Program Files\OpenCV\opencv\build\x64\vc14\bin目录里面的
opencv_ffmpeg341_64.dll
复制到C:\Windows\System32这个文件夹里面


配置环境变量时,不要把vc140 和vc150都配置了,不然有编译的冲突

连接 =》 输入 =》附加依赖项只能有 opencv_world410d.lib  一个文件

必须包含 opencv_world410.lib  或者 opencv_world410d.lib
带d 的是Debug版本

//实例Begin
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
//实例End
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