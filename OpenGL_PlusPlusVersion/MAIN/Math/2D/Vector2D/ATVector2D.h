#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI       3.14159265358979323846
//1e-5//��ѧ������ 1*10^(-5) 0.00001
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
	float Dot(const ATVector2D& Vector2D);//����
	float Cross(const ATVector2D& Vector2D);//�����Ĳ�ˣ����
	float Length();//��ģ
	float GetAngle_r(ATVector2D& Vector2D);//��нǻ���
	float GetAngle_a(ATVector2D& Vector2D);//��нǽǶ�

	ATVector2D Nomalize();//��λ����
	ATVector2D GetShadow(const ATVector2D& Vector2D); //��ͶӰ
	ATVector2D  operator+(const ATVector2D& Vector2D);
	ATVector2D&  operator+=(const ATVector2D& Vector2D);
	ATVector2D  operator-(const ATVector2D& Vector2D);
	ATVector2D&  operator-=(const ATVector2D& Vector2D);
	ATVector2D  operator*(double);//��������
	ATVector2D&  operator*=(double);//��������
	float  operator*(const ATVector2D& Vector2D);//�����,����2D�����ؽ����ģ
};