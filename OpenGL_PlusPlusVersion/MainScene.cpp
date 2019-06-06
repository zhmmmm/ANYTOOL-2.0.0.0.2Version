/*
场景说明:==>
*/
#include "MainScene.h"




void MainScene::ATOpenGLInitData()
{
	MainScene::Start();
}

void MainScene::Start()
{
	this->m_Windows_X = 10;
	this->m_Windows_Y = 10;
	this->m_WindowsWidth = 800;
	this->m_WindowsHeight = 600;
	this->m_CameraPos_Y = 0;
	this->m_CameraPos_Z = 270;
	this->m_CameraPos_X = 0;

	//ATA->Init3DAudioEngine();

	//ATA->LoadMusics3D("res\\Audio\\Musics\\dj - 预谋.mp3");
	//ATA->PlayMusics("res\\Audio\\Musics\\dj - 预谋.mp3");

	m_T1 = new TEXTUREMANAGER("1.png");
	m_T2 = new TEXTUREMANAGER("1.bmp");
}

static int Angle = 0;

BASS_3DVECTOR Pos;
BASS_3DVECTOR Vel;

int Volume = 0;





void MainScene::Update()
{
	AT->ATENGINE_DisableCilentState();
	Camera::CameraToWorld(this);


	m_T1->DrawTexture();

	AT->Translate(ATATPOS2D(-100,0));
	m_T2->DrawTexture();
}

void MainScene::OnOrdinaryKeyboardDownEvent(unsigned char Key, int X, int Y)
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
void MainScene::OnSpecialKeyboardDownEvent(int Key, int X, int Y)
{
	std::cout << "功能按下！" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 101)//KEYUP
	{

	}
	if (Key == 103)//KEYDOWN
	{

	}
}
void MainScene::OnMouseMoveEvent(int Mouse_X, int Mouse_Y)
{
	//std::cout << "鼠标移动 " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	//m_LookAt_X = Mouse_X - m_WindowsWidth / 2;
	//m_LookAt_Y = -(Mouse_Y - m_WindowsHeight / 2);
}

void MainScene::End()
{
	delete m_T1;
	m_T1 = NULL;
}