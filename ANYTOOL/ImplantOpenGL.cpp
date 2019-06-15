#include "stdafx.h"
#include "ImplantOpenGL.h"


BOOL ImplantOpenGL::InitHDCTOMFC(HDC Hdc)
{
	if (ImplantOpenGL::SetWindowPixelFormat(Hdc))
	{
		return ImplantOpenGL::CreateGLContext(Hdc);
	}
	return FALSE;
}
BOOL ImplantOpenGL::InitHDCTOMFC(HWND HWnd)
{
	LONG lStyle = ::GetWindowLong(HWnd, GWL_STYLE);
	lStyle |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	if (SetWindowLong(HWnd, GWL_STYLE, lStyle))
	{
		return TRUE;
	}
	return FALSE;
	//TRACE(_T("OnInit, long = %d\n"), lStyle);
}

BOOL ImplantOpenGL::InitHDCTOMFC(CDialogEx *This)
{
	if (ImplantOpenGL::SetWindowPixelFormat(This->GetDC()->GetSafeHdc()))
	{
		if (ImplantOpenGL::InitHDCTOMFC(This->GetSafeHwnd()))
		{
			return ImplantOpenGL::CreateGLContext(This->GetDC()->GetSafeHdc());
		}
		return FALSE;
	}
	return FALSE;
}

void ImplantOpenGL::OpenGL_TO_MFC__Init_ATENGINE(Object *object, int Width, int Height)
{
	ATENGINE->InitMode(GLUT_DOUBLE | GLUT_RGBA);
	ATENGINE->ATENGINE_WindowsChangeMatrixModeAndOrtho2D(GL_PROJECTION,Width,Height, MATRIXMODE::CENTER);
	ATVARIABLE->SetglClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	object->m_WindowsWidth = Width;
	object->m_WindowsHeight = Height;
	object->m_CurWindowsWidth = Width;
	object->m_CurWindowsHeight = Height;


	/*
		事件的响应用MFC的事件
		会造成内存冲突
		就用MFC的事件
	*/

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

	object->ATOpenGLInitData();
}
void ImplantOpenGL::OpenGL_TO_MFC__Update_ATENGINE(Object *object)
{
	ATENGINE->ATENGINE_Runing_Draw_Begin();
	object->Update();
	ATENGINE->ATENGINE_Runing_Draw_End();

	//缓冲区已经交给了MFC,所以不必再交换
	//ATENGINE->ATENGINE_SWAPBUFFERS();
}
void ImplantOpenGL::OpenGL_TO_MFC__End_ATENGINE(Object *object)
{
	object->End();
}








































BOOL ImplantOpenGL::CreateGLContext(HDC Hdc)
{
	/*if ((m_hGLContext = wglCreateContext(hdc)) != NULL)
	{
		return wglMakeCurrent(hdc, m_hGLContext);
	}
	return FALSE;*/

	this->m_hGLContext = wglCreateContext(Hdc);
	if (this->m_hGLContext == NULL)
	{
		//创建失败
		return FALSE;
	}
	if (wglMakeCurrent(Hdc, this->m_hGLContext) == FALSE)
	{
		//选为当前RC失败
		return FALSE;
	}
	return TRUE;
}
BOOL ImplantOpenGL::SetWindowPixelFormat(HDC Hdc)
{
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,
		32,
		0,0,
		PFD_MAIN_PLANE,
		0,0,0,0
	};
	if ((m_nGLPixelIndex = ChoosePixelFormat(Hdc, &pfd)) == 0)
	{
		m_nGLPixelIndex = 1;
		if (DescribePixelFormat(Hdc, m_nGLPixelIndex, sizeof(PIXELFORMATDESCRIPTOR), &pfd) == 0)
		{
			return FALSE;
		}
	}

	return SetPixelFormat(Hdc, m_nGLPixelIndex, &pfd);
}