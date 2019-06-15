#pragma once
#include "OpenGL_AY_Engine.h"

typedef unsigned int T_2D;

typedef struct TEXTURE
{
	//����ID
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

	ATATPOS2D Position;

}TextureV, TextureINFO, *LPTextureV;

//class Texture2D
//{
//	unsigned int *m_TextureArr = NULL;
//	int m_CurCapacity = 5;//��ǰ����
//	int m_SaveMemory = 0;//�Ѿ����������
//	int m_CapacityScale = 5;//ÿ�ο���������
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
//	//������ʽ Ĭ��Ϊ������� GL_NEAREST
//	//GL_LINEAR ���Բ���
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

//�����ֻ�ܼ���λͼ
//��ռʱ������
class _declspec(dllexport) Texture2D
{
	TextureV m_TextureV;
	unsigned int TextureID = 0;
public:
	Texture2D();
	Texture2D(const char *FileName);
	/*
		�����Ҫ�ͷ��������

	*/
	static Texture2D *Create(const char *FileName);
	void DrawTexture2D();


private:
	void InitTexture(const char *FileName);
	void LoadTexture(const char *FileName);
};

//֧�ֳ���ͼƬ
/*
IMAGEBMP   0
IMAGEPNG   1
IMAGEJPG     2
IMAGEJPEG   3
IMAGEPSD    4
IMAGEJPE     5
IMAGETIF      6
*/
class _declspec(dllexport) Texture
{
	string m_FileName;
	TextureINFO m_TextureINFO;
	
public:
	Texture();
	Texture(const char *FileName);
	~Texture();

	static Texture *Create(const char *FileName);

	void DrawTexture();
	void DeleteTexture();


	TextureINFO *GetTextureInfo() { return &m_TextureINFO; }
	//�벻Ҫ�� TextureINFO.TID ������֪������ʲô
	void SetTextureInfo(TextureINFO *TextureINFO);
	string *GetTextureName() { return &m_FileName; }

	void SetTextureWidth(float Width);
	void SetTextureHeight(float Height);
	void SetTextureSize(ATATCONTENTSIZE Size);
	void SetTexturePositionX(float X);
	void SetTexturePositionY(float Y);
	void SetTexturePosition(float X, float Y);
	void SetTexturePosition(ATATPOS2D Position);
	void SetTexturePosition(ATATPOS2D *Position);
	void SetTexturePosition(ATVector2D Position);
	void SetTexturePosition(ATVector2D *Position);
private:
	//��ֵ��Ϣ
	void AssignmentINFO();
protected:
	ATVector2D _Position;
};