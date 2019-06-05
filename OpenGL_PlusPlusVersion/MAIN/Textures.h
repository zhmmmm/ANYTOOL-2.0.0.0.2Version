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

}TextureV, TextureINFO, *LPTextureV;

//class Texture2D
//{
//	unsigned int *m_TextureArr = NULL;
//	int m_CurCapacity = 5;//当前容量
//	int m_SaveMemory = 0;//已经保存的容量
//	int m_CapacityScale = 5;//每次开容量比例
//
//	int m_TextureArrIndex = 0;
//	float m_CooryArr[12] = 
//	{
//		-20,+20,0,
//		-20,-20,0,
//		+20,-20,0,
//		+20,+20,0
//	};
//	float m_UV[8] = 
//	{
//		0,1,
//		0,0,
//		1,0,
//		1,1
//	};
//	unsigned int m_Index[6] = 
//	{
//		0,1,2,
//		0,2,3
//	};
//
//	map<string, TextureV> m_TextureMap;
//public:
//	Texture2D();
//	~Texture2D();
//	T_2D Create(const char *FileName);
//	//采样方式 默认为最近采样 GL_NEAREST
//	//GL_LINEAR 线性采样
//	T_2D Create(const char *FileName,unsigned int PARAM);
//
//
//	void DrawTexture(int ID);
//	void DrawTexture(const char *FileName);
//	void DrawTexture(const void *CooryArr,const void *UV,int ID,const void *Index);
//
//	void SetTextureWidth(int ID, float Width);
//	void SetTextureHeight(int ID, float Height);
//	void SetTextureSize(int ID, float Width,float Height);
//	void SetTextureSize(int ID, ATATCONTENTSIZE Size);
//	void SetTextureWidth(const char *FileName, float Width);
//	void SetTextureHeight(const char *FileName, float Height);
//	void SetTextureSize(const char *FileName, float Width, float Height);
//	void SetTextureSize(const char *FileName, ATATCONTENTSIZE Size);
//private:
//	void NewMemory();
//};

class Texture2D
{
	TextureV m_TextureV;
	unsigned int TextureID = 0;
public:
	Texture2D();
	Texture2D(const char *FileName);
	/*
		你可能要释放这个对象

	*/
	static Texture2D *Create(const char *FileName);
	void DrawTexture2D();


private:
	void InitTexture(const char *FileName);
	void LoadTexture(const char *FileName);
public:
	//拷贝构造
	Texture2D(const Texture2D& that);
	//同类赋值 重载 = 运算符
	Texture2D& operator = (const Texture2D& that);
};



class Texture3D
{
	TextureV m_TextureV;
	unsigned int TextureID = 0;
public:
	Texture3D();
	Texture3D(const char *FileName);
	static Texture3D *Create(const char *FileName);
	void DrawTexture3D();


private:
	void InitTexture(const char *FileName);
	void LoadTexture(const char *FileName);
public:
	//拷贝构造
	Texture3D(const Texture3D& that) {}
	//同类赋值 重载 = 运算符
	Texture3D& operator = (const Texture3D& that) {}
};




class TEXTUREMANAGER
{
	string m_FileName;
	TextureINFO m_TextureINFO;
public:
	TEXTUREMANAGER();
	TEXTUREMANAGER(const char *FileName);
	static TEXTUREMANAGER *Create(const char *FileName);
	void DrawTexture();
private:
	//赋值信息
	void AssignmentINFO();
};