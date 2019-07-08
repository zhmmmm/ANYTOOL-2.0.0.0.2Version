#include "RetroSnaker.h"



RetroSnaker::RetroSnaker()
{
	RetroSnaker::initting();
}

RetroSnaker::~RetroSnaker()
{
	RetroSnaker::ending();
}

void RetroSnaker::initting()
{
	ATA->InitAudioEngine();
	//ATA->LoadMusicsAndPlay("res/RetroSnaker/YZFHKM.mp3");

	m_Pos.x = this->m_WindowsWidth / 2;
	m_Pos.y = this->m_WindowsHeight / 2;

	m_SnakeUp = new Texture("res/RetroSnaker/SnakeUp.png");
	m_SnakeUp->SetVisible(false);

	m_SnakeDown = new Texture("res/RetroSnaker/SnakeDown.png");
	m_SnakeDown->SetVisible(false);

	m_SnakeLeft = new Texture("res/RetroSnaker/SnakeLeft.png");
	m_SnakeLeft->SetVisible(false);

	m_SnakeRight = new Texture("res/RetroSnaker/SnakeRight.png");

	m_Background = new Texture("res/Background.jpg");
	m_Background->SetTextureSize(ATATCONTENTSIZE(this->m_WindowsWidth, this->m_WindowsHeight));
	m_Background->SetTexturePosition(ATVector2D(400, 300));

	for (int i = 0; i < m_SnakeLen + 1; i++)
	{
		m_SnakePos[i] = ATVector2D(this->m_WindowsWidth / 2 - (i * 50), this->m_WindowsHeight / 2);
	}

	for (int i = 0; i < m_SnakeLen; i++)
	{
		Texture *Temp = new Texture("res/RetroSnaker/SnakeBody.png");
		m_SnakeBody[i] = *Temp;
		m_SnakeBody[i].SetTag(1);
		m_SnakeBody[i].SetTexturePosition(m_SnakePos[i + 1]);

	}
}

void RetroSnaker::runing()
{

	//每一秒移动一个单位
	this->registerUpdateTime(0.1);

	Camera::CameraToWorld(this);

	m_SnakeUp->SetTexturePosition(m_SnakePos[0]);
	m_SnakeUp->DrawTexture();
	m_SnakeDown->SetTexturePosition(m_SnakePos[0]);
	m_SnakeDown->DrawTexture();
	m_SnakeLeft->SetTexturePosition(m_SnakePos[0]);
	m_SnakeLeft->DrawTexture();
	m_SnakeRight->SetTexturePosition(m_SnakePos[0]);
	m_SnakeRight->DrawTexture();

	for (int i = 0; i < m_SnakeLen; i++)
	{
		m_SnakeBody[i].SetTexturePosition(m_SnakePos[i + 1]);
		m_SnakeBody[i].DrawTexture();
	}

	//OpenGL中,先画的在最上面
	//在来张背景
	//就她

	m_Background->DrawTexture();

}

void RetroSnaker::SnakeRefresh()
{
	for (int i = m_SnakeLen; i > 0; i--)
	{
		m_SnakePos[i] = m_SnakePos[i - 1];
	}
}

void RetroSnaker::SnakeBody()
{
	for (int i = 0; i < m_SnakeLen; i++)
	{
		if (m_SnakeBody[i].GetTag() == 0)
		{
			m_SnakeBody[i] = Texture("res/RetroSnaker/SnakeBody.png");
			m_SnakeBody[i].SetTag(1);
		}
		else
		{
			m_SnakeBody[i].SetTexturePosition(m_SnakePos[i + 1]);
		}
	}
}

void RetroSnaker::ending()
{
	delete m_SnakeUp;
	m_SnakeUp = NULL;
	delete m_SnakeDown;
	m_SnakeDown = NULL;
	delete m_SnakeLeft;
	m_SnakeLeft = NULL;
	delete m_SnakeRight;
	m_SnakeRight = NULL;
	delete m_Background;
	m_Background = NULL;
}

void RetroSnaker::updateTime(int Time)
{
	RetroSnaker::SnakeRefresh();
	switch (m_SnakeDir)
	{
	case SNAKEDIR::UP:
	{
		m_Pos.y += 50;
		m_SnakePos[0].y += 50;
	}; break;
	case SNAKEDIR::DOWN:
	{
		m_Pos.y -= 50;
		m_SnakePos[0].y -= 50;
	}; break;
	case SNAKEDIR::LEFT:
	{
		m_Pos.x -= 50;
		m_SnakePos[0].x -= 50;
	}; break;
	case SNAKEDIR::RIGHT:
	{
		m_Pos.x += 50;
		m_SnakePos[0].x += 50;
	}; break;
	}
	RetroSnaker::SnakeBody();
}


void RetroSnaker::OnSpecialKeyboardDownEvent(int Key, int X, int Y)
{
	//std::cout << "功能按下！" << Key << " X = " << X << " Y = " << Y << std::endl;

	if (Key == 101)//KEYUP
	{
		//不改进算法 不使用数组

		//往上走是不能向下,其他同理
		if (m_SnakeDir == SNAKEDIR::DOWN)
		{
			std::cout << "打头 ！ " << std::endl;
			return;
		}

		m_SnakeRight->SetVisible(false);
		m_SnakeUp->SetVisible(true);
		m_SnakeDown->SetVisible(false);
		m_SnakeLeft->SetVisible(false);

		m_SnakeDir = SNAKEDIR::UP;
	}
	if (Key == 103)//KEYDOWN
	{
		//不改进算法 不使用数组

		//往下走是不能向上,其他同理
		if (m_SnakeDir == SNAKEDIR::UP)
		{
			std::cout << "打头 ！ " << std::endl;
			return;
		}
		m_SnakeRight->SetVisible(false);
		m_SnakeUp->SetVisible(false);
		m_SnakeDown->SetVisible(true);
		m_SnakeLeft->SetVisible(false);

		m_SnakeDir = SNAKEDIR::DOWN;
	}
	if (Key == 100)//KEYLEFT
	{
		//不改进算法 不使用数组

		//往左走是不能向右,其他同理
		if (m_SnakeDir == SNAKEDIR::RIGHT)
		{
			std::cout << "打头 ！ " << std::endl;
			return;
		}
		m_SnakeRight->SetVisible(false);
		m_SnakeUp->SetVisible(false);
		m_SnakeDown->SetVisible(false);
		m_SnakeLeft->SetVisible(true);

		m_SnakeDir = SNAKEDIR::LEFT;
	}
	if (Key == 102)//KEYRIGHT
	{
		//不改进算法 不使用数组

		//往右走是不能向左,其他同理
		if (m_SnakeDir == SNAKEDIR::LEFT)
		{
			std::cout << "打头 ！ " << std::endl;
			return;
		}
		m_SnakeRight->SetVisible(true);
		m_SnakeUp->SetVisible(false);
		m_SnakeDown->SetVisible(false);
		m_SnakeLeft->SetVisible(false);

		m_SnakeDir = SNAKEDIR::RIGHT;
	}
}