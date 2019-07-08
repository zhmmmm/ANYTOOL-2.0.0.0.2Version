#include "MAIN/OpenGL_AY_Engine.h"
#include "MainScene.h"

#define Main main

// ATENGINE
// ATVARIABLE
MainScene g_Object;

void MainDisplay();
void MainInit();


void OnWindowsChange(int width, int height)
{
	std::cout << "ˢ�� OnWindowsChange" << std::endl;
	std::cout << width << " " << height << std::endl;
	g_Object.m_CurWindowsWidth = width;
	g_Object.m_CurWindowsHeight = height;
	ATENGINE->ATENGINE_WindowsChangeMatrixModeAndOrtho2D(GL_PROJECTION,
		width, height,
		MATRIXMODE::LEFTDOWN);
}
//����
void OnOrdinaryKeyboardDown(unsigned char Key, int X, int Y)
{
	//std::cout << "��ͨ���£�" << Key << " X = " << X << " Y = " << Y << std::endl;
	//if (Key == '\r')
	//{
	//	exit(0);
	//}
	g_Object.OnOrdinaryKeyboardDownEvent(Key, X, Y);
}
void OnOrdinaryKeyboardUp(unsigned char Key, int X, int Y)
{
	//std::cout << "��̧ͨ��" << Key << " X = " << X << " Y = " << Y << std::endl;
	g_Object.OnOrdinaryKeyboardUpEvent(Key, X, Y);
}
void OnSpecialKeyboardDown(int Key, int X, int Y)
{
	//std::cout << "���ܰ��£�" << Key << " X = " << X << " Y = " << Y << std::endl;
	g_Object.OnSpecialKeyboardDownEvent(Key, X, Y);
}
void OnSpecialKeyboardUp(int Key, int X, int Y)
{
	//std::cout << "����̧��" <<Key<<" X = "<<X<<" Y = "<<Y<< std::endl;
	g_Object.OnSpecialKeyboardUpEvent(Key, X, Y);
}

//���
void OnMouseClickEvent(int Button, int State, int X, int Y)
{
	//std::cout << "Button =" << Button << " State = " << State << " X = " << X << " Y = " << Y << std::endl;
	g_Object.OnMouseClickEvent(Button, State, X, Y);
}
void OnMouseMoveEvent(int Mouse_X, int Mouse_Y)
{
	//std::cout << "����ƶ� " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	g_Object.OnMouseMoveEvent(Mouse_X, Mouse_Y);
}
void OnMousePassiveEvent(int Mouse_X, int Mouse_Y)
{
	//std::cout << "�����ק " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	g_Object.OnMousePassiveEvent(Mouse_X, Mouse_Y);
}

void OnIdle()
{
	//std::cout << "���ڿ���ˢ��" << std::endl;
	//ATENGINE->ATENGINE_RefreshDraw();
	ATENGINE->ATENGINE_FPSDRAW(1);
}

int Main(int argc, char **argv)
{
	MainInit();
	ATENGINE->Init(AT_INITOPENGL, &argc, argv);
	ATENGINE->InitMode(GLUT_DOUBLE | GLUT_RGBA,
		g_Object.m_Windows_X, g_Object.m_Windows_Y,
		g_Object.m_WindowsWidth, g_Object.m_WindowsHeight);
	ATVARIABLE->SetglClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ATENGINE_MAINDRAW(MainDisplay);
	ATENGINE_ONWINDOWSCHANGE(OnWindowsChange);
	ATENGINE_ONORDINARYKEYBOARDDOWN(OnOrdinaryKeyboardDown);
	ATENGINE_ONSPECIAKEYBOARDDOWN(OnSpecialKeyboardDown);
	ATENGINE_ONORDINARYKEYBOARDUP(OnOrdinaryKeyboardUp);
	ATENGINE_ONSPECIAKEYBOARDUP(OnSpecialKeyboardUp);
	ATENGINE_ONMOUSECILCKEVENT(OnMouseClickEvent);
	ATENGINE_ONMOUSEMOVEEVENT(OnMouseMoveEvent);
	ATENGINE_ONMOUSEPASSIVEEVENT(OnMousePassiveEvent);
	ATENGINE_ONIDLE(OnIdle);

	ATENGINE->ATENGINE_Enable();
	ATENGINE->ATENGINE_Enable(GL_DEPTH_TEST);
	ATENGINE->ATENGINE_CULLFACE();
	ATENGINE->ATENGINE_Enable(GL_TEXTURE_2D);
	ATENGINE->ATENGINE_Enable(GL_BLEND);
	ATENGINE->ATENGINE_EnableCilentState(GL_TEXTURE_COORD_ARRAY);
	ATENGINE->ATENGINE_EnableCilentState(GL_VERTEX_ARRAY);
	ATENGINE->ATENGINE_EnableCilentState(GL_COLOR_ARRAY);
	ATENGINE->ATENGINE_Enable(GL_ALPHA_TEST);
	ATENGINE->ATENGINE_GLAlphaFunc();
	ATENGINE->ATENGINE_GLBlendFunc();


	g_Object.ATOpenGLInitData();

	ATENGINE->ATENGINEMAIN_Loop();

	g_Object.End();

	system("pause");
	return 0;
}

void MainInit()
{
	//g_Object.Start();
}
void MainDisplay()
{
	ATENGINE->ATENGINE_Runing_Draw_Begin();

	g_Object.Update();

	ATENGINE->ATENGINE_Runing_Draw_End();
	ATENGINE->ATENGINE_SWAPBUFFERS();
}