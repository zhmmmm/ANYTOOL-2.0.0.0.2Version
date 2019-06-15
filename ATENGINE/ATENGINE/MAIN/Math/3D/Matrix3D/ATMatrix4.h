#pragma once
#include <iostream>
#include <math.h>
#include "../Vector3D/ATVector3D.h"
using namespace std;

typedef struct _CMATRIX4
{//4�׷���ṹ��
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
	//==================================����=========================
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
	ATMatrix4 Transpose();//��ת�þ���
	ATMatrix4 Adjoint();//��������
	ATMatrix4 Inverse(bool &IsInverse);//�������//����һ���߼����ò��������ж��Ƿ����

	ATMatrix4 operator + (const ATMatrix4& other);
	ATMatrix4 operator - (const ATMatrix4& other);
	ATMatrix4 operator * (const double k);
	ATMatrix4 operator * (const ATMatrix4& other);
	ATMatrix4& operator += (const ATMatrix4& other);
	ATMatrix4& operator -= (const ATMatrix4& other);
	ATMatrix4& operator *= (const double k);
	ATMatrix4& operator *= (const ATMatrix4& other);





	//ƽ��
	//1,0,0,0
	//0,1,0,0
	//0,0,1,0
	//x,y,z,1
	ATMatrix4 MakeTranslate(float x, float y, float z);
	ATMatrix4& Translate(float x, float y, float z);
	//����
	//x,0,0,0
	//0,y,0,0
	//0,0,z,0
	//0,0,0,1
	ATMatrix4 MakeScale(float x, float y, float z);
	ATMatrix4& Scale(float x, float y, float z);
	//��X��ת����
	//1  0  0  0
	//0  c  s  0
	//0  -s c  0
	//0  0  0  1
	ATMatrix4 MakeRotateX_r(float angle);
	ATMatrix4& RotateX_r(float angle);

	ATMatrix4 MakeRotateX_d(float angle);
	ATMatrix4& RotateX_d(float angle);

	//��Y��ת����
	//c  0 -s  0  
	//0  1  0  0  
	//s  0  c  0  
	//0  0  0  1
	ATMatrix4 MakeRotateY_r(float angle);
	ATMatrix4& RotateY_r(float angle);

	ATMatrix4 MakeRotateY_d(float angle);
	ATMatrix4& RotateY_d(float angle);

	//��Z��ת����
	//c  s  0  0
	//-s c  0  0
	//0  0  1  0
	//0  0  0  1
	ATMatrix4 MakeRotateZ_r(float angle);
	ATMatrix4& RotateZ_r(float angle);
	ATMatrix4 MakeRotateZ_d(float angle);
	ATMatrix4& RotateZ_d(float angle);
	//����������ת����
	ATMatrix4 MakeRotateXYZ_r(const ATVector3D& v, float a);
	ATMatrix4& RotateXYZ_r(const ATVector3D& v, float a);
	ATMatrix4 MakeRotateXYZ_d(const ATVector3D& v, float angle);
	ATMatrix4& RotateXYZ_d(const ATVector3D& v, float angle);


	void Identity();

	void ShowData(char* MatrixName);
	//==================================����=========================
	_CMATRIX4 m_Matrix;
};