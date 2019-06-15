//**********************************************
//Singleton Texture Manager class
//Written by Ben English
//benjamin.english@oit.edu
//
//For use with OpenGL and the FreeImage library
//**********************************************

#pragma once

#include <windows.h>
#include <gl/gl.h>
#include "FreeImage.h"
#include <map>

#define TM TextureManager::Inst()

#define IMAGEBMP   0
#define IMAGEPNG   1
#define IMAGEJPG     2
#define IMAGEJPEG   3
#define IMAGEPSD    4
#define IMAGEJPE     5
#define IMAGETIF      6



class TextureManager
{
public:
	//ͼƬ������ĵ�����������
	static TextureManager* Inst();
	virtual ~TextureManager();//����

	//load a texture and make it the current texture
	//if texID is already in use, it will be unloaded and replaced with this texture
	bool LoadTexture(
		const char* filename,								//Ҫ���ص��ļ���
		const unsigned int texID,						//�Զ����ͼƬID����OpenGL�����ģ�
																			//���������ֵ�Եļ�ֵ
																			//��Ϊ����ʹ�õ���map���洢��
																			//����������
		GLenum image_format = GL_RGB,		//�����ͼƬ��ɫ��ʽ
		GLint internal_format = GL_RGB,			//ͼƬ�洢��ʽ
		GLint level = 0,											//�༶ͼƬ�ȼ�
		GLint border = 0);									//ͼƬ�߽�ߴ�

	//�����Զ���ͼƬIDж������
	//free the memory for a texture
	bool UnloadTexture(const unsigned int texID);

	//�Զ����ͼƬID������
	//set the current texture
	bool BindTexture(const unsigned int texID);//�Զ����ͼƬID������

	//һ����ȫ��ж�����е�����
	//free all texture memory
	void UnloadAllTextures();

protected:
	TextureManager();//����
	TextureManager(const TextureManager& tm) {}//��������
	TextureManager& operator=(const TextureManager& tm)
	{
		TextureManager Tm;
		return Tm;
	}//�ȺŸ�ֵ

	static TextureManager* m_inst;//��������ָ��
	std::map<unsigned int, GLuint> m_texID;//�洢ͼ��ID��map��





	//==================================================================
	/*
		�����Ƕ�FreeImage ��ʹ����չ
	*/

private:

	
public:
	BYTE *m_ColorData = NULL;//��ɫ����
	FIBITMAP *m_Data = NULL;//���������Զ������������
	unsigned int m_Width = 0;
	unsigned int m_Height = 0;
	unsigned int m_TextureID = 0;//����ID


	bool LoadTexture(const char *FileName);

	bool Load_BMP(const char *FileName);
	bool Load_PNG(const char *FileName);
	bool Load_JPG(const char *FileName);
	bool Load_JPEG(const char *FileName);
	bool Load_PSD(const char *FileName);
	bool Load_JPE(const char *FileName);
	bool Load_TIF(const char *FileName);
private:

	bool Load_FreeImage(const char *FileName);

	//�������
	/*
	//��������Ĳ�����ʽ
	//GL_NEAREST������������Ч����Ч�ʸ�
	//GL_LINEAR�����Բ�ֵ������Ч����Ч�ʵ�
	//GL_TEXTURE_MIN_FILTER��ʾ���ֲ�����ʽ
	//��������С����������棬��ν��С����ָ
	//��ģ�������εĻ������С��������������
	//����ʱ��GL_TEXTURE_MAG_FILTER�ͱ�ʾ
	//���ֲ��������ڷŴ�����������棬��ģ��
	//�����εĻ�������������������������ʱ
	//��һ����˵��С���Ŵ��������Ҫ����
	*/
	//GL_TEXTURE_2D��ʾ���ض�ά����
	//0��ʾ�������༶��������
	//GL_RGB��ʾ������RGB��ɫģʽ
	//�������ؿ�
	//�������ظ�
	//0��ʾ����������߽�
	//GL_BGR_EXT     ��ʾ�������صĸ�ʽΪB��G��R������
	//GL_UNSIGNED_BYTE   ��ʾ����������ɫ�����ĸ�ʽΪunsigned char
	//����������ɫ����ʼ��ַ

	//BMP Load_Texture(GL_NEAREST, GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_ColorData, GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER);
	//PNG Load_Texture(GL_NEAREST, GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, m_ColorData, GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER);
	//JPG  Load_Texture(GL_NEAREST, GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_ColorData, GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER);
	void Load_Texture(
		float PARAM,
		unsigned int TARGET,
		int Level,
		int Internalformat,
		int Width, int Height,
		int Border,
		unsigned int Format,
		unsigned int Type,
		BYTE *Pixels,
		unsigned int PNAME_0,
		unsigned int PNAME_1);
};