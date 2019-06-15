#pragma once
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI       3.14159265358979323846
//1e-5//科学计数法 1*10^(-5) 0.00001
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
	float Dot(const ATVector3D& Vector3D);//求点积
	ATVector3D Cross(const ATVector3D& Vector3D);//向量的叉乘
	float Length() const;//求模
	float GetAngle_R__(ATVector3D& Vector3D);//求夹角弧度
	float GetAngle_A__(ATVector3D& Vector3D);//求夹角角度
	float GetOuterProduct(const ATVector3D& Vector3D);//求外积,这里3D，返回结果的模

	ATVector3D Normalize() const;//求单位向量
	ATVector3D Normalized();//求单位向量
	ATVector3D GetShadow(const ATVector3D& Vector3D); //求投影


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
	ATVector3D operator -- ();//前置--
	ATVector3D operator -- (int);//后置--
	ATVector3D operator ++ ();//前置++
	ATVector3D operator ++ (int);//后置++
};