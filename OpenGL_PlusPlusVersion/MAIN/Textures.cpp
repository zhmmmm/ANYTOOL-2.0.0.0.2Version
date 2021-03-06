#include "Textures.h"

//=====================================================================Texture2D
//Texture2D::Texture2D()
//{
//	Texture2D::NewMemory();
//}
//Texture2D::~Texture2D()
//{
//	if (m_TextureArr)
//	{
//		ATENGINE->ATENGINE_DeleteTexture(m_SaveMemory, m_TextureArr);
//		delete[] m_TextureArr;
//		m_TextureArr = NULL;
//		if (!m_TextureMap.empty())
//		{
//			m_TextureMap.clear();
//		}
//	}
//}
//
//T_2D Texture2D::Create(const char *FileName, unsigned int PARAM)
//{
//	Texture2D::NewMemory();
//
//	map<string, TextureV>::iterator it = m_TextureMap.find(FileName);
//	if (it != m_TextureMap.end())//存在
//	{
//		return it->second.TID;
//	}
//
//	ATENGINE->ATENGINE_CreateTextureID(1, m_TextureArr);
//
//	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, m_TextureArr[m_TextureArrIndex]);
//
//	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, PARAM);
//	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, PARAM);
//
//	ATENGINE->ATENGINE_LoadTexture(
//		GL_TEXTURE_2D,
//		0,
//		GL_RGB,
//		ATENGINE->GetBitMapWidth(),
//		ATENGINE->GetBitMapHeight(),
//		0,
//		GL_BGR_EXT,
//		GL_UNSIGNED_BYTE,
//		*ATENGINE->LoadBitMapRGBData(FileName));
//
//	ATENGINE->ATENGINE_BindTextureEnd();
//
//	m_TextureArrIndex++;
//
//	TextureV textureV;
//	textureV.Width = ATENGINE->GetBitMapWidth();
//	textureV.Height = ATENGINE->GetBitMapHeight();
//
//	textureV.CooryArr[0] = -textureV.Width / 2.0f;
//	textureV.CooryArr[1] = +textureV.Height / 2.0f;
//	textureV.CooryArr[3] = -textureV.Width / 2.0f;
//	textureV.CooryArr[4] = -textureV.Height / 2.0f;
//	textureV.CooryArr[6] = +textureV.Width / 2.0f;
//	textureV.CooryArr[7] = -textureV.Height / 2.0f;
//	textureV.CooryArr[9] = +textureV.Width / 2.0f;
//	textureV.CooryArr[10] = +textureV.Height / 2.0f;
//
//	m_TextureMap.insert(pair<string, TextureV>(FileName, textureV));
//
//	return m_TextureArr[m_TextureArrIndex - 1];
//}
//
//T_2D Texture2D::Create(const char *FileName)
//{
//	Texture2D::NewMemory();
//
//	map<string, TextureV>::iterator it = m_TextureMap.find(FileName);
//	if (it != m_TextureMap.end())//存在
//	{
//		return it->second.TID;
//	}
//
//	ATENGINE->ATENGINE_CreateTextureID(1, m_TextureArr);
//
//	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, m_TextureArr[0]);
//
//	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	ATENGINE->ATENGINE_LoadTexture(
//		GL_TEXTURE_2D,
//		0,
//		GL_RGB,
//		ATENGINE->GetBitMapWidth(),
//		ATENGINE->GetBitMapHeight(),
//		0,
//		GL_BGR_EXT,
//		GL_UNSIGNED_BYTE,
//		*ATENGINE->LoadBitMapRGBData(FileName));
//
//	ATENGINE->ATENGINE_BindTextureEnd();
//
//	m_TextureArrIndex++;
//
//	TextureV textureV;
//
//	textureV.TID = m_TextureArr[0];
//
//	textureV.Width = ATENGINE->GetBitMapWidth();
//	textureV.Height = ATENGINE->GetBitMapHeight();
//
//	textureV.CooryArr[0] = -textureV.Width / 2.0f;
//	textureV.CooryArr[1] = +textureV.Height / 2.0f;
//	textureV.CooryArr[3] = -textureV.Width / 2.0f;
//	textureV.CooryArr[4] = -textureV.Height / 2.0f;
//	textureV.CooryArr[6] = +textureV.Width / 2.0f;
//	textureV.CooryArr[7] = -textureV.Height / 2.0f;
//	textureV.CooryArr[9] = +textureV.Width / 2.0f;
//	textureV.CooryArr[10] = +textureV.Height / 2.0f;
//
//	m_TextureMap.insert(pair<string, TextureV>(FileName, textureV));
//
//	return m_TextureArr[0];
//}
//
//void Texture2D::DrawTexture(int ID)
//{
//	if (!m_TextureMap.empty())
//	{
//		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
//		{
//			if (it->second.TID == ID)
//			{
//				Texture2D::DrawTexture(it->second.CooryArr, it->second.UV, it->second.TID, it->second.Index);
//				return;
//			}
//		}
//	}
//}
//void Texture2D::DrawTexture(const char *FileName)
//{
//	if (!m_TextureMap.empty())
//	{
//		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
//		{
//			if (it->first == FileName)
//			{
//				Texture2D::DrawTexture(it->second.CooryArr, it->second.UV, it->second.TID, it->second.Index);
//				return;
//			}
//		}
//	}
//}
//void Texture2D::SetTextureWidth(int ID, float Width)
//{
//	if (!m_TextureMap.empty())
//	{
//		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
//		{
//			if (it->second.TID == ID)
//			{
//				it->second.Width = Width;
//				it->second.CooryArr[0] = -it->second.Width / 2.0f;
//				it->second.CooryArr[3] = -it->second.Width / 2.0f;
//				it->second.CooryArr[6] = +it->second.Width / 2.0f;
//				it->second.CooryArr[9] = +it->second.Width / 2.0f;
//				return;
//			}
//		}
//	}
//}
//void Texture2D::SetTextureHeight(int ID, float Height)
//{
//	if (!m_TextureMap.empty())
//	{
//		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
//		{
//			if (it->second.TID == ID)
//			{
//				it->second.Height = Height;
//				it->second.CooryArr[1] = +it->second.Height / 2.0f;
//				it->second.CooryArr[4] = -it->second.Height / 2.0f;
//				it->second.CooryArr[7] = -it->second.Height / 2.0f;
//				it->second.CooryArr[10] = +it->second.Height / 2.0f;
//				return;
//			}
//		}
//	}
//}
//void Texture2D::SetTextureSize(int ID, float Width, float Height)
//{
//	Texture2D::SetTextureWidth(ID, Width);
//	Texture2D::SetTextureHeight(ID, Height);
//}
//void Texture2D::SetTextureSize(int ID, ATATCONTENTSIZE Size)
//{
//	Texture2D::SetTextureSize(ID, Size.Get_Width(), Size.Get_Height());
//}
//void Texture2D::SetTextureWidth(const char *FileName, float Width)
//{
//	if (!m_TextureMap.empty())
//	{
//		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
//		{
//			if (it->first == FileName)
//			{
//				it->second.Width = Width;
//				it->second.CooryArr[0] = -it->second.Width / 2.0f;
//				it->second.CooryArr[3] = -it->second.Width / 2.0f;
//				it->second.CooryArr[6] = +it->second.Width / 2.0f;
//				it->second.CooryArr[9] = +it->second.Width / 2.0f;
//				return;
//			}
//		}
//	}
//}
//void Texture2D::SetTextureHeight(const char *FileName, float Height)
//{
//	if (!m_TextureMap.empty())
//	{
//		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
//		{
//			if (it->first == FileName)
//			{
//				it->second.Height = Height;
//				it->second.CooryArr[1] = +it->second.Height / 2.0f;
//				it->second.CooryArr[4] = -it->second.Height / 2.0f;
//				it->second.CooryArr[7] = -it->second.Height / 2.0f;
//				it->second.CooryArr[10] = +it->second.Height / 2.0f;
//				return;
//			}
//		}
//	}
//}
//void Texture2D::SetTextureSize(const char *FileName, float Width, float Height)
//{
//	Texture2D::SetTextureWidth(FileName, Width);
//	Texture2D::SetTextureHeight(FileName, Height);
//}
//void Texture2D::SetTextureSize(const char *FileName, ATATCONTENTSIZE Size)
//{
//	Texture2D::SetTextureSize(FileName, Size.Get_Width(), Size.Get_Height());
//}
//
//
//
//
//
//void Texture2D::DrawTexture(const void *CooryArr, const void *UV, int ID, const void *Index)
//{
//	ATENGINE->ATENGINE_VertexPointer(3, GL_FLOAT, 12, CooryArr);
//	ATENGINE->ATENGIEN_DrawTexturePointer(2, GL_FLOAT, 8, UV);
//	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, ID);
//	ATENGINE->ATENGINE_DrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, Index);
//}
//
//void Texture2D::NewMemory()
//{
//	if (m_TextureArr == NULL)
//	{
//		m_TextureArr = new unsigned int[m_CurCapacity];
//		memset(m_TextureArr, 0, sizeof(unsigned int) * m_CurCapacity);
//	}
//	else
//	{
//		//当前容量已经满了
//		if (m_CurCapacity == m_SaveMemory)
//		{
//			unsigned int *Temp = new unsigned int[m_CurCapacity + m_CapacityScale];
//			if (Temp)
//			{
//				memset(Temp, 0, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale));
//				memcpy_s(Temp, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale), m_TextureArr, sizeof(unsigned int) * m_CurCapacity);
//				delete[] m_TextureArr;
//				m_TextureArr = NULL;
//				m_TextureArr = new unsigned int[m_CurCapacity + m_CapacityScale];
//				if (m_TextureArr)
//				{
//					memset(m_TextureArr, 0, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale));
//					memcpy_s(m_TextureArr, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale), Temp, sizeof(unsigned int) * m_CurCapacity);
//					delete[] Temp;
//					Temp = NULL;
//				}
//			}
//		}
//
//		m_SaveMemory++;
//	}
//}

Texture2D::Texture2D()
{

}
Texture2D::Texture2D(const char *FileName)
{
	Texture2D::InitTexture(FileName);
}
void Texture2D::InitTexture(const char *FileName)
{
	Texture2D::LoadTexture(FileName);
}
Texture2D *Texture2D::Create(const char *FileName)
{
	//Texture2D *Texture = new (std::nothrow) Texture2D();
	//return Texture;

	Texture2D *Texture = new Texture2D(FileName);
	return Texture;
}
void Texture2D::LoadTexture(const char *FileName)
{
	unsigned int TextureArr[1] = { 0 };

	ATENGINE->ATENGINE_CreateTextureID(1, TextureArr);

	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, TextureArr[0]);

	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); // automatic mipmap generation included in OpenGL v1.4

	ATENGINE->ATENGINE_LoadTexture(
		GL_TEXTURE_2D,
		0,
		GL_RGB,
		ATENGINE->GetBitMapWidth(),
		ATENGINE->GetBitMapHeight(),
		0,
		GL_BGR_EXT,
		GL_UNSIGNED_BYTE,
		*ATENGINE->LoadBitMapRGBData(FileName));

	ATENGINE->ATENGINE_BindTextureEnd();

	m_TextureV.TID = TextureArr[0];

	m_TextureV.Width = ATENGINE->GetBitMapWidth();
	m_TextureV.Height = ATENGINE->GetBitMapHeight();

	m_TextureV.CooryArr[0] = -m_TextureV.Width / 2.0f;
	m_TextureV.CooryArr[1] = +m_TextureV.Height / 2.0f;
	m_TextureV.CooryArr[3] = -m_TextureV.Width / 2.0f;
	m_TextureV.CooryArr[4] = -m_TextureV.Height / 2.0f;
	m_TextureV.CooryArr[6] = +m_TextureV.Width / 2.0f;
	m_TextureV.CooryArr[7] = -m_TextureV.Height / 2.0f;
	m_TextureV.CooryArr[9] = +m_TextureV.Width / 2.0f;
	m_TextureV.CooryArr[10] = +m_TextureV.Height / 2.0f;
}

void Texture2D::DrawTexture2D()
{
	ATENGINE->ATENGINE_VertexPointer(3, GL_FLOAT, 12, m_TextureV.CooryArr);
	ATENGINE->ATENGIEN_DrawTexturePointer(2, GL_FLOAT, 8, m_TextureV.UV);
	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, m_TextureV.TID);
	ATENGINE->ATENGINE_DrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_TextureV.Index);
}



Texture::Texture()
{

}
Texture::Texture(const char *FileName)
{
	if (TM->LoadTexture(FileName))
	{
		m_FileName = FileName;
		Texture::AssignmentINFO();
	}
}
Texture::~Texture()
{
	Texture::DeleteTexture();
}
Texture *Texture::Create(const char *FileName)
{
	Texture *Textures = new Texture(FileName);
	return Textures;
}

void Texture::SetVisible(bool Visible)
{
	m_Visible = Visible;
}

void Texture::SetTag(int Tag)
{
	m_Tag = Tag;
}

void Texture::DrawTexture()
{
	if (m_Visible)
	{
		ATENGINE->ATENGINE_DisableCilentState(GL_COLOR_ARRAY);
		ATENGINE->ATENGINE_Enable(GL_TEXTURE_2D);

		ATENGINE->ATENGINE_VertexPointer(3, GL_FLOAT, 12, m_TextureINFO.CooryArr);
		ATENGINE->ATENGIEN_DrawTexturePointer(2, GL_FLOAT, 8, m_TextureINFO.UV);
		ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, m_TextureINFO.TID);
		ATENGINE->ATENGINE_DrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_TextureINFO.Index);

		ATENGINE->ATENGINE_EnableCilentState(GL_COLOR_ARRAY);
		ATENGINE->ATENGINE_Disable(GL_TEXTURE_2D);
	}
}

void Texture::DeleteTexture()
{
	ATENGINE->ATENGINE_DeleteTexture(1, &m_TextureINFO.TID);
}

void Texture::SetTextureInfo(TextureINFO *TextureINFO)
{
	m_TextureINFO.Width = TextureINFO->Width;
	m_TextureINFO.Height = TextureINFO->Height;
	//m_TextureINFO.TID = TextureINFO->TID;
	int Temp_i = sizeof(m_TextureINFO.Index) / sizeof(int);
	for (int i = 0; i < Temp_i; i++)
	{
		m_TextureINFO.Index[i] = TextureINFO->Index[i];
	}
	Temp_i = sizeof(m_TextureINFO.UV) / sizeof(float);
	for (int i = 0; i < Temp_i; i++)
	{
		m_TextureINFO.UV[i] = TextureINFO->UV[i];
	}
	Texture::SetTextureSize(ATATCONTENTSIZE(m_TextureINFO.Width, m_TextureINFO.Height));
}

void Texture::AssignmentINFO()
{
	m_TextureINFO.Width = TM->m_Width;
	m_TextureINFO.Height = TM->m_Height;
	m_TextureINFO.TID = TM->m_TextureID;


	m_TextureINFO.CooryArr[0] = -m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[1] = +m_TextureINFO.Height / 2.0f;
	m_TextureINFO.CooryArr[3] = -m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[4] = -m_TextureINFO.Height / 2.0f;
	m_TextureINFO.CooryArr[6] = +m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[7] = -m_TextureINFO.Height / 2.0f;
	m_TextureINFO.CooryArr[9] = +m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[10] = +m_TextureINFO.Height / 2.0f;
}

void Texture::SetTextureWidth(float Width)
{
	m_TextureINFO.CooryArr[0] = -Width / 2.0f;
	m_TextureINFO.CooryArr[3] = -Width / 2.0f;
	m_TextureINFO.CooryArr[6] = +Width / 2.0f;
	m_TextureINFO.CooryArr[9] = +Width / 2.0f;

	m_TextureINFO.Width = Width;
}
void Texture::SetTextureHeight(float Height)
{
	m_TextureINFO.CooryArr[1] = +Height / 2.0f;
	m_TextureINFO.CooryArr[4] = -Height / 2.0f;
	m_TextureINFO.CooryArr[7] = -Height / 2.0f;
	m_TextureINFO.CooryArr[10] = +Height / 2.0f;

	m_TextureINFO.Height = Height;
}
void Texture::SetTextureSize(ATATCONTENTSIZE Size)
{
	Texture::SetTextureWidth(Size.Get_Width());
	Texture::SetTextureHeight(Size.Get_Height());
}
void Texture::SetTexturePositionX(float X)
{
	if (X == _Position.x) { return; }

	m_TextureINFO.CooryArr[0] = -m_TextureINFO.Width / 2.0f + X;
	m_TextureINFO.CooryArr[3] = -m_TextureINFO.Width / 2.0f + X;
	m_TextureINFO.CooryArr[6] = +m_TextureINFO.Width / 2.0f + X;
	m_TextureINFO.CooryArr[9] = +m_TextureINFO.Width / 2.0f + X;

	_Position.x = X;
}
void Texture::SetTexturePositionY(float Y)
{
	if (Y == _Position.y) { return; }

	m_TextureINFO.CooryArr[1] = m_TextureINFO.Height / 2.0f + Y;
	m_TextureINFO.CooryArr[4] = -m_TextureINFO.Height / 2.0f + Y;
	m_TextureINFO.CooryArr[7] = -m_TextureINFO.Height / 2.0f + Y;
	m_TextureINFO.CooryArr[10] = m_TextureINFO.Height / 2.0f + Y;

	_Position.y = Y;
}
void Texture::SetTexturePosition(float X, float Y)
{
	Texture::SetTexturePositionX(X);
	Texture::SetTexturePositionY(Y);
}
void Texture::SetTexturePosition(ATATPOS2D Position)
{
	Texture::SetTexturePosition(Position.X, Position.Y);
}
void Texture::SetTexturePosition(ATATPOS2D *Position)
{
	Texture::SetTexturePosition(*Position);
}
void Texture::SetTexturePosition(ATVector2D Position)
{
	Texture::SetTexturePosition(Position.x, Position.y);
}
void Texture::SetTexturePosition(ATVector2D *Position)
{
	Texture::SetTexturePosition(*Position);
}


//拷贝构造
Texture::Texture(const Texture& that)
{
	this->m_FileName = that.m_FileName;
	this->m_Tag = that.m_Tag;
	
	memcpy_s(&(this->m_TextureINFO),sizeof(this->m_TextureINFO),&(that.m_TextureINFO),sizeof(this->m_TextureINFO));
	this->m_Visible = that.m_Visible;
}

//同类赋值 重载 = 运算符
Texture& Texture::operator = (const Texture& that)
{
	this->m_FileName = that.m_FileName;
	this->m_Tag = that.m_Tag;

	memcpy_s(&(this->m_TextureINFO), sizeof(this->m_TextureINFO), &(that.m_TextureINFO), sizeof(this->m_TextureINFO));
	this->m_Visible = that.m_Visible;
	return *this;
}




//================================================
	/*
	扩展
	*/
Texture *Texture::CreateEx(string FileName)
{
	Texture *texture = new Texture();
	gl_texture_t *GL_Texture = texture->LoadPNGEx(FileName);
	texture->BindTextureEx(GL_Texture);
	return texture;
}

gl_texture_t *Texture::LoadPNGEx(string FileName)
{
	gl_texture_t *texinfo;
	png_byte magic[8];
	png_structp png_ptr;
	png_infop info_ptr;
	int bit_depth, color_type;
	FILE *fp = NULL;
	png_bytep *row_pointers = NULL;
	png_uint_32 w, h;
	int i;
	/* Open image file */
	fopen_s(&fp, FileName.c_str(), "rb");
	if (!fp)
	{
		fprintf(stderr, "error: couldn't open \"%s\"!\n", FileName.c_str());
		return NULL;
	}
	/* Read magic number */
	fread(magic, 1, sizeof(magic), fp);
	/* Check for valid magic number */
	if (!png_check_sig(magic, sizeof(magic)))
	{
		fprintf(stderr, "error: \"%s\" is not a valid PNG image!\n", FileName.c_str());
		fclose(fp);
		return NULL;
	}
	/* Create a png read struct */
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		fclose(fp);
		return NULL;
	}
	/* Create a png info struct */
	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		fclose(fp);
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return NULL;
	}
	/* Create our OpenGL texture object */
	texinfo = (gl_texture_t *)malloc(sizeof(gl_texture_t));
	/* Initialize the setjmp for returning properly after a libpng error occured */
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		fclose(fp);
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		if (row_pointers) free(row_pointers);
		if (texinfo) {
			if (texinfo->texels)
				free(texinfo->texels);
			free(texinfo);
		}
		return NULL;
	}
	/* Setup libpng for using standard C fread() function with our FILE pointer */
	png_init_io(png_ptr, fp);
	/* Tell libpng that we have already read the magic number */
	png_set_sig_bytes(png_ptr, sizeof(magic));
	/* Read png info */
	png_read_info(png_ptr, info_ptr);
	/* Get some usefull information from header */
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	/* Convert index color images to RGB images */
	if (color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png_ptr);
	/* Convert 1-2-4 bits grayscale images to 8 bits grayscale. */
	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png_ptr);

	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png_ptr);
	if (bit_depth == 16) png_set_strip_16(png_ptr);
	else if (bit_depth < 8) png_set_packing(png_ptr);
	/* Update info structure to apply transformations */
	png_read_update_info(png_ptr, info_ptr);
	/* Retrieve updated information */
	png_get_IHDR(png_ptr, info_ptr, &w, &h, &bit_depth, &color_type, NULL, NULL, NULL);
	texinfo->width = w;
	texinfo->height = h;
	/* Get image format and components per pixel */
	Texture::GetPNGtextureInfoEx(color_type, texinfo);
	/* We can now allocate memory for storing pixel data */
	texinfo->texels = (GLubyte *)malloc(sizeof(GLubyte) * texinfo->width * texinfo->height * texinfo->internalFormat);
	/* Setup a pointer array. Each one points at the begening of a row. */
	row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * texinfo->height);
	for (i = 0; i < texinfo->height; ++i)
	{
		row_pointers[i] = (png_bytep)(texinfo->texels + ((texinfo->height - (i + 1)) * texinfo->width * texinfo->internalFormat));
	}
	/* Read pixel data using row pointers */
	png_read_image(png_ptr, row_pointers);
	/* Finish decompression and release memory */
	png_read_end(png_ptr, NULL);
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	/* We don't need row pointers anymore */
	free(row_pointers);
	fclose(fp);
	return texinfo;
}

void Texture::GetPNGtextureInfoEx(int color_type, gl_texture_t *texinfo)
{
	switch (color_type)
	{
	case PNG_COLOR_TYPE_GRAY:
		texinfo->format = GL_LUMINANCE;
		texinfo->internalFormat = 1;
		break;

	case PNG_COLOR_TYPE_GRAY_ALPHA:
		texinfo->format = GL_LUMINANCE_ALPHA;
		texinfo->internalFormat = 2;
		break;

	case PNG_COLOR_TYPE_RGB:
		texinfo->format = GL_RGB;
		texinfo->internalFormat = 3;
		break;

	case PNG_COLOR_TYPE_RGB_ALPHA:
		texinfo->format = GL_RGBA;
		texinfo->internalFormat = 4;
		break;

	default:
		/* Badness */
		break;
	}
}

void Texture::BindTextureEx(gl_texture_t *GL_Texture)
{
	GLint alignment;
	if (GL_Texture && GL_Texture->texels)
	{
		/* Generate texture */
		glGenTextures(1, &GL_Texture->id);
		glBindTexture(GL_TEXTURE_2D, GL_Texture->id);
		/* Setup some parameters for texture filters and mipmapping */
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		glGetIntegerv(GL_UNPACK_ALIGNMENT, &alignment);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_Texture->internalFormat, GL_Texture->width, GL_Texture->height, 0, GL_Texture->format, GL_UNSIGNED_BYTE, GL_Texture->texels);
		glPixelStorei(GL_UNPACK_ALIGNMENT, alignment);
	}
	Texture::AssignmentINFOEx(GL_Texture);
	/* OpenGL has its own copy of texture data */
	free(GL_Texture->texels);
	free(GL_Texture);
}

void Texture::AssignmentINFOEx(gl_texture_t *GL_Texture)
{
	m_TextureINFO.Width = GL_Texture->width;
	m_TextureINFO.Height = GL_Texture->height;
	m_TextureINFO.TID = GL_Texture->id;


	m_TextureINFO.CooryArr[0] = -m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[1] = +m_TextureINFO.Height / 2.0f;
	m_TextureINFO.CooryArr[3] = -m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[4] = -m_TextureINFO.Height / 2.0f;
	m_TextureINFO.CooryArr[6] = +m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[7] = -m_TextureINFO.Height / 2.0f;
	m_TextureINFO.CooryArr[9] = +m_TextureINFO.Width / 2.0f;
	m_TextureINFO.CooryArr[10] = +m_TextureINFO.Height / 2.0f;
}