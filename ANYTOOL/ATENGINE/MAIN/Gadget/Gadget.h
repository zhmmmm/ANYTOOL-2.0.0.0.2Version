#pragma once
#include "../OpenGL_AY_Engine.h"


//����Ҫ�ر�2D������
class Gadget
{
public:
	static void CreateQuadrangle2D();
	static void CreateQuadrangle3D();

	//��Բ
	//���� �뾶
	static void CreateCircular2D(int Side,float R);

	//
	static void CreateMusicMapCircular2D(float *Data,int DataLen = 128, int Side = 0, float R = 300);

	static void CreateMusicMapLine2D(float *Data, int DataLen = 128, int Side = 0, float R = 300);

	//�����е���Բ��
	//CreateMusicMap2D ��������

	static void CreateNotRing2D(int Side, float R,float Width);
};