#pragma once
#include "OpenGL_AY_Engine.h"

/*
	���ִ��Ҫ�� 
	Sprite S;
	S.Create("1.bmp");
	S.DrawSprite();
*/

//������
//��Щ��������bmp��ʽ��
class BITMAPS
{
	LPPIXCOLOR **m_BitMapRGBData = NULL;
	BITMAPFILEHEADER *m_bf = NULL;
	BITMAPINFOHEADER *m_bi = NULL;
	ATATPOS2D *m_Position = NULL;
	ATATSCALE2D *m_Scale = NULL;

	int m_SpriteState = 0;
public:
	BITMAPS();
	BITMAPS(const char *FileName);
	void *Create(const char *FileName);

	void SetSpriteScale(float X, float Y);
	//::::::::::::::::::::::::��������:::::::::::::::::::::::::::::::: ������ƵĿ�ʼλ�ó����ӿ�,��ô�ǻ��Ʋ�������
	void SetSpritePosition(float X, float Y);
	//float GetSpriteWidthAndHeight();

	LPPIXCOLOR *GetBitMapRGBData();

	void DrawSprite();
	//::::::::::::::::::::::::�������:::::::::::::::::::::::::::::::: void SetSpriteScale(float X, float Y); ��������Ч��
	void DrawSprite(float Width,float Height);
	//void DeleteSprite();
	~BITMAPS();
private:
	void InitSpriteInfoData();
	void DeleteSpriteInfoData();
};