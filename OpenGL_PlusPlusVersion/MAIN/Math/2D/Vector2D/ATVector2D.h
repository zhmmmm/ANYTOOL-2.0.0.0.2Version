#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI       3.14159265358979323846
//1e-5//科学计数法 1*10^(-5) 0.00001
#define ISFLOATZERO(x)	abs(x)<1e-5


class ATVector2D
{
public:
	float x;
	float y;

	ATVector2D();
	ATVector2D(float x, float y);
	ATVector2D(const ATVector2D& Vector2D);

	void SetVector2D(float x, float y);
	float Dot(const ATVector2D& Vector2D);//求点积
	float Cross(const ATVector2D& Vector2D);//向量的叉乘，外积
	float Length();//求模
	float GetAngle_r(ATVector2D& Vector2D);//求夹角弧度
	float GetAngle_a(ATVector2D& Vector2D);//求夹角角度

	ATVector2D Nomalize();//求单位向量
	ATVector2D GetShadow(const ATVector2D& Vector2D); //求投影
	ATVector2D  operator+(const ATVector2D& Vector2D);
	ATVector2D&  operator+=(const ATVector2D& Vector2D);
	ATVector2D  operator-(const ATVector2D& Vector2D);
	ATVector2D&  operator-=(const ATVector2D& Vector2D);
	ATVector2D  operator*(double);//数乘重载
	ATVector2D&  operator*=(double);//数乘重载
	float  operator*(const ATVector2D& Vector2D);//求外积,这里2D，返回结果的模
};