#pragma once
#include <map>
#include <string>
#include "BASS\\include\\bass.h"
#pragma comment(lib,"../../MAIN\\ATBAudioEngine\\BASS\\lib\\bass.lib")
//两种包含都可以
//#pragma comment(lib,"MAIN\\ATBAudioEngine\\BASS\\lib\\bass.lib")

using namespace std;


#define ATA ATBAE::GetInstance()
#define SAMPLING_RATE (44100) //音乐采样率

//AT BASS 音频 引擎
/*采取的是流播放,还有更多的功能*/
class _declspec(dllexport) ATBAE
{
	//是否初始化
	BOOL m_IsInit = FALSE;
	//音乐Map
	map<string, HSTREAM> m_MusicMap;
	//音效Map
	map<string, HSTREAM> m_EffectMap;

	//音量
	unsigned long m_Volume = 100;
	BOOL m_IsPlayMusic = FALSE;
	//当前播放的音乐
	string m_CurPlayMusics;
	//当前播放的音效
	string m_CurPlayEffects;


	BASS_3DVECTOR m_Pos;
	BASS_3DVECTOR m_Vel;
public:
	static ATBAE *GetInstance();
	BOOL InitAudioEngine();
	BOOL UninstallAudioEngine();

	BOOL LoadMusics(string MusicFileName, DWORD Flags = BASS_SAMPLE_LOOP);
	BOOL LoadMusicsAndPlay(string MusicFileName, DWORD Flags = BASS_SAMPLE_LOOP);
	BOOL LoadEffects(string EffectFileName, DWORD Flags = BASS_SAMPLE_MONO);
	BOOL LoadEffectsAndPlay(string EffectFileName, DWORD Flags = BASS_SAMPLE_MONO);
	BOOL SetVolume(int Volume = 100);
	DWORD GetVolume() { return m_Volume; }
	string GetCurPlayMusic() { return m_CurPlayMusics; }
	string GetCurPlayEffect() { return m_CurPlayEffects; }
	HSTREAM GetStream(string AudioFileName);
	BOOL VolumeReduce();//--
	BOOL VolumeAdd();//++
	//=================================================================
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	/*
	static int W = 3;
	static int WSpace = 1;
	static int Y = 190;
	void Scene::Update()
	{
		ATA->PlayMusics_s("res\\Audio\\Musics\\夜色.flac");
		Camera::CameraToWorld(this);
		this->m_CameraPos_Y = 0;
		//AT->CreateQuadrangle(
		//	ATATRGB::RED, ATATPOS3D(-105, +205, 0),
		//	ATATRGB::WHITE, ATATPOS3D(-105, -105, 0),
		//	ATATRGB::WHITE, ATATPOS3D(+105, -105, 0),
		//	ATATRGB::RED, ATATPOS3D(+105, +105, 0));
		//AT->DrawEnd();
		int X = -200;
		static float Buf[128] = { 0 };
		ATA->GetAudioStreamData("res\\Audio\\Musics\\夜色.flac", Buf);
		for (int i = 0; i < 128; i++)
		{
			Y = Buf[i] * 1000;

			AT->CreateQuadrangle(
				ATATRGB::RED, ATATPOS3D(X, Y, 0),
				ATATRGB::WHITE, ATATPOS3D(X, 0, 0),
				ATATRGB::WHITE, ATATPOS3D(X + W, 0, 0),
				ATATRGB::RED, ATATPOS3D(X + W,Y, 0));
			X = X + W + WSpace;
			Y = 190;
		}
		AT->DrawEnd();
		ZeroMemory(Buf,128);
	}
	*/
	/*
		char Buf[128];
		while (true)
		{
			ATA->GetAudioStreamData("夜色.flac",Buf);
			system("cls");
			printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", Buf[0], Buf[1], Buf[2], Buf[3], Buf[4], Buf[5], Buf[6], Buf[7], Buf[8], Buf[9]);
			int end = 0;
		}
	*///需要用流加载方式,否则无效
	DWORD GetAudioStreamData(string AudioFileName, void *Buffer);
	//=================================================================
	//3D
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	//设置3D因子
	/*
	默认以米作为单位
	// Initialize the default output device with 3D support

	3D在设置音量时是无效的
	*/

	BOOL Init3DAudioEngine();
	BOOL Set3DFactors(float distf = 1.0f, float rollf = 1.0f, float doppf = 1.0f);

	//
	/*
	Don't move unless you know what you're doing

	BASS_SAMPLE_LOOP | BASS_SAMPLE_3D | BASS_SAMPLE_MONO
	BASS_SAMPLE_3D | BASS_SAMPLE_MONO
	*/
	BOOL LoadMusics3D(string MusicFileName, DWORD Flags = BASS_SAMPLE_LOOP | BASS_SAMPLE_3D | BASS_SAMPLE_MONO);
	BOOL LoadMusics3DAndPlay(string MusicFileName, DWORD Flags = BASS_SAMPLE_LOOP | BASS_SAMPLE_3D | BASS_SAMPLE_MONO);
	BOOL LoadEffects3D(string EffectFileName, DWORD Flags = BASS_SAMPLE_3D | BASS_SAMPLE_MONO);
	BOOL LoadEffects3DAndPlay(string EffectFileName, DWORD Flags = BASS_SAMPLE_3D | BASS_SAMPLE_MONO);

	BOOL SetMusics3DPos(BASS_3DVECTOR Pos);
	BOOL SetMusics3DPos(BASS_3DVECTOR Pos, BASS_3DVECTOR Vel);
	BOOL SetEffects3DPos(BASS_3DVECTOR Pos);
	BOOL SetEffects3DPos(BASS_3DVECTOR Pos, BASS_3DVECTOR Vel);

	BOOL SetMusics3DPos(string MusicFileName, BASS_3DVECTOR Pos);
	BOOL SetMusics3DPos(string MusicFileName, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel);
	BOOL SetMusics3DPos(HSTREAM HStream, BASS_3DVECTOR Pos);
	BOOL SetMusics3DPos(HSTREAM HStream, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel);
	BOOL SetEffects3DPos(string EffectFileName, BASS_3DVECTOR Pos);
	BOOL SetEffects3DPos(string EffectFileName, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel);
	BOOL SetEffects3DPos(HSTREAM HStream, BASS_3DVECTOR Pos);
	BOOL SetEffects3DPos(HSTREAM HStream, BASS_3DVECTOR Pos, BASS_3DVECTOR Vel);



	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	//TRUE ,重新播放,FALSE 接着播放
	BOOL PlayMusics(string MusicFileName, BOOL Restart = TRUE);
	BOOL PlayMusics_s(string MusicFileName, BOOL Restart = TRUE);
	BOOL PlayEffects(string EffectFileName);
	BOOL PlayStream(HSTREAM HStream, BOOL Restart = TRUE);

	BOOL PauseMusics(string MusicFileName);
	BOOL PauseEffects(string EffectFileName);
	BOOL PauseAllMusics();
	BOOL PauseAllEffects();
	BOOL PauseAllMusicAndEffects();

	BOOL StopMusics(string MusicFileName);
	BOOL StopEffects(string EffectFileName);
	BOOL StopAllMusics();
	BOOL StopAllEffects();
	BOOL StopAllMusicAndEffects();

	void DeleteMusic(string MusicFileName);
	void DeleteEffect(string EffectFileName);
	void DeleteAllMusic();
	void DeleteAllEffect();
	void DeleteAllMusicAndEffects();
	//释放说明
	/*
		//BASS_SampleFree(HStream);
		采取的是流功能
	*/
	BOOL FreeATA();
	//=================================================================
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	//返回秒
	double GetTimeSecond(string MusicFileName);
	//返回分
	double GetTimeMinute(string MusicFileName);
	//返回时
	double GetTimeHour(string MusicFileName);
	//返回秒
	double GetCurTimeSecond(string MusicFileName);
	//返回分
	double GetCurTimeMinute(string MusicFileName);
	//返回时
	double GetCurTimeHour(string MusicFileName);
	//返回指针的指向位置::::::::::::::::::::::::::
	unsigned __int64 GetCurPoint(string MusicFileName);
	//设置秒
	BOOL SetTimeSecond(string MusicFileName, double Second);
	//设置分
	BOOL SetTimeMinute(string MusicFileName, double Minute);
	//设置时
	BOOL SetTimeHour(string MusicFileName, double Hour);


private:
	ATBAE();
	~ATBAE();

	//拷贝构造
	ATBAE(const ATBAE& that);
	//同类赋值 重载 = 运算符
	ATBAE& operator = (const ATBAE& that);
};

/*
wchar_t file[MAX_PATH] = L"";
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFile = file;
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_EXPLORER;
	ofn.lpstrTitle = L"OpenFile";
	ofn.lpstrFilter = (L"音乐文件(*.mp3)|*.mp3|视频文件(*.mp4)|*.mp4|视频文件(*.mkv)|*.mkv|所有文件(*.*)|*.*||");
	if (GetOpenFileName(&ofn))
	{


		int var = 0;
		return FALSE;
	}

*/