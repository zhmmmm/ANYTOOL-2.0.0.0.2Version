#pragma once
#include <iostream>
using namespace std;
#include <math.h>
#include "../Vector2D/ATVector2D.h"
typedef struct _CMATRIX3
{
	//3阶方阵结构体
	union
	{
		struct
		{
			double        _11, _12, _13;
			double        _21, _22, _23;
			double        _31, _32, _33;
		};
		double m[3][3];
	};
}CMATRIX3D, *LPCMATRIX3D;

class _declspec(dllexport) ATMatrix3
{
public:
	//==================================方法=========================
	ATMatrix3();
	ATMatrix3(const ATMatrix3& old);
	ATMatrix3(double _11, double _12, double _13, double _21, double _22, double _23, double _31, double _32, double _33);
	ATMatrix3(double m[3][3]);
	ATMatrix3(double** m);

	double GetDet();
	ATMatrix3 Transpose();//求转置矩阵
	ATMatrix3 Adjoint();//求伴随矩阵
	ATMatrix3 Inverse(bool &IsInverse);//求逆矩阵//传入一个逻辑引用参数，来判断是否可逆
	static ATMatrix3 GetScaleMtr(double x_ratio, double y_ratio);//比例变换矩阵
	static ATMatrix3 GetEqlScaleMtr(double s_ratio);//等比例变换矩阵
	static ATMatrix3 GetRotateMtr(double angle);//旋转矩阵
	static ATMatrix3 GetTranslationMtr(double x_m, double y_n);//平移
	static ATMatrix3 GetX_Symmetry();//X对称变换
	static ATMatrix3 GetY_Symmetry();//Y对称变换
	static ATMatrix3 GetO_Symmetry();//原点对称变换
	static ATMatrix3 Get45_Symmetry();//+45°对称变换
	static ATMatrix3 Get_45_Symmetry();//-45°对称变换
	static ATMatrix3 Get_Angle_Symmetry(double angle);//关于过原点任意角度直线的对称变换
	static ATMatrix3 GetX_TiltMtr(double angle);//X错切变换
	static ATMatrix3 GetY_TiltMtr(double angle);//Y错切变换
	ATMatrix3 operator + (const ATMatrix3& other);
	ATMatrix3 operator - (const ATMatrix3& other);
	ATMatrix3 operator * (const double k);
	ATVector2D operator * (ATVector2D& p);
	ATMatrix3 operator * (const ATMatrix3& other);
	ATMatrix3& operator += (const ATMatrix3& other);
	ATMatrix3& operator -= (const ATMatrix3& other);
	ATMatrix3& operator *= (const double k);
	ATMatrix3& operator *= (const ATMatrix3& other);


	//单位化矩阵
	ATMatrix3& Identity();
	//平移矩阵
	ATMatrix3& Translate(float x, float y);

	ATMatrix3 SetTranslate(float x, float y);
	//缩放矩阵
	ATMatrix3& Scale(float x, float y);
	ATMatrix3 SetScale(float x, float y);
	//旋转矩阵(弧度)
	ATMatrix3& Rotate_R__(float Angle_r);
	ATMatrix3 SetRotate_R__(float Angle_r);
	//旋转矩阵(角度)
	ATMatrix3& Rotate_D__(float Angle_d);
	ATMatrix3 SetRotate_D__(float Angle_d);

	void ShowData(char* MatrixName);
	//==================================属性=========================
	_CMATRIX3 m_Matrix;
};