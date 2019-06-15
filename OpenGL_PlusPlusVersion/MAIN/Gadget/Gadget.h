#pragma once
#include "../OpenGL_AY_Engine.h"


//你需要关闭2D纹理功能
class Gadget
{
public:
	static void CreateQuadrangle2D();
	static void CreateQuadrangle3D();

	//画圆
	//边数 半径
	static void CreateCircular2D(int Side,float R);

	//
	static void CreateMusicMapCircular2D(float *Data,int DataLen = 128, int Side = 0, float R = 300);

	static void CreateMusicMapLine2D(float *Data, int DataLen = 128, int Side = 0, float R = 300);

	//创建有点像圆环
	//CreateMusicMap2D 的衍生版

	static void CreateNotRing2D(int Side, float R,float Width);
};