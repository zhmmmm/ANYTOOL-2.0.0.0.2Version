#include "ATBAudioEngine.h"

ATBAE::ATBAE()
{
	ATBAE::InitAudioEngine();
}
ATBAE::ATBAE(const ATBAE& that)
{
	//this->... = than...;
}
ATBAE& ATBAE::operator = (const ATBAE& that)
{
	//this->... = than...;
	return *this;
}


ATBAE::~ATBAE()
{
	ATBAE::FreeATA();
}
ATBAE *ATBAE::GetInstance()
{
	static ATBAE A_T_B_A_E;
	return &A_T_B_A_E;
}

BOOL ATBAE::InitAudioEngine()
{
	if (!m_IsInit)
	{
		if (HIWORD(BASS_GetVersion()) != BASSVERSION)
		{
			return FALSE;
		}
		if (BASS_Init(-1, SAMPLING_RATE, BASS_DEVICE_3D, NULL, NULL))
		{
			m_IsInit = TRUE;
			ATBAE::SetVolume();
			return TRUE;
		}
	}
	return FALSE;
}

BOOL ATBAE::UninstallAudioEngine()
{
	if (m_IsInit)
	{
		return ATBAE::FreeATA();
	}
	return FALSE;
}

BOOL ATBAE::LoadMusics(string MusicFileName, DWORD Flags)
{
	map<string, HSTREAM>::iterator it = m_MusicMap.find(MusicFileName);
	if (it != m_MusicMap.end())//存在
	{
		return TRUE;
	}
	HSTREAM HStream = BASS_StreamCreateFile(FALSE, MusicFileName.c_str(), 0, 0, Flags);//从文件加载音乐
	if (HStream == NULL)
	{
		//加载失败
		return FALSE;
	}
	//make_pair
	m_MusicMap.insert(pair<string, HSTREAM>(MusicFileName, HStream));
	return TRUE;
}

BOOL ATBAE::LoadMusicsAndPlay(string MusicFileName, DWORD Flags)
{
	if (ATBAE::LoadMusics(MusicFileName,Flags))
	{
		return ATBAE::PlayMusics(MusicFileName);
	}
	return FALSE;
}

BOOL ATBAE::LoadEffects(string EffectFileName, DWORD Flags)
{
	map<string, HSTREAM>::iterator it = m_EffectMap.find(EffectFileName);
	if (it != m_EffectMap.end())//存在
	{
		return TRUE;
	}
	HSTREAM HStream = BASS_StreamCreateFile(FALSE, EffectFileName.c_str(), 0, 0, Flags);//从文件加载音乐
	if (HStream == NULL)
	{
		//加载失败
		return FALSE;
	}
	//make_pair
	m_EffectMap.insert(pair<string, HSTREAM>(EffectFileName, HStream));
	return TRUE;
}

BOOL ATBAE::LoadEffectsAndPlay(string EffectFileName, DWORD Flags)
{
	if (ATBAE::LoadEffects(EffectFileName, Flags))
	{
		return ATBAE::PlayEffects(EffectFileName);
	}
	return FALSE;
}

BOOL ATBAE::SetVolume(int Volume)
{
	if (m_IsInit)
	{
		if (Volume <= 0)
		{
			Volume = 0;
		}
		else if (Volume >= 100)
		{
			Volume = 100;
		}
		m_Volume = (unsigned long)Volume;
		return BASS_SetConfig(BASS_CONFIG_GVOL_STREAM, m_Volume * 100);
	}
	return FALSE;
}

HSTREAM ATBAE::GetStream(string AudioFileName)
{
	if (m_IsInit)
	{
		map<string, HSTREAM>::iterator it = m_MusicMap.find(AudioFileName);
		if (it != m_MusicMap.end())
		{
			return it->second;
		}
		it = m_EffectMap.find(AudioFileName);
		if (it != m_EffectMap.end())
		{
			return it->second;
		}
	}
	return 0;
}

BOOL ATBAE::VolumeReduce()
{
	if (m_IsInit)
	{
		m_Volume -= 1;
		ATBAE::SetVolume(m_Volume);
		return TRUE;
	}
	return FALSE;
}

BOOL ATBAE::VolumeAdd()
{
	if (m_IsInit)
	{
		m_Volume += 1;
		ATBAE::SetVolume(m_Volume);
		return TRUE;
	}
	return FALSE;
}

//=================================================================
DWORD ATBAE::GetAudioStreamData(string AudioFileName, void *Buffer)
{
	if (m_IsInit)
	{
		map<string, HSTREAM>::iterator it = m_MusicMap.find(AudioFileName);
		if (it != m_MusicMap.end())
		{
			return BASS_ChannelGetData(it->second, Buffer, 2147483648);
		}
		it = m_EffectMap.find(AudioFileName);
		if (it != m_EffectMap.end())
		{
			return BASS_ChannelGetData(it->second, Buffer, 2147483648);
		}
	}
	return 0;
}


BOOL ATBAE::Init3DAudioEngine()
{
	return BASS_Set3DFactors(1, 1, 1);
}
BOOL ATBAE::Set3DFactors(float distf, float rollf, float doppf)
{
	return BASS_Set3DFactors(distf, rollf, doppf);
}

BOOL ATBAE::LoadMusics3D(string MusicFileName, DWORD Flags)
{
	map<string, HSTREAM>::iterator it = m_MusicMap.find(MusicFileName);
	if (it != m_MusicMap.end())//存在
	{
		return TRUE;
	}
	HSTREAM HStream = BASS_SampleLoad(FALSE, MusicFileName.c_str(), 0, 0, 1, Flags);//从文件加载音乐
	BASS_SampleGetChannel(HStream, FALSE);
	if (HStream == NULL)
	{
		//加载失败
		return FALSE;
	}
	//make_pair
	m_MusicMap.insert(pair<string, HSTREAM>(MusicFileName, HStream));
	return TRUE;
}
BOOL ATBAE::LoadMusics3DAndPlay(string MusicFileName, DWORD Flags)
{
	if (ATBAE::LoadMusics3D(MusicFileName, Flags))
	{
		return ATBAE::PlayMusics(MusicFileName);
	}
	return FALSE;
}
BOOL ATBAE::LoadEffects3D(string EffectFileName, DWORD Flags)
{
	map<string, HSTREAM>::iterator it = m_EffectMap.find(EffectFileName);
	if (it != m_EffectMap.end())//存在
	{
		return TRUE;
	}
	HSTREAM HStream = BASS_SampleLoad(FALSE, EffectFileName.c_str(), 0, 0, 1, Flags);//从文件加载音乐
	BASS_SampleGetChannel(HStream, FALSE);
	if (HStream == NULL)
	{
		//加载失败
		return FALSE;
	}
	//make_pair
	m_EffectMap.insert(pair<string, HSTREAM>(EffectFileName, HStream));
	return TRUE;
}
BOOL ATBAE::LoadEffects3DAndPlay(string EffectFileName, DWORD Flags)
{
	if (ATBAE::LoadEffects3D(EffectFileName, Flags))
	{
		return ATBAE::PlayEffects(EffectFileName);
	}
	return FALSE;
}

BOOL ATBAE::SetMusics3DPos(BASS_3DVECTOR Pos, BASS_3DVECTOR Vel)
{
	BOOL ISSeting = FALSE;
	string CurPlayMusic = ATBAE::GetCurPlayMusic();
	if (!CurPlayMusic.empty())
	{
		HSTREAM HStream = ATBAE::GetStream(CurPlayMusic);
		if (BASS_ChannelIsActive(HStream) == BASS_ACTIVE_PLAYING)
		{
			ISSeting = BASS_ChannelSet3DPosition((DWORD)HStream, &Pos, NULL, &Vel);
		}
	}
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetEffects3DPos(BASS_3DVECTOR Pos, BASS_3DVECTOR Vel)
{
	BOOL ISSeting = FALSE;
	string CurPlayEffects = ATBAE::GetCurPlayEffect();
	if (!CurPlayEffects.empty())
	{
		HSTREAM HStream = ATBAE::GetStream(CurPlayEffects);
		if (BASS_ChannelIsActive(HStream) == BASS_ACTIVE_PLAYING)
		{
			ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &Vel);
		}
	}
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetMusics3DPos(BASS_3DVECTOR Pos)
{
	BASS_3DVECTOR Vel;
	Vel.x = 0;
	Vel.y = 0;
	Vel.z = 0;
	return ATBAE::SetMusics3DPos(Pos, Vel);
}
BOOL ATBAE::SetEffects3DPos(BASS_3DVECTOR Pos)
{
	BASS_3DVECTOR Vel;
	Vel.x = 0;
	Vel.y = 0;
	Vel.z = 0;
	return ATBAE::SetEffects3DPos(Pos, Vel);
}

BOOL ATBAE::SetMusics3DPos(string MusicFileName, BASS_3DVECTOR Pos)
{
	BOOL ISSeting = FALSE;
	if (!MusicFileName.empty())
	{
		HSTREAM HStream = ATBAE::GetStream(MusicFileName);
		BASS_ChannelIsActive(HStream);
		ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &m_Vel);
	}
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetEffects3DPos(string EffectFileName, BASS_3DVECTOR Pos)
{
	BOOL ISSeting = FALSE;
	if (!EffectFileName.empty())
	{
		HSTREAM HStream = ATBAE::GetStream(EffectFileName);
		BASS_ChannelIsActive(HStream);
		ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &m_Vel);
	}
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetMusics3DPos(string MusicFileName, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel)
{
	BOOL ISSeting = FALSE;
	if (!MusicFileName.empty())
	{
		HSTREAM HStream = ATBAE::GetStream(MusicFileName);
		BASS_ChannelIsActive(HStream);
		ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &Vel);
	}
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetEffects3DPos(string EffectFileName, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel)
{
	BOOL ISSeting = FALSE;
	if (!EffectFileName.empty())
	{
		HSTREAM HStream = ATBAE::GetStream(EffectFileName);
		BASS_ChannelIsActive(HStream);
		ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &Vel);
	}
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetMusics3DPos(HSTREAM HStream, BASS_3DVECTOR Pos)
{
	BOOL ISSeting = FALSE;
	BASS_ChannelIsActive(HStream);
	ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &m_Vel);
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetEffects3DPos(HSTREAM HStream, BASS_3DVECTOR Pos)
{
	BOOL ISSeting = FALSE;
	BASS_ChannelIsActive(HStream);
	ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &m_Vel);
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetMusics3DPos(HSTREAM HStream, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel)
{
	BOOL ISSeting = FALSE;
	BASS_ChannelIsActive(HStream);
	ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &Vel);
	BASS_Apply3D();
	return ISSeting;
}
BOOL ATBAE::SetEffects3DPos(HSTREAM HStream, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel)
{
	BOOL ISSeting = FALSE;
	BASS_ChannelIsActive(HStream);
	ISSeting = BASS_ChannelSet3DPosition(HStream, &Pos, NULL, &Vel);
	BASS_Apply3D();
	return ISSeting;
}











BOOL ATBAE::PlayMusics(string MusicFileName, BOOL Restart)
{
	map<string, HSTREAM>::iterator it = m_MusicMap.find(MusicFileName);
	if (it != m_MusicMap.end())//存在
	{
		BASS_ChannelPlay(it->second, Restart);
		m_CurPlayMusics = MusicFileName;
		m_IsPlayMusic = TRUE;
		return TRUE;
	}
	if (ATBAE::LoadMusics(MusicFileName))
	{
		ATBAE::PlayMusics(MusicFileName);
	}
	else
	{
		return FALSE;
	}
	//这个return 只是消除警告,没有实际意义
	return TRUE;
}
BOOL ATBAE::PlayMusics_s(string MusicFileName, BOOL Restart)
{
	if (!m_IsPlayMusic)
	{
		return ATBAE::PlayMusics(MusicFileName, Restart);
	}
	return FALSE;
}
BOOL ATBAE::PlayEffects(string EffectFileName)
{
	map<string, HSTREAM>::iterator it = m_EffectMap.find(EffectFileName);
	if (it != m_EffectMap.end())//存在
	{
		BASS_ChannelPlay(it->second, TRUE);
		m_CurPlayEffects = EffectFileName;
		return TRUE;
	}
	if (ATBAE::LoadEffects(EffectFileName))
	{
		ATBAE::PlayEffects(EffectFileName);
	}
	else
	{
		return FALSE;
	}
	//这个return 只是消除警告,没有实际意义
	return TRUE;
}
BOOL ATBAE::PlayStream(HSTREAM HStream, BOOL Restart)
{
	if (m_IsInit)
	{
		return BASS_ChannelPlay(HStream, Restart);
	}
	return FALSE;
}

BOOL ATBAE::PauseMusics(string MusicFileName)
{
	if (m_IsInit && m_IsPlayMusic)
	{
		map<string, HSTREAM>::iterator it = m_MusicMap.find(MusicFileName);
		if (it != m_MusicMap.end())
		{
			return BASS_ChannelPause(it->second);
		}
	}
	return FALSE;
}
BOOL ATBAE::PauseEffects(string EffectFileName)
{
	if (m_IsInit)
	{
		map<string, HSTREAM>::iterator it = m_EffectMap.find(EffectFileName);
		if (it != m_EffectMap.end())
		{
			return BASS_ChannelPause(it->second);
		}
	}
	return FALSE;
}
BOOL ATBAE::PauseAllMusics()
{
	if (m_IsInit)
	{
		if (!m_MusicMap.empty())
		{
			for (map<string, HSTREAM>::iterator it = m_MusicMap.begin(); it != m_MusicMap.end(); it++)
			{
				BASS_ChannelPause(it->second);
			}
			return TRUE;
		}
	}
	return FALSE;
}
BOOL ATBAE::PauseAllEffects()
{
	if (m_IsInit)
	{
		if (!m_EffectMap.empty())
		{
			for (map<string, HSTREAM>::iterator it = m_EffectMap.begin(); it != m_EffectMap.end(); it++)
			{
				BASS_ChannelPause(it->second);
			}
			return TRUE;
		}
	}
	return FALSE;
}
BOOL ATBAE::PauseAllMusicAndEffects()
{
	BOOL Music = ATBAE::PauseAllMusics();
	BOOL Sound = ATBAE::PauseAllEffects();
	if (Music && Sound)
	{
		return TRUE;
	}
	return FALSE;
}

BOOL ATBAE::StopMusics(string MusicFileName)
{
	if (m_IsInit && m_IsPlayMusic)
	{
		map<string, HSTREAM>::iterator it = m_MusicMap.find(MusicFileName);
		if (it != m_MusicMap.end())
		{
			return BASS_ChannelStop(it->second);
		}
	}
	return FALSE;
}
BOOL ATBAE::StopEffects(string EffectFileName)
{
	if (m_IsInit)
	{
		map<string, HSTREAM>::iterator it = m_EffectMap.find(EffectFileName);
		if (it != m_EffectMap.end())
		{
			return BASS_ChannelStop(it->second);
		}
	}
	return FALSE;
}
BOOL ATBAE::StopAllMusics()
{
	if (m_IsInit)
	{
		if (!m_MusicMap.empty())
		{
			for (map<string, HSTREAM>::iterator it = m_MusicMap.begin(); it != m_MusicMap.end(); it++)
			{
				BASS_ChannelStop(it->second);
			}
			return TRUE;
		}
	}
	return FALSE;
}
BOOL ATBAE::StopAllEffects()
{
	if (m_IsInit)
	{
		if (!m_EffectMap.empty())
		{
			for (map<string, HSTREAM>::iterator it = m_EffectMap.begin(); it != m_EffectMap.end(); it++)
			{
				BASS_ChannelStop(it->second);
			}
			return TRUE;
		}
	}
	return FALSE;
}
BOOL ATBAE::StopAllMusicAndEffects()
{
	BOOL Music = ATBAE::StopAllMusics();
	BOOL Sound = ATBAE::StopAllEffects();
	if (Music && Sound)
	{
		return TRUE;
	}
	return FALSE;
}


void ATBAE::DeleteMusic(string MusicFileName)
{
	ATBAE::StopMusics(MusicFileName);
	map<string, HSTREAM>::iterator it = m_MusicMap.find(MusicFileName);
	if (it != m_MusicMap.end())
	{
		BOOL Free = BASS_StreamFree(it->second);
		m_MusicMap.erase(it);
	}
}
void ATBAE::DeleteEffect(string EffectFileName)
{
	map<string, HSTREAM>::iterator it = m_EffectMap.find(EffectFileName);
	if (it != m_EffectMap.end())
	{
		BOOL Free = BASS_StreamFree(it->second);
		m_EffectMap.erase(it);
	}
}
void ATBAE::DeleteAllMusic()
{
	if (!m_MusicMap.empty())
	{
		for (map<string, HSTREAM>::iterator it = m_MusicMap.begin(); it != m_MusicMap.end(); it++)
		{
			BASS_StreamFree(it->second);
		}
		m_MusicMap.clear();
	}
}
void ATBAE::DeleteAllEffect()
{
	if (!m_EffectMap.empty())
	{
		for (map<string, HSTREAM>::iterator it = m_EffectMap.begin(); it != m_EffectMap.end(); it++)
		{
			BASS_StreamFree(it->second);
		}
		m_EffectMap.clear();
	}
}
void ATBAE::DeleteAllMusicAndEffects()
{
	ATBAE::DeleteAllMusic();
	ATBAE::DeleteAllEffect();
}
BOOL ATBAE::FreeATA()
{
	if (m_IsInit)
	{
		ATBAE::StopAllMusicAndEffects();

		ATBAE::DeleteAllMusic();
		ATBAE::DeleteAllEffect();
		BASS_Free();
		m_IsInit = FALSE;
		return TRUE;
	}
	return FALSE;
}


double ATBAE::GetTimeSecond(string MusicFileName)
{
	if (m_IsInit)
	{
		HSTREAM Stream = ATBAE::GetStream(MusicFileName);
		unsigned __int64 StreamLen = BASS_ChannelGetLength(Stream, BASS_POS_BYTE);
		return BASS_ChannelBytes2Seconds(Stream, StreamLen);
	}
	return 0;
}
double ATBAE::GetTimeMinute(string MusicFileName)
{
	return ATBAE::GetTimeSecond(MusicFileName) / 60.0;
}
double ATBAE::GetTimeHour(string MusicFileName)
{
	return ATBAE::GetTimeMinute(MusicFileName) / 60.0;
}
double ATBAE::GetCurTimeSecond(string MusicFileName)
{
	if (m_IsInit)
	{
		HSTREAM Stream = ATBAE::GetStream(MusicFileName);
		return BASS_ChannelBytes2Seconds(Stream, BASS_ChannelGetPosition(Stream, BASS_POS_BYTE));
	}
	return 0;
}
double ATBAE::GetCurTimeMinute(string MusicFileName)
{
	return ATBAE::GetCurTimeSecond(MusicFileName) / 60.0;
}
double ATBAE::GetCurTimeHour(string MusicFileName)
{
	return ATBAE::GetCurTimeMinute(MusicFileName) / 60.0;
}
unsigned __int64 ATBAE::GetCurPoint(string MusicFileName)
{
	if (m_IsInit)
	{
		return BASS_ChannelGetPosition(ATBAE::GetStream(MusicFileName), BASS_POS_BYTE);
	}
	return 0;
}
BOOL ATBAE::SetTimeSecond(string MusicFileName, double Second)
{
	if (m_IsInit)
	{
		HSTREAM Stream = ATBAE::GetStream(MusicFileName);
		unsigned __int64 CurPoint = BASS_ChannelSeconds2Bytes(Stream, Second);
		ATBAE::PauseMusics(MusicFileName);
		if (BASS_ChannelSetPosition(Stream, CurPoint, BASS_POS_BYTE))
		{
			return ATBAE::PlayMusics(MusicFileName, FALSE);
		}
	}
	return FALSE;
}
BOOL ATBAE::SetTimeMinute(string MusicFileName, double Minute)
{
	return ATBAE::SetTimeSecond(MusicFileName, Minute * 60.0);
}
BOOL ATBAE::SetTimeHour(string MusicFileName, double Hour)
{
	return ATBAE::SetTimeMinute(MusicFileName, Hour * 60.0);
}