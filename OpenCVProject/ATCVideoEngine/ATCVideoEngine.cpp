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
#include "ATCVideoEngine.h"

ATCVE *ATCVE::GetInstance()
{
	static ATCVE ATCVENGINE;
	return &ATCVENGINE;
}

ATCVE::ATCVE()
{

}
ATCVE::~ATCVE()
{
	ATV->FreeATC();
}

BOOL ATCVE::LoadVideo(string VideoFileName)
{
	map<string, VideoCapture>::iterator it = m_VideoMap.find(VideoFileName);
	if (it != m_VideoMap.end())
	{
		return TRUE;
	}
	VideoCapture Capture(VideoFileName);
	if (!Capture.isOpened())
	{
		return FALSE;
	}
	m_VideoMap.insert(pair<string, VideoCapture>(VideoFileName, Capture));
	return TRUE;
}
BOOL ATCVE::PlayVideo(string VideoFileName)
{
	map<string, VideoCapture>::iterator it = m_VideoMap.find(VideoFileName);
	if (it != m_VideoMap.end())//����
	{
		m_CurPlayVideo = it->first;

		Mat Frame;
		string WindowName("ATCV");
		
		double FPS = it->second.get(CAP_PROP_FPS);
		while (true)
		{
			it->second >> Frame;
			it->second.read(Frame);
			if (Frame.empty())
			{
				break;
			}
			imshow(WindowName, Frame);
			if (waitKey(33) == 27)
			{
				break;
			}

		}
		Frame.release();
		destroyWindow(WindowName); //destroy the created window
		return TRUE;
	}
	if (ATCVE::LoadVideo(VideoFileName))
	{
		ATCVE::PlayVideo(VideoFileName);
	}
	else
	{
		return FALSE;
	}
	//���return ֻ����������,û��ʵ������
	return TRUE;
}
BOOL ATCVE::PlayVideo(string VideoFileName, string WindowName)
{
	return FALSE;
}


BOOL ATCVE::PauseVideo(string VideoFileName)
{
	return FALSE;
}

BOOL ATCVE::StopVideo()
{
	return FALSE;
}
BOOL ATCVE::StopVideo(string VideoFileName)
{

	return FALSE;
}


void ATCVE::FreeATC()
{
	if (!m_VideoMap.empty())
	{
		ATCVE::StopVideo();

		for (map<string, VideoCapture>::iterator it = m_VideoMap.begin(); it != m_VideoMap.end(); it++)
		{
			it->second.release();
		}

		m_VideoMap.clear();
	}
	ATV->FreeAllWindow();
}
void ATCVE::FreeWindow(string WindowName)
{
	destroyWindow(WindowName);
}
void ATCVE::FreeAllWindow()
{
	destroyAllWindows();
}