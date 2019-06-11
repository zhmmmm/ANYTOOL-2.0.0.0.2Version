#pragma once
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI       3.14159265358979323846
//1e-5//��ѧ������ 1*10^(-5) 0.00001
#define ISZERO(x)	(abs(x)<(1e-5))

#define ATPOS3D ATVector3D

class ATVector3D
{
public:
	float x = 0;
	float y = 0;
	float z = 0;

	ATVector3D();
	ATVector3D(float x, float y, float z);
	ATVector3D(const ATVector3D& Vector3D);

	void Zero();

	void SetVector3D(float x, float y,float z);
	float Dot(const ATVector3D& Vector3D);//����
	ATVector3D Cross(const ATVector3D& Vector3D);//�����Ĳ��
	float Length() const;//��ģ
	float GetAngle_R__(ATVector3D& Vector3D);//��нǻ���
	float GetAngle_A__(ATVector3D& Vector3D);//��нǽǶ�
	float GetOuterProduct(const ATVector3D& Vector3D);//�����,����3D�����ؽ����ģ

	ATVector3D Normalize() const;//��λ����
	ATVector3D Normalized();//��λ����
	ATVector3D GetShadow(const ATVector3D& Vector3D); //��ͶӰ


	ATVector3D  operator + (const ATVector3D& Vector3D);
	ATVector3D&  operator += (const ATVector3D& Vector3D);
	ATVector3D  operator + (double Var);
	ATVector3D&  operator += (double Var);
	ATVector3D  operator - (const ATVector3D& Vector3D);
	ATVector3D&  operator -= (const ATVector3D& Vector3D);
	ATVector3D  operator - (double Var);
	ATVector3D&  operator -= (double Var);
	ATVector3D  operator * (double Var);
	ATVector3D&  operator *= (double Var);
	ATVector3D  operator * (const ATVector3D& Vector3D);
	ATVector3D&  operator *= (const ATVector3D& Vector3D);
	ATVector3D  operator / (double Var);
	ATVector3D&  operator /= (double Var);
	ATVector3D  operator / (const ATVector3D& Vector3D);
	ATVector3D&  operator /= (const ATVector3D& Vector3D);
	ATVector3D&  operator = (const ATVector3D& Vector3D);
	ATVector3D&  operator = (double Var);
	bool  operator == (const ATVector3D& Vector3D);
	bool  operator != (const ATVector3D& Vector3D);
	ATVector3D operator -- ();//ǰ��--
	ATVector3D operator -- (int);//����--
	ATVector3D operator ++ ();//ǰ��++
	ATVector3D operator ++ (int);//����++
};