#pragma once
#include "OpenGL_AY_Engine.h"

typedef unsigned int T_2D;

typedef struct TEXTURE
{
	unsigned int TID = 0;

	float CooryArr[12] =
	{
		-20,+20,0,
		-20,-20,0,
		+20,-20,0,
		+20,+20,0
	};
	float UV[8] =
	{
		0,1,
		0,0,
		1,0,
		1,1
	};
	unsigned int Index[6] =
	{
		0,1,2,
		0,2,3
	};
	float Width = 0;
	float Height = 0;

}TextureV,*LPTextureV;

class Texture2D
{
	unsigned int *m_TextureArr = NULL;
	int m_CurCapacity = 5;//当前容量
	int m_SaveMemory = 0;//已经保存的容量
	int m_CapacityScale = 5;//每次开容量比例

	int m_TextureArrIndex = 0;
	float m_CooryArr[12] = 
	{
		-20,+20,0,
		-20,-20,0,
		+20,-20,0,
		+20,+20,0
	};
	float m_UV[8] = 
	{
		0,1,
		0,0,
		1,0,
		1,1
	};
	unsigned int m_Index[6] = 
	{
		0,1,2,
		0,2,3
	};

	map<string, TextureV> m_TextureMap;
public:
	Texture2D();
	~Texture2D();
	T_2D Create(const char *FileName);
	//采样方式 默认为最近采样 GL_NEAREST
	//GL_LINEAR 线性采样
	T_2D Create(const char *FileName,unsigned int PARAM);


	void DrawTexture(int ID);
	void DrawTexture(const char *FileName);
	void DrawTexture(const void *CooryArr,const void *UV,int ID,const void *Index);
	void SetTextureWidth(int ID, int Width);
	void SetTextureHeight(int ID, int Height);
	void SetTextureSize(int ID, ATATCONTENTSIZE Size);
private:
	void NewMemory();
};

class Texture3D
{
public:
	Texture3D();
};