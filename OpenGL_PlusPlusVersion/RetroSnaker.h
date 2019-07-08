#pragma once
#include "MAIN/OpenGL_AY_Engine.h"

enum SNAKEDIR
{
	UP = 101,
	DOWN = 103,
	LEFT = 100,
	RIGHT = 102
};


class RetroSnaker:public Object
{



	Texture *m_SnakeUp;
	Texture *m_SnakeDown;
	Texture *m_SnakeLeft;
	Texture *m_SnakeRight;
	Texture *m_Background;

	ATVector2D m_Pos;

	int m_SnakeLen = 15;
	static const int m_SnakeMaxLen = 100;
	int m_SnakeDir = SNAKEDIR::RIGHT;
	ATVector2D m_SnakePos[100];

	Texture m_SnakeBody[m_SnakeMaxLen];

public:
	RetroSnaker();
	~RetroSnaker();
	void initting();
	void runing();
	void ending();

	void SnakeRefresh();
	void SnakeBody();


	void updateTime(int Time);
	void OnSpecialKeyboardDownEvent(int Key, int X, int Y);
};