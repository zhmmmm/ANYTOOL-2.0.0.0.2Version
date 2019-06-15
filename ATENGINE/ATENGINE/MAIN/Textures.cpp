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



Texture::Texture(){}
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

void Texture::DrawTexture()
{
	ATENGINE->ATENGINE_VertexPointer(3, GL_FLOAT, 12, m_TextureINFO.CooryArr);
	ATENGINE->ATENGIEN_DrawTexturePointer(2, GL_FLOAT, 8, m_TextureINFO.UV);
	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, m_TextureINFO.TID);
	ATENGINE->ATENGINE_DrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_TextureINFO.Index);
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