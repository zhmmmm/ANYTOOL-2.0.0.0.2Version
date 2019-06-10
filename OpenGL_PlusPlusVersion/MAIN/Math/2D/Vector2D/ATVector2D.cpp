#include "ATVector2D.h"

ATVector2D::ATVector2D()
{
	this->x = this->y = 0;
}
ATVector2D::ATVector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}
ATVector2D::ATVector2D(const ATVector2D& Vector2D)
{
	this->x = Vector2D.x;
	this->y = Vector2D.y;
}

void ATVector2D::Zero()
{
	this->x = 0;
	this->y = 0;
}

void ATVector2D::SetVector2D(float x, float y)
{
	ATVector2D::ATVector2D(x, y);
}
float ATVector2D::Dot(const ATVector2D& Vector2D)
{
	return this->x * Vector2D.x + this->y * Vector2D.y;
}
float ATVector2D::Cross(const ATVector2D& Vector2D)//向量的叉乘，外积
{
	return this->x * Vector2D.y - this->y * Vector2D.x;
}
float ATVector2D::Length() const
{
	return sqrt(this->x * this->x + this->y * this->y);
}
float ATVector2D::GetAngle_R__(ATVector2D& Vector2D)
{
	float Dot = this->Dot(Vector2D);
	float Cosa = Dot / (this->Length() * Vector2D.Length());
	float Temp = acosf(Cosa);
	return Temp;
}
float ATVector2D::GetAngle_A__(ATVector2D& Vector2D)
{
	float Temp = this->GetAngle_R__(Vector2D);
	return float(Temp / M_PI * 180);
}
float ATVector2D::GetOuterProduct(const ATVector2D& Vector2D)
{
	double Temp = this->x * Vector2D.y - this->y * Vector2D.x;
	return (float)fabs(Temp);
}


ATVector2D ATVector2D::Normalize() const
{
	float Len = this->Length();
	if (ISZERO(Len))
	{
		return ATVector2D(0, 0);
	}
	return ATVector2D(this->x / Len, this->y / Len);
}
ATVector2D ATVector2D::Normalized()
{
	float Len = this->Length();
	assert(!ISZERO(Len));
	return ATVector2D(this->x / Len, this->y / Len);
}
ATVector2D ATVector2D::GetShadow(const ATVector2D& Vector2D)
{
	double Dot = this->Dot(Vector2D);
	float M = Vector2D.x * Vector2D.x + Vector2D.y * Vector2D.y;
	ATVector2D Shadow(x * (Dot / M), y * (Dot / M));
	return Shadow;
}
ATVector2D  ATVector2D::operator + (const ATVector2D& Vector2D)
{
	return ATVector2D(this->x + Vector2D.x, this->y + Vector2D.y);
}
ATVector2D & ATVector2D::operator += (const ATVector2D& Vector2D)
{
	this->x += Vector2D.x;
	this->y += Vector2D.y;
	return *this;
}
ATVector2D  ATVector2D::operator + (double Var)
{
	return ATVector2D(this->x + Var, this->y + Var);
}
ATVector2D&  ATVector2D::operator += (double Var)
{
	this->x += Var;
	this->y += Var;
	return *this;
}
ATVector2D  ATVector2D::operator - (const ATVector2D& Vector2D)
{
	return ATVector2D(this->x - Vector2D.x, this->y - Vector2D.y);
}
ATVector2D & ATVector2D::operator -= (const ATVector2D& Vector2D)
{
	this->x -= Vector2D.x;
	this->y -= Vector2D.y;
	return *this;
}
ATVector2D  ATVector2D::operator - (double Var)
{
	return ATVector2D(this->x - Var, this->y - Var);
}
ATVector2D&  ATVector2D::operator -= (double Var)
{
	this->x -= Var;
	this->y -= Var;
	return *this;
}
ATVector2D  ATVector2D::operator * (double Var)
{
	return ATVector2D(this->x * Var, this->y * Var);
}
ATVector2D & ATVector2D::operator *= (double Var)
{
	this->x *= Var;
	this->y *= Var;
	return *this;
}
ATVector2D  ATVector2D::operator * (const ATVector2D& Vector2D)
{
	return ATVector2D(this->x * Vector2D.x, this->y * Vector2D.y);
}
ATVector2D&  ATVector2D::operator *= (const ATVector2D& Vector2D)
{
	this->x *= Vector2D.x;
	this->y *= Vector2D.y;
	return *this;
}
ATVector2D  ATVector2D::operator / (double Var)
{
	return ATVector2D(this->x / Var, this->y / Var);
}
ATVector2D & ATVector2D::operator /= (double Var)
{
	this->x /= Var;
	this->y /= Var;
	return *this;
}
ATVector2D  ATVector2D::operator / (const ATVector2D& Vector2D)
{
	return ATVector2D(this->x / Vector2D.x, this->y / Vector2D.y);
}
ATVector2D&  ATVector2D::operator /= (const ATVector2D& Vector2D)
{
	this->x /= Vector2D.x;
	this->y /= Vector2D.y;
	return *this;
}
ATVector2D&  ATVector2D::operator = (const ATVector2D& Vector2D)
{
	this->x = Vector2D.x;
	this->y = Vector2D.y;
	return *this;
}
ATVector2D&  ATVector2D::operator = (double Var)
{
	this->x = Var;
	this->y = Var;
	return *this;
}
bool  ATVector2D::operator == (const ATVector2D& Vector2D)
{
	if (this->x == Vector2D.x && this->y == Vector2D.y)
	{
		return true;
	}
	return false;
}
bool  ATVector2D::operator != (const ATVector2D& Vector2D)
{
	if (this->x != Vector2D.x && this->y != Vector2D.y)
	{
		return true;
	}
	return false;
}