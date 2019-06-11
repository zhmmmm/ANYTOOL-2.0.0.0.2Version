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

	m_Background = new Texture("res/Image/Card/Background/BG800.png");
	m_Background->SetTextureSize(ATATCONTENTSIZE(800, 600));
	m_T1 = new Texture("res/Image/Card/Croupier/棋牌人物 (84).png");
	m_T1->SetTextureSize(ATATCONTENTSIZE(300, 400));
	m_T2 = new Texture("res/Image/UI/21GZ_bg.png");
	m_T2->SetTextureSize(ATATCONTENTSIZE(100, 100));
}

static int Angle = 0;

BASS_3DVECTOR Pos;
BASS_3DVECTOR Vel;
ATATPOS2D T1Pos = { 0,200 };
ATATPOS2D T2Pos = { -100,-50 };
float M[16] = { 0 };
ATPOS2D t1(T1Pos.X, T1Pos.Y);
ATPOS2D t2(T2Pos.X, T2Pos.Y);

void MainScene::Update()
{
	AT->ATENGINE_DisableCilentState();
	Camera::CameraToWorld(this);


	ATVector2D t = (t2 - t1).Normalize();
	t1 += t;
	m_T1->SetTexturePosition(t1);
	m_T1->DrawTexture();


	AT->ATENGINE_MatrixMode();
	Camera::CameraToWorld(this);

	m_T2->SetTexturePosition(t2);
	m_T2->DrawTexture();


	AT->ATENGINE_MatrixMode();
	Camera::CameraToWorld(this);
	m_Background->DrawTexture();

}



void MainScene::End()
{
	delete m_T1;
	m_T1 = NULL;
	delete m_T2;
	m_T2 = NULL;
	delete m_Background;
	m_Background = NULL;
}


void MainScene::OnOrdinaryKeyboardDownEvent(unsigned char Key, int X, int Y)
{
	std::cout << "普通按下！" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 'w' || Key == 'W')
	{

		Pos.z--;

		ATA->SetMusics3DPos(Pos, Vel);

		this->m_CameraPos_Z -= 5;
	}
	if (Key == 's' || Key == 'S')
	{
		Pos.z++;
		ATA->SetMusics3DPos(Pos, Vel);

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
	//std::cout << "功能按下！" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 101)//KEYUP
	{
		T1Pos.Y++;
	}
	if (Key == 103)//KEYDOWN
	{
		T1Pos.Y--;
	}
	if (Key == 100)//KEYLEFT
	{
		T1Pos.X--;
	}
	if (Key == 102)//KEYRIGHT
	{
		T1Pos.X++;
	}
}
void MainScene::OnMouseMoveEvent(int Mouse_X, int Mouse_Y)
{
	//std::cout << "鼠标移动 " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	//m_LookAt_X = Mouse_X - m_WindowsWidth / 2;
	//m_LookAt_Y = -(Mouse_Y - m_WindowsHeight / 2);
}

