//**********************************************
//Singleton Texture Manager class
//Written by Ben English
//benjamin.english@oit.edu
//
//For use with OpenGL and the FreeImage library
//**********************************************
#include "TextureManager.h"
//ʹ�������ķ�ʽ����Ҫ���ӵľ�̬��
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
	//����ǰ��վ�̬��ķ�ʽʹ��FreeImage����ô��Ҫ��ʼ��
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
	//����ǰ��վ�̬��ķ�ʽʹ��FreeImage����ô��Ҫ����
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
	//ͼƬ��ʽ
	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	//ָ��ͼƬ�������˵���ָ�룬ֻ����һ�Σ�FreeImage����ͼƬ��Ҫ�����ָ��
	//�е����ƴ��ļ����ص�һ���ļ�ָ�룬ͨ�����ָ����Բ����ļ�
	//pointer to the image, once loaded
	FIBITMAP *dib(0);//FIBITMAP *dib=NULL;


	//ָ���ͼƬ����ɫ����
	//pointer to the image data
	BYTE* bits(0);

	//ͼƬ�Ŀ��͸�
	//image width and height
	unsigned int width(0), height(0);


	//Ҫ�ŵ�map�е�OpenGL ��ͼƬID
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//�����ļ�ǩ��(�ļ�ͷ)�ƶ��ļ�����
	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//�����Ȼ�������ʽ�����Դ��ļ���չ���²��ļ���ʽ
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);

	//�����Ȼ�������ʽ�����ؼ�
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;


	//�����ʽ����ͼƬ���FreeImage��ͼƬָ��
	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);

	//����ļ�����ʧ�ܣ����ؼ�
	//if the image failed to load, return failure
	if (!dib)
		return false;

	//����ͼƬ����ɫ����
	//retrieve the image data
	bits = FreeImage_GetBits(dib);

	//��ȡͼƬ�Ŀ���
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);

	//����ͼƬ�����Ƿ�Ϻ��߼�
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;


	//���������Զ���ID�Ѿ���ʹ�ã�ж�ص�ǰ�Զ���ID������OpenGLͼƬ����
	//if this texture ID is in use, unload the current texture
	if (m_texID.find(texID) != m_texID.end())
		glDeleteTextures(1, &(m_texID[texID]));


	//���´���OpenGLͼƬ����
	//generate an OpenGL texture ID for this texture
	glGenTextures(1, &gl_texID);
	//store the texture ID mapping
	m_texID[texID] = gl_texID;
	//bind to the new texture ID
	glBindTexture(GL_TEXTURE_2D, gl_texID);
	glTexParameterf(
		GL_TEXTURE_2D,//��ά������������
		GL_TEXTURE_MIN_FILTER,//��С����
		GL_LINEAR);//������ʽ
	glTexParameterf(
		GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER,//�Ŵ����
		GL_LINEAR);
	//store the texture data for OpenGL use
	glTexImage2D(GL_TEXTURE_2D, level, internal_format, width, height,
		border, image_format, GL_UNSIGNED_BYTE, bits);

	//��������ͼƬ������ж��ͼƬ
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
	�����Ƕ�FreeImage ��ʹ����չ
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