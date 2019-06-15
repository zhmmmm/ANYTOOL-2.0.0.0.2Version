#pragma once
#include <iostream>
using namespace std;
#include <math.h>
#include "../Vector2D/ATVector2D.h"
typedef struct _CMATRIX3
{
	//3�׷���ṹ��
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
	//==================================����=========================
	ATMatrix3();
	ATMatrix3(const ATMatrix3& old);
	ATMatrix3(double _11, double _12, double _13, double _21, double _22, double _23, double _31, double _32, double _33);
	ATMatrix3(double m[3][3]);
	ATMatrix3(double** m);

	double GetDet();
	ATMatrix3 Transpose();//��ת�þ���
	ATMatrix3 Adjoint();//��������
	ATMatrix3 Inverse(bool &IsInverse);//�������//����һ���߼����ò��������ж��Ƿ����
	static ATMatrix3 GetScaleMtr(double x_ratio, double y_ratio);//�����任����
	static ATMatrix3 GetEqlScaleMtr(double s_ratio);//�ȱ����任����
	static ATMatrix3 GetRotateMtr(double angle);//��ת����
	static ATMatrix3 GetTranslationMtr(double x_m, double y_n);//ƽ��
	static ATMatrix3 GetX_Symmetry();//X�ԳƱ任
	static ATMatrix3 GetY_Symmetry();//Y�ԳƱ任
	static ATMatrix3 GetO_Symmetry();//ԭ��ԳƱ任
	static ATMatrix3 Get45_Symmetry();//+45��ԳƱ任
	static ATMatrix3 Get_45_Symmetry();//-45��ԳƱ任
	static ATMatrix3 Get_Angle_Symmetry(double angle);//���ڹ�ԭ������Ƕ�ֱ�ߵĶԳƱ任
	static ATMatrix3 GetX_TiltMtr(double angle);//X���б任
	static ATMatrix3 GetY_TiltMtr(double angle);//Y���б任
	ATMatrix3 operator + (const ATMatrix3& other);
	ATMatrix3 operator - (const ATMatrix3& other);
	ATMatrix3 operator * (const double k);
	ATVector2D operator * (ATVector2D& p);
	ATMatrix3 operator * (const ATMatrix3& other);
	ATMatrix3& operator += (const ATMatrix3& other);
	ATMatrix3& operator -= (const ATMatrix3& other);
	ATMatrix3& operator *= (const double k);
	ATMatrix3& operator *= (const ATMatrix3& other);


	//��λ������
	ATMatrix3& Identity();
	//ƽ�ƾ���
	ATMatrix3& Translate(float x, float y);

	ATMatrix3 SetTranslate(float x, float y);
	//���ž���
	ATMatrix3& Scale(float x, float y);
	ATMatrix3 SetScale(float x, float y);
	//��ת����(����)
	ATMatrix3& Rotate_R__(float Angle_r);
	ATMatrix3 SetRotate_R__(float Angle_r);
	//��ת����(�Ƕ�)
	ATMatrix3& Rotate_D__(float Angle_d);
	ATMatrix3 SetRotate_D__(float Angle_d);

	void ShowData(char* MatrixName);
	//==================================����=========================
	_CMATRIX3 m_Matrix;
};