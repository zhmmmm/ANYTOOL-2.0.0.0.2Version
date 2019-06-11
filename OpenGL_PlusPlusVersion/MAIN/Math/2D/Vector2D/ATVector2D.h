#pragma once
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI       3.14159265358979323846
//1e-5//科学计数法 1*10^(-5) 0.00001
#define ISZERO(x)	(abs(x)<(1e-5))

#define ATPOS2D ATVector2D

class ATVector2D
{
public:
	float x = 0;
	float y = 0;

	ATVector2D();
	ATVector2D(float x, float y);
	ATVector2D(const ATVector2D& Vector2D);

	void Zero();

	void SetVector2D(float x, float y);
	float Dot(const ATVector2D& Vector2D);//求点积
	float Cross(const ATVector2D& Vector2D);//向量的叉乘
	float Length() const;//求模
	float GetAngle_R__(ATVector2D& Vector2D);//求夹角弧度
	float GetAngle_A__(ATVector2D& Vector2D);//求夹角角度
	float GetOuterProduct(const ATVector2D& Vector2D);//求外积,这里2D，返回结果的模

	ATVector2D Normalize() const;//求单位向量
	ATVector2D Normalized();//求单位向量
	ATVector2D GetShadow(const ATVector2D& Vector2D); //求投影


	ATVector2D  operator + (const ATVector2D& Vector2D);
	ATVector2D&  operator += (const ATVector2D& Vector2D);
	ATVector2D  operator + (double Var);
	ATVector2D&  operator += (double Var);
	ATVector2D  operator - (const ATVector2D& Vector2D);
	ATVector2D&  operator -= (const ATVector2D& Vector2D);
	ATVector2D  operator - (double Var);
	ATVector2D&  operator -= (double Var);
	ATVector2D  operator * (double Var);
	ATVector2D&  operator *= (double Var);
	ATVector2D  operator * (const ATVector2D& Vector2D);
	ATVector2D&  operator *= (const ATVector2D& Vector2D);
	ATVector2D  operator / (double Var);
	ATVector2D&  operator /= (double Var);
	ATVector2D  operator / (const ATVector2D& Vector2D);
	ATVector2D&  operator /= (const ATVector2D& Vector2D);
	ATVector2D&  operator = (const ATVector2D& Vector2D);
	ATVector2D&  operator = (double Var);
	bool  operator == (const ATVector2D& Vector2D);
	bool  operator != (const ATVector2D& Vector2D);
	ATVector2D operator -- ();//前置--
	ATVector2D operator -- (int);//后置--
	ATVector2D operator ++ ();//前置++
	ATVector2D operator ++ (int);//后置++
};