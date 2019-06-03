#include "Textures.h"

//=====================================================================Texture2D
Texture2D::Texture2D()
{
	Texture2D::NewMemory();
}
Texture2D::~Texture2D()
{
	if (m_TextureArr)
	{
		ATENGINE->ATENGINE_DeleteTexture(m_SaveMemory, m_TextureArr);
		delete[] m_TextureArr;
		m_TextureArr = NULL;
		if (!m_TextureMap.empty())
		{
			m_TextureMap.clear();
		}
	}
}

T_2D Texture2D::Create(const char *FileName, unsigned int PARAM)
{
	Texture2D::NewMemory();

	map<string, TextureV>::iterator it = m_TextureMap.find(FileName);
	if (it != m_TextureMap.end())//存在
	{
		return it->second.TID;
	}

	ATENGINE->ATENGINE_CreateTextureID(1, m_TextureArr);

	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, m_TextureArr[m_TextureArrIndex]);

	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, PARAM);
	ATENGINE->ATENGINE_TexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, PARAM);

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

	m_TextureArrIndex++;
	
	TextureV textureV;
	textureV.Width = ATENGINE->GetBitMapWidth();
	textureV.Height = ATENGINE->GetBitMapHeight();

	textureV.CooryArr[0] = -textureV.Width / 2.0f;
	textureV.CooryArr[1] = +textureV.Height / 2.0f;
	textureV.CooryArr[3] = -textureV.Width / 2.0f;
	textureV.CooryArr[4] = -textureV.Height / 2.0f;
	textureV.CooryArr[6] = +textureV.Width / 2.0f;
	textureV.CooryArr[7] = -textureV.Height / 2.0f;
	textureV.CooryArr[9] = +textureV.Width / 2.0f;
	textureV.CooryArr[10] = +textureV.Height / 2.0f;

	m_TextureMap.insert(pair<string, TextureV>(FileName, textureV));

	return m_TextureArr[m_TextureArrIndex - 1];
}

T_2D Texture2D::Create(const char *FileName)
{
	Texture2D::NewMemory();

	map<string, TextureV>::iterator it = m_TextureMap.find(FileName);
	if (it != m_TextureMap.end())//存在
	{
		return it->second.TID;
	}

	ATENGINE->ATENGINE_CreateTextureID(1, m_TextureArr);

	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, m_TextureArr[m_TextureArrIndex]);

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

	m_TextureArrIndex++;

	TextureV textureV;

	textureV.TID = m_TextureArr[m_TextureArrIndex - 1];

	textureV.Width = ATENGINE->GetBitMapWidth();
	textureV.Height = ATENGINE->GetBitMapHeight();

	textureV.CooryArr[0] = -textureV.Width / 2.0f;
	textureV.CooryArr[1] = +textureV.Height / 2.0f;
	textureV.CooryArr[3] = -textureV.Width / 2.0f;
	textureV.CooryArr[4] = -textureV.Height / 2.0f;
	textureV.CooryArr[6] = +textureV.Width / 2.0f;
	textureV.CooryArr[7] = -textureV.Height / 2.0f;
	textureV.CooryArr[9] = +textureV.Width / 2.0f;
	textureV.CooryArr[10] = +textureV.Height / 2.0f;

	m_TextureMap.insert(pair<string, TextureV>(FileName, textureV));

	return m_TextureArr[m_TextureArrIndex - 1];
}

void Texture2D::DrawTexture(int ID)
{
	if (!m_TextureMap.empty())
	{
		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
		{
			if (it->second.TID == ID)
			{
				Texture2D::DrawTexture(it->second.CooryArr,it->second.UV,it->second.TID,it->second.Index);
			}
		}
	}
}
void Texture2D::DrawTexture(const char *FileName)
{
	if (!m_TextureMap.empty())
	{
		for (map<string, TextureV>::iterator it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
		{
			if (it->first == FileName)
			{
				Texture2D::DrawTexture(it->second.CooryArr, it->second.UV, it->second.TID, it->second.Index);
			}
		}
	}
}
void Texture2D::SetTextureWidth(int ID, int Width)
{

}
void Texture2D::SetTextureHeight(int ID, int Height)
{

}
void Texture2D::SetTextureSize(int ID, ATATCONTENTSIZE Size)
{

}

void Texture2D::DrawTexture(const void *CooryArr, const void *UV, int ID, const void *Index)
{
	ATENGINE->ATENGINE_VertexPointer(3, GL_FLOAT, 12, CooryArr);
	ATENGINE->ATENGIEN_DrawTexturePointer(2, GL_FLOAT, 8, UV);
	ATENGINE->ATENGINE_BindTextureID(GL_TEXTURE_2D, ID);
	ATENGINE->ATENGINE_DrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, Index);
}

void Texture2D::NewMemory()
{
	if (m_TextureArr == NULL)
	{
		m_TextureArr = new unsigned int[m_CurCapacity];
		memset(m_TextureArr, 0, sizeof(unsigned int) * m_CurCapacity);
	}
	else
	{
		//当前容量已经满了
		if (m_CurCapacity == m_SaveMemory)
		{
			unsigned int *Temp = new unsigned int[m_CurCapacity + m_CapacityScale];
			if (Temp)
			{
				memset(Temp, 0, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale));
				memcpy_s(Temp, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale), m_TextureArr, sizeof(unsigned int) * m_CurCapacity);
				delete[] m_TextureArr;
				m_TextureArr = NULL;
				m_TextureArr = new unsigned int[m_CurCapacity + m_CapacityScale];
				if (m_TextureArr)
				{
					memset(m_TextureArr, 0, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale));
					memcpy_s(m_TextureArr, sizeof(unsigned int) * (m_CurCapacity + m_CapacityScale), Temp, sizeof(unsigned int) * m_CurCapacity);
					delete[] Temp;
					Temp = NULL;
				}
			}
		}

		m_SaveMemory++;
	}
}












//=====================================================================Texture3D
Texture3D::Texture3D()
{

}
