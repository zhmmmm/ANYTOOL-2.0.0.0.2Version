//**********************************************
//Singleton Texture Manager class
//Written by Ben English
//benjamin.english@oit.edu
//
//For use with OpenGL and the FreeImage library
//**********************************************
#include "TextureManager.h"
//使用这样的方式设置要链接的静态库
#pragma comment(lib,"FreeImage.lib")

TextureManager* TextureManager::m_inst(0);

TextureManager* TextureManager::Inst()
{
	if (!m_inst)
		m_inst = new TextureManager();

	return m_inst;
}

TextureManager::TextureManager()
{
	//如果是按照静态库的方式使用FreeImage，那么需要初始化
	// call this ONLY when linking with FreeImage as a static library
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();
#endif
}

//these should never be called
//TextureManager::TextureManager(const TextureManager& tm){}
//TextureManager& TextureManager::operator=(const TextureManager& tm){}

TextureManager::~TextureManager()
{
	//如果是按照静态库的方式使用FreeImage，那么需要销毁
	// call this ONLY when linking with FreeImage as a static library
#ifdef FREEIMAGE_LIB
	FreeImage_DeInitialise();
#endif

	UnloadAllTextures();
	if (m_inst)
	{
		delete m_inst;
	}
	m_inst = 0;
}

bool TextureManager::LoadTexture(
	const char* filename,
	const unsigned int texID,
	GLenum image_format,
	GLint internal_format,
	GLint level,
	GLint border)
{
	//图片格式
	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	//指向图片对象或者说句柄指针，只加载一次，FreeImage操作图片都要靠这个指针
	//有点类似打开文件返回的一个文件指针，通过这个指针可以操作文件
	//pointer to the image, once loaded
	FIBITMAP *dib(0);//FIBITMAP *dib=NULL;


	//指向的图片的颜色数据
	//pointer to the image data
	BYTE* bits(0);

	//图片的宽和高
	//image width and height
	unsigned int width(0), height(0);


	//要放到map中的OpenGL 的图片ID
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//根据文件签名(文件头)推断文件类型
	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//如果仍然不清楚格式，尝试从文件扩展名猜测文件格式
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);

	//如果仍然不清楚格式，返回假
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;


	//传入格式加载图片获得FreeImage的图片指针
	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);

	//如果文件加载失败，返回假
	//if the image failed to load, return failure
	if (!dib)
		return false;

	//接收图片的颜色数据
	//retrieve the image data
	bits = FreeImage_GetBits(dib);

	//获取图片的宽高
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);

	//检验图片数据是否合乎逻辑
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;


	//如果传入的自定义ID已经被使用，卸载当前自定义ID关联的OpenGL图片纹理
	//if this texture ID is in use, unload the current texture
	if (m_texID.find(texID) != m_texID.end())
		glDeleteTextures(1, &(m_texID[texID]));


	//重新创建OpenGL图片纹理
	//generate an OpenGL texture ID for this texture
	glGenTextures(1, &gl_texID);
	//store the texture ID mapping
	m_texID[texID] = gl_texID;
	//bind to the new texture ID
	glBindTexture(GL_TEXTURE_2D, gl_texID);
	glTexParameterf(
		GL_TEXTURE_2D,//二维纹理参数设置
		GL_TEXTURE_MIN_FILTER,//缩小采样
		GL_LINEAR);//采样方式
	glTexParameterf(
		GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER,//放大采样
		GL_LINEAR);
	//store the texture data for OpenGL use
	glTexImage2D(GL_TEXTURE_2D, level, internal_format, width, height,
		border, image_format, GL_UNSIGNED_BYTE, bits);

	//结束加载图片结束后卸载图片
	//Free FreeImage's copy of the data
	FreeImage_Unload(dib);
	glBindTexture(GL_TEXTURE_2D, 0);
	//return success
	return true;
}

bool TextureManager::UnloadTexture(const unsigned int texID)
{
	bool result(true);
	//if this texture ID mapped, unload it's texture, and remove it from the map
	if (m_texID.find(texID) != m_texID.end())
	{
		glDeleteTextures(1, &(m_texID[texID]));
		m_texID.erase(texID);
	}
	//otherwise, unload failed
	else
	{
		result = false;
	}

	return result;
}

bool TextureManager::BindTexture(const unsigned int texID)
{
	bool result(true);
	//if this texture ID mapped, bind it's texture as current
	if (m_texID.find(texID) != m_texID.end())
		glBindTexture(GL_TEXTURE_2D, m_texID[texID]);
	//otherwise, binding failed
	else
		result = false;

	return result;
}

void TextureManager::UnloadAllTextures()
{
	//start at the begginning of the texture map
	std::map<unsigned int, GLuint>::iterator i = m_texID.begin();

	//Unload the textures untill the end of the texture map is found
	while (i != m_texID.end())
		UnloadTexture(i->first);

	//clear the texture map
	m_texID.clear();
}







//==================================================================
/*
	以下是对FreeImage 的使用扩展
*/

bool TextureManager::LoadTexture(const char *FileName)
{
	char ImageType[][16] =
	{
		".bmp",
		".png",
		".jpg",
		".jpeg",
		".psd",
		".jpe",
		".tif"
	};
	int Index = -1;
	for (int i = 0; i < sizeof(ImageType) / 16; i++)
	{
		int Len = strlen(FileName);
		int TypeLen = strlen(ImageType[i]);

		for (int j = Len - 1; j >= 0; j--)
		{
			char Tmp = ImageType[i][TypeLen - (Len - j)];

			if (FileName[j] == '.' || Tmp == '.')
			{
				Index = i;
				break;
			}
			if (FileName[j] != Tmp)
			{
				break;
			}
		}
		if (Index != -1)
		{
			break;
		}
	}

	switch (Index)
	{
	case IMAGEBMP: {return TextureManager::Load_BMP(FileName); }; break;
	case IMAGEPNG: {return TextureManager::Load_PNG(FileName); }; break;
	case IMAGEJPG: {return TextureManager::Load_JPG(FileName); }break;
	case IMAGEJPEG: {return TextureManager::Load_JPEG(FileName); }break;
	case IMAGEPSD: {return TextureManager::Load_PSD(FileName); }break;
	case IMAGEJPE: {return TextureManager::Load_JPE(FileName); }break;
	case IMAGETIF: {return TextureManager::Load_TIF(FileName); }; break;
	}
	return false;
}

bool TextureManager::Load_BMP(const char *FileName)
{
	if (TextureManager::Load_FreeImage(FileName))
	{
		Load_Texture(GL_NEAREST, GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_ColorData, GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER);
		return true;
	}
	return false;
}

bool TextureManager::Load_PNG(const char *FileName)
{
	if (TextureManager::Load_FreeImage(FileName))
	{
		Load_Texture(GL_NEAREST, GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, m_ColorData, GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER);
		return true;
	}
	return false;
}

bool TextureManager::Load_JPG(const char *FileName)
{
	if (TextureManager::Load_FreeImage(FileName))
	{

		Load_Texture(GL_NEAREST, GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, m_ColorData, GL_TEXTURE_MIN_FILTER, GL_TEXTURE_MAG_FILTER);
		return true;
	}
	return false;
}

bool TextureManager::Load_JPEG(const char *FileName)
{
	return TextureManager::Load_JPG(FileName);
}

bool TextureManager::Load_PSD(const char *FileName)
{
	return TextureManager::Load_JPG(FileName);
}

bool TextureManager::Load_JPE(const char *FileName)
{
	return TextureManager::Load_JPG(FileName);
}

bool TextureManager::Load_TIF(const char *FileName)
{
	return TextureManager::Load_PNG(FileName);
}





//=====================================================================
bool TextureManager::Load_FreeImage(const char *FileName)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	fif = FreeImage_GetFileType(FileName, 0);
	if (fif == FIF_UNKNOWN)
	{
		fif = FreeImage_GetFIFFromFilename(FileName);
	}
	if (fif == FIF_UNKNOWN)
	{
		return false;
	}

	if (FreeImage_FIFSupportsReading(fif))
	{
		m_Data = FreeImage_Load(fif, FileName);
	}

	if (!m_Data)
	{
		return false;
	}

	m_ColorData = FreeImage_GetBits(m_Data);
	m_Width = FreeImage_GetWidth(m_Data);
	m_Height = FreeImage_GetHeight(m_Data);
	if (m_ColorData && m_Width && m_Height)
	{
		return true;
	}
	return false;
}

void TextureManager::Load_Texture(float PARAM, unsigned int TARGET, int Level, int Internalformat, int Width, int Height, int Border, unsigned int Format, unsigned int Type, BYTE *Pixels, unsigned int PNAME_0, unsigned int PNAME_1)
{
	glGenTextures(1, &m_TextureID);
	glBindTexture(TARGET, m_TextureID);
	glTexParameterf(TARGET, PNAME_0, PARAM);
	glTexParameterf(TARGET, PNAME_1, PARAM);
	glTexImage2D(TARGET, Level, Internalformat, Width, Height, Border, Format, Type, Pixels);
	FreeImage_Unload(m_Data);
	glBindTexture(GL_TEXTURE_2D, 0);
}