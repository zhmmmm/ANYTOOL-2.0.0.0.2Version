#pragma once
#include <assert.h>
#define _USE_MATH_DEFINES
#include <cmath>
#define M_PI       3.14159265358979323846
//1e-5//��ѧ������ 1*10^(-5) 0.00001
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
	float Dot(const ATVector2D& Vector2D);//����
	float Cross(const ATVector2D& Vector2D);//�����Ĳ��
	float Length() const;//��ģ
	float GetAngle_R__(ATVector2D& Vector2D);//��нǻ���
	float GetAngle_A__(ATVector2D& Vector2D);//��нǽǶ�
	float GetOuterProduct(const ATVector2D& Vector2D);//�����,����2D�����ؽ����ģ

	ATVector2D Normalize() const;//��λ����
	ATVector2D Normalized();//��λ����
	ATVector2D GetShadow(const ATVector2D& Vector2D); //��ͶӰ


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
	ATVector2D operator -- ();//ǰ��--
	ATVector2D operator -- (int);//����--
	ATVector2D operator ++ ();//ǰ��++
	ATVector2D operator ++ (int);//����++
};