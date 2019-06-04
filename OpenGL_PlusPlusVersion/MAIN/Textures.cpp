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
Texture2D *Texture2D::create(const char *FileName)
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







//=====================================================================Texture3D
Texture3D::Texture3D()
{

}
