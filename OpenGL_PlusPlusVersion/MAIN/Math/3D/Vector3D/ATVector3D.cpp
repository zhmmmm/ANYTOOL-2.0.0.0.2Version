#include "ATVector3D.h"

ATVector3D::ATVector3D()
{
	this->x = this->y = this->z = 0;
}
ATVector3D::ATVector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
ATVector3D::ATVector3D(const ATVector3D& Vector3D)
{
	this->x = Vector3D.x;
	this->y = Vector3D.y;
	this->z = Vector3D.z;
}

void ATVector3D::Zero()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

void ATVector3D::SetVector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
float ATVector3D::Dot(const ATVector3D& Vector3D)
{
	return this->x * Vector3D.x + this->y * Vector3D.y + this->z * Vector3D.z;
}
ATVector3D ATVector3D::Cross(const ATVector3D& Vector3D)
{
	ATVector3D v;
	v.x = this->y * Vector3D.z - this->z * Vector3D.y;
	v.y = this->z * Vector3D.x - this->x * Vector3D.z;
	v.z = this->x * Vector3D.y - this->y * Vector3D.x;
	return v;
}
float ATVector3D::Length() const
{
	return sqrtf(this->x*this->x + this->y * this->y + this->z * this->z);
}
float ATVector3D::GetAngle_R__(ATVector3D& Vector3D)
{
	float len1 = this->Length();
	float len2 = Vector3D.Length();
	assert(!ISZERO(len1));
	assert(!ISZERO(len2));
	float _cos = this->Dot(Vector3D) / (len1*len2);
	return acosf(_cos);
}
float ATVector3D::GetAngle_A__(ATVector3D& Vector3D)
{
	float Temp = this->GetAngle_R__(Vector3D);
	return float(Temp / M_PI * 180);
}
float ATVector3D::GetOuterProduct(const ATVector3D& Vector3D)
{
	double Temp = this->x * Vector3D.y - this->y * Vector3D.x - this->y * Vector3D.z - this->z * Vector3D.y;
	return (float)fabs(Temp);
}

ATVector3D ATVector3D::Normalize() const
{
	ATVector3D v;
	float Len = this->Length();
	v.x = this->x / Len;
	v.y = this->y / Len;
	v.z = this->z / Len;
	return v;
}
ATVector3D ATVector3D::Normalized()
{
	float Len = this->Length();
	assert(!ISZERO(Len));
	this->x /= Len;
	this->y /= Len;
	this->z /= Len;
	return *this;
}
ATVector3D ATVector3D::GetShadow(const ATVector3D& Vector3D)
{
	//被投影向量的单位向量
	ATVector3D Dir = Vector3D.Normalize();
	//求被投影后向量的长度 = 原投影向量的模*两个向量的夹角余弦
	float Len1 = Length();
	float Len2 = Vector3D.Length();
	assert(!ISZERO(Len1));
	assert(!ISZERO(Len2));
	float Mod = this->Dot(Vector3D) / Len2;//化简后的结果
	//向量的方向乘以长度
	Dir *= Mod;
	return Dir;
}


ATVector3D  ATVector3D::operator + (const ATVector3D& Vector3D)
{
	return ATVector3D(this->x + Vector3D.x, this->y + Vector3D.y, this->z + Vector3D.z);
}
ATVector3D&  ATVector3D::operator += (const ATVector3D& Vector3D)
{
	this->x += Vector3D.x;
	this->y += Vector3D.y;
	this->z += Vector3D.z;
	return *this;
}
ATVector3D  ATVector3D::operator + (double Var)
{
	return ATVector3D(this->x + Var, this->y + Var, this->z + Var);
}
ATVector3D&  ATVector3D::operator += (double Var)
{
	this->x += Var;
	this->y += Var;
	this->z += Var;
	return *this;
}
ATVector3D  ATVector3D::operator - (const ATVector3D& Vector3D)
{
	return ATVector3D(this->x - Vector3D.x, this->y - Vector3D.y, this->z - Vector3D.z);
}
ATVector3D&  ATVector3D::operator -= (const ATVector3D& Vector3D)
{
	this->x -= Vector3D.x;
	this->y -= Vector3D.y;
	this->z -= Vector3D.z;
	return *this;
}
ATVector3D  ATVector3D::operator - (double Var)
{
	return ATVector3D(this->x - Var, this->y - Var, this->z - Var);
}
ATVector3D&  ATVector3D::operator -= (double Var)
{
	this->x -= Var;
	this->y -= Var;
	this->z -= Var;
	return *this;
}
ATVector3D  ATVector3D::operator * (double Var)
{
	return ATVector3D(this->x * Var, this->y * Var, this->z * Var);
}
ATVector3D&  ATVector3D::operator *= (double Var)
{
	this->x *= Var;
	this->y *= Var;
	this->z *= Var;
	return *this;
}
ATVector3D  ATVector3D::operator * (const ATVector3D& Vector3D)
{
	return ATVector3D(this->x * Vector3D.x, this->y * Vector3D.y, this->z * Vector3D.z);
}
ATVector3D&  ATVector3D::operator *= (const ATVector3D& Vector3D)
{
	this->x *= Vector3D.x;
	this->y *= Vector3D.y;
	this->z *= Vector3D.z;
	return *this;
}
ATVector3D  ATVector3D::operator / (double Var)
{
	return ATVector3D(this->x / Var, this->y / Var, this->z / Var);
}
ATVector3D&  ATVector3D::operator /= (double Var)
{
	this->x /= Var;
	this->y /= Var;
	this->z /= Var;
	return *this;
}
ATVector3D  ATVector3D::operator / (const ATVector3D& Vector3D)
{
	return ATVector3D(this->x / Vector3D.x, this->y / Vector3D.y, this->z / Vector3D.z);
}
ATVector3D&  ATVector3D::operator /= (const ATVector3D& Vector3D)
{
	this->x /= Vector3D.x;
	this->y /= Vector3D.y;
	this->z /= Vector3D.z;
	return *this;
}
ATVector3D&  ATVector3D::operator = (const ATVector3D& Vector3D)
{
	this->x = Vector3D.x;
	this->y = Vector3D.y;
	this->z = Vector3D.z;
	return *this;
}
ATVector3D&  ATVector3D::operator = (double Var)
{
	this->x = Var;
	this->y = Var;
	this->z = Var;
	return *this;
}
bool  ATVector3D::operator == (const ATVector3D& Vector3D)
{
	if (this->x == Vector3D.x && this->y == Vector3D.y && this->z == Vector3D.z)
	{
		return true;
	}
	return false;
}
bool  ATVector3D::operator != (const ATVector3D& Vector3D)
{
	if (this->x != Vector3D.x && this->y != Vector3D.y && this->z != Vector3D.z)
	{
		return true;
	}
	return false;
}