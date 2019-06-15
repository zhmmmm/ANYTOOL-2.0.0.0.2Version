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
	srand(GetTickCount());

	this->m_Windows_X = 10;
	this->m_Windows_Y = 10;
	this->m_WindowsWidth = 800;
	this->m_WindowsHeight = 600;
	this->m_CameraPos_Y = 0;
	this->m_CameraPos_Z = 270;
	this->m_CameraPos_X = 0;

	ATA->LoadMusics("res\\Audio\\Musics\\dj - 预谋.mp3");
	ATA->PlayMusics("res\\Audio\\Musics\\dj - 预谋.mp3");

	m_Background = new Texture("res/Image/Background.jpg");
	m_Background->SetTextureSize(ATATCONTENTSIZE(800, 600));
}

BASS_3DVECTOR Pos;
BASS_3DVECTOR Vel;



int n = 10;  //圆绘制次数
float R = 100.0f;  //半径
ATVector2D A[10];
ATVector2D S[10];

void MainScene::Update()
{
	Camera::CameraToWorld(this);
	ATENGINE->ATENGINE_Disable(GL_TEXTURE_2D);

	ATENGINE->Rotate(m_Angle++,ATATPOS3D(0,0,1));
	float Buf[128] = { 0 };
	ATA->GetAudioStreamData("res\\Audio\\Musics\\dj - 预谋.mp3",Buf);
	Gadget::CreateMusicMapCircular2D(Buf, 80,0, 300);


	Camera::CameraToWorld(this);
	Gadget::CreateCircular2D(360,100);

	Gadget::CreateQuadrangle3D();

	ATENGINE->ATENGINE_DisableCilentState(GL_COLOR_ARRAY);
	ATENGINE->ATENGINE_Enable(GL_TEXTURE_2D);
	Camera::CameraToWorld(this);
	m_Background->DrawTexture();
}



void MainScene::End()
{
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

	}
	if (Key == 103)//KEYDOWN
	{

	}
	if (Key == 100)//KEYLEFT
	{

	}
	if (Key == 102)//KEYRIGHT
	{

	}
}
void MainScene::OnMouseMoveEvent(int Mouse_X, int Mouse_Y)
{
	//std::cout << "鼠标移动 " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	//m_LookAt_X = Mouse_X - m_WindowsWidth / 2;
	//m_LookAt_Y = -(Mouse_Y - m_WindowsHeight / 2);
}

