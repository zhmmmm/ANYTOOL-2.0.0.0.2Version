/*
场景说明:==>
*/
#include "MainScene.h"

void Scene::ATOpenGLInitData()
{

	m_T1 = Texture2D::create("1.bmp");
	m_T2 = Texture2D::create("psb.bmp");
}

void Scene::Start()
{
	S = new Sprite("1.bmp");

	this->m_Windows_X = 10;
	this->m_Windows_Y = 10;
	this->m_WindowsWidth = 800;
	this->m_WindowsHeight = 600;
	this->m_CameraPos_Y = 0;
	this->m_CameraPos_Z = 260;

	//ATA->Init3DAudioEngine();

	//ATA->LoadMusics3D("res\\Audio\\Musics\\dj - 预谋.mp3");
	//ATA->PlayMusics("res\\Audio\\Musics\\dj - 预谋.mp3");
}

static int Angle = 0;

BASS_3DVECTOR Pos;
BASS_3DVECTOR Vel;

int Volume = 0;

void Scene::Update()
{
	Camera::CameraToWorld(this);
	//m_Texture2D.SetTextureSize("LaKes.bmp",100,400);
	//m_Texture2D.DrawTexture("LaKes.bmp");
	//AT->Translate(ATATPOS3D(-100,0,0));
	//m_Texture2D.DrawTexture(2);

	m_T1->DrawTexture2D();

	AT->Translate(ATATPOS3D(-100,0,0));
	m_T2->DrawTexture2D();
}

void Scene::OnOrdinaryKeyboardDownEvent(unsigned char Key, int X, int Y)
{
	std::cout << "普通按下！" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 'w' || Key == 'W')
	{

		Vel.x++;
		ATA->SetMusics3DPos(Pos, Vel);

		this->m_CameraPos_Z -= 5;
	}
	if (Key == 's' || Key == 'S')
	{
		this->m_CameraPos_Z += 5;
	}
	if (Key == 'a' || Key == 'A')
	{
		m_CameraPos_X -= m_MoveSpeed_X;

		Pos.x--;
		ATA->SetMusics3DPos(Pos);
	}
	if (Key == 'd' || Key == 'D')
	{
		m_CameraPos_X += m_MoveSpeed_X;

		Pos.x++;
		ATA->SetMusics3DPos(Pos);
	}
	if (Key == '\r')
	{
		exit(0);
	}
}
void Scene::OnSpecialKeyboardDownEvent(int Key, int X, int Y)
{
	std::cout << "功能按下！" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 101)//KEYUP
	{

	}
	if (Key == 103)//KEYDOWN
	{

	}
}
void Scene::OnMouseMoveEvent(int Mouse_X, int Mouse_Y)
{
	std::cout << "鼠标移动 " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	//m_LookAt_X = Mouse_X - m_WindowsWidth / 2;
	//m_LookAt_Y = -(Mouse_Y - m_WindowsHeight / 2);
}

void Scene::End()
{
	delete S;
	S = NULL;
}