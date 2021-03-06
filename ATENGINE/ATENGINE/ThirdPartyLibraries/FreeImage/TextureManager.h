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



class _declspec(dllexport) TextureManager
{
public:
	//图片管理类的单例创建函数
	static TextureManager* Inst();
	virtual ~TextureManager();//析构

	//load a texture and make it the current texture
	//if texID is already in use, it will be unloaded and replaced with this texture
	bool LoadTexture(
		const char* filename,								//要加载的文件名
		const unsigned int texID,						//自定义的图片ID不是OpenGL创建的，
																			//但是是其键值对的键值
																			//因为这里使用的是map来存储的
																			//这两样数据
		GLenum image_format = GL_RGB,		//传入的图片颜色格式
		GLint internal_format = GL_RGB,			//图片存储格式
		GLint level = 0,											//多级图片等级
		GLint border = 0);									//图片边界尺寸

	//传入自定义图片ID卸载纹理
	//free the memory for a texture
	bool UnloadTexture(const unsigned int texID);

	//自定义的图片ID绑定纹理
	//set the current texture
	bool BindTexture(const unsigned int texID);//自定义的图片ID绑定纹理

	//一次性全部卸载所有的纹理
	//free all texture memory
	void UnloadAllTextures();

protected:
	TextureManager();//构造
	TextureManager(const TextureManager& tm) {}//拷贝构造
	TextureManager& operator=(const TextureManager& tm) 
	{
		TextureManager Tm;
		return Tm;
	}//等号赋值

	static TextureManager* m_inst;//单利对象指针
	std::map<unsigned int, GLuint> m_texID;//存储图像ID的map表





	//==================================================================
	/*
		以下是对FreeImage 的使用扩展
	*/

private:

	
public:
	BYTE *m_ColorData = NULL;//颜色数据
	FIBITMAP *m_Data = NULL;//保留作者自定义的数据类型
	unsigned int m_Width = 0;
	unsigned int m_Height = 0;
	unsigned int m_TextureID = 0;//纹理ID


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

	//纹理采样
	/*
	//设置纹理的采样方式
	//GL_NEAREST：最近点采样，效果差效率高
	//GL_LINEAR：线性插值采样，效果好效率低
	//GL_TEXTURE_MIN_FILTER表示这种采样方式
	//作用在缩小纹理采样上面，所谓缩小就是指
	//的模型三角形的绘制面积小于纹理三角形面
	//积的时候，GL_TEXTURE_MAG_FILTER就表示
	//这种采样作用在放大纹理采样上面，即模型
	//三角形的绘制面积大于纹理三角形面积的时
	//候，一般来说缩小、放大采样都需要设置
	*/
	//GL_TEXTURE_2D表示加载二维纹理
	//0表示不创建多级渐进纹理
	//GL_RGB表示纹理是RGB颜色模式
	//纹理像素宽
	//纹理像素高
	//0表示不设置纹理边界
	//GL_BGR_EXT     表示纹理像素的格式为B、G、R的排列
	//GL_UNSIGNED_BYTE   表示纹理像素颜色分量的格式为unsigned char
	//纹理像素颜色的起始地址

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