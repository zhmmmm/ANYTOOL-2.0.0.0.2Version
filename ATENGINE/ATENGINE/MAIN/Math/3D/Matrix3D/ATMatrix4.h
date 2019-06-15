#pragma once
#include <iostream>
#include <math.h>
#include "../Vector3D/ATVector3D.h"
using namespace std;

typedef struct _CMATRIX4
{//4阶方阵结构体
	union 
	{
		struct
		{
			double        _11, _12, _13, _14;
			double        _21, _22, _23, _24;
			double        _31, _32, _33, _34;
			double        _41, _42, _43, _44;
		};
		double m[4][4];
	};
}CMATRIX4D, *LPCMATRIX4D;

class _declspec(dllexport) ATMatrix4
{
public:
	//==================================方法=========================
	ATMatrix4();
	ATMatrix4(const ATMatrix4& old);
	ATMatrix4(double _11, double _12, double _13, double _14,
		double _21, double _22, double _23, double _24,
		double _31, double _32, double _33, double _34,
		double _41, double _42, double _43, double _44
	);
	ATMatrix4(double m[4][4]);
	ATMatrix4(double** m);

	double GetDet();
	ATMatrix4 Transpose();//求转置矩阵
	ATMatrix4 Adjoint();//求伴随矩阵
	ATMatrix4 Inverse(bool &IsInverse);//求逆矩阵//传入一个逻辑引用参数，来判断是否可逆

	ATMatrix4 operator + (const ATMatrix4& other);
	ATMatrix4 operator - (const ATMatrix4& other);
	ATMatrix4 operator * (const double k);
	ATMatrix4 operator * (const ATMatrix4& other);
	ATMatrix4& operator += (const ATMatrix4& other);
	ATMatrix4& operator -= (const ATMatrix4& other);
	ATMatrix4& operator *= (const double k);
	ATMatrix4& operator *= (const ATMatrix4& other);





	//平移
	//1,0,0,0
	//0,1,0,0
	//0,0,1,0
	//x,y,z,1
	ATMatrix4 MakeTranslate(float x, float y, float z);
	ATMatrix4& Translate(float x, float y, float z);
	//缩放
	//x,0,0,0
	//0,y,0,0
	//0,0,z,0
	//0,0,0,1
	ATMatrix4 MakeScale(float x, float y, float z);
	ATMatrix4& Scale(float x, float y, float z);
	//绕X旋转矩阵
	//1  0  0  0
	//0  c  s  0
	//0  -s c  0
	//0  0  0  1
	ATMatrix4 MakeRotateX_r(float angle);
	ATMatrix4& RotateX_r(float angle);

	ATMatrix4 MakeRotateX_d(float angle);
	ATMatrix4& RotateX_d(float angle);

	//绕Y旋转矩阵
	//c  0 -s  0  
	//0  1  0  0  
	//s  0  c  0  
	//0  0  0  1
	ATMatrix4 MakeRotateY_r(float angle);
	ATMatrix4& RotateY_r(float angle);

	ATMatrix4 MakeRotateY_d(float angle);
	ATMatrix4& RotateY_d(float angle);

	//绕Z旋转矩阵
	//c  s  0  0
	//-s c  0  0
	//0  0  1  0
	//0  0  0  1
	ATMatrix4 MakeRotateZ_r(float angle);
	ATMatrix4& RotateZ_r(float angle);
	ATMatrix4 MakeRotateZ_d(float angle);
	ATMatrix4& RotateZ_d(float angle);
	//绕任意轴旋转矩阵
	ATMatrix4 MakeRotateXYZ_r(const ATVector3D& v, float a);
	ATMatrix4& RotateXYZ_r(const ATVector3D& v, float a);
	ATMatrix4 MakeRotateXYZ_d(const ATVector3D& v, float angle);
	ATMatrix4& RotateXYZ_d(const ATVector3D& v, float angle);


	void Identity();

	void ShowData(char* MatrixName);
	//==================================属性=========================
	_CMATRIX4 m_Matrix;
};