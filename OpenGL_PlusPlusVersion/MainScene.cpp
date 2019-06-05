/*
����˵��:==>
*/
#include "MainScene.h"

void Scene::ATOpenGLInitData()
{

	m_T1 = Texture2D::Create("1.bmp");
	m_T2 = Texture2D::Create("psb.bmp");
	m_T3 = Texture3D::Create("1.bmp");

	TM->LoadTexture("1.png");

	m_T4 = TEXTUREMANAGER::Create("1.bmp");
}

void Scene::Start()
{
	this->m_Windows_X = 10;
	this->m_Windows_Y = 10;
	this->m_WindowsWidth = 800;
	this->m_WindowsHeight = 600;
	this->m_CameraPos_Y = 0;
	this->m_CameraPos_Z = 270;
	this->m_CameraPos_X = 0;

	//ATA->Init3DAudioEngine();

	//ATA->LoadMusics3D("res\\Audio\\Musics\\dj - Ԥı.mp3");
	//ATA->PlayMusics("res\\Audio\\Musics\\dj - Ԥı.mp3");

}

static int Angle = 0;

BASS_3DVECTOR Pos;
BASS_3DVECTOR Vel;

int Volume = 0;

void Scene::Update()
{
	Camera::CameraToWorld(this);

	//m_T2->DrawTexture2D();


	//m_T3->DrawTexture3D();


	m_T4->DrawTexture();
}

void Scene::OnOrdinaryKeyboardDownEvent(unsigned char Key, int X, int Y)
{
	std::cout << "��ͨ���£�" << Key << " X = " << X << " Y = " << Y << std::endl;
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
	std::cout << "���ܰ��£�" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 101)//KEYUP
	{

	}
	if (Key == 103)//KEYDOWN
	{

	}
}
void Scene::OnMouseMoveEvent(int Mouse_X, int Mouse_Y)
{
	//std::cout << "����ƶ� " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	//m_LookAt_X = Mouse_X - m_WindowsWidth / 2;
	//m_LookAt_Y = -(Mouse_Y - m_WindowsHeight / 2);
}

void Scene::End()
{
	delete m_T1;
	m_T1 = NULL;
	delete m_T2;
	m_T2 = NULL;
}