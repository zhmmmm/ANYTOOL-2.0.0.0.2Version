#include "ATMatrix4.h"

ATMatrix4::ATMatrix4()
{
	memset(m_Matrix.m, 0, sizeof(double) * 16);
}
ATMatrix4::ATMatrix4(const ATMatrix4& old)
{
	memcpy(m_Matrix.m, old.m_Matrix.m, sizeof(double) * 16);
}
ATMatrix4::ATMatrix4(double _11, double _12, double _13, double _14,
	double _21, double _22, double _23, double _24,
	double _31, double _32, double _33, double _34,
	double _41, double _42, double _43, double _44
)
{
	m_Matrix._11 = _11; m_Matrix._12 = _12; m_Matrix._13 = _13, m_Matrix._14 = _14;
	m_Matrix._21 = _21; m_Matrix._22 = _22; m_Matrix._23 = _23, m_Matrix._24 = _24;
	m_Matrix._31 = _31; m_Matrix._32 = _32; m_Matrix._33 = _33, m_Matrix._34 = _34;
	m_Matrix._41 = _41; m_Matrix._42 = _42; m_Matrix._43 = _43, m_Matrix._44 = _44;
}
ATMatrix4::ATMatrix4(double m[4][4])
{
	memcpy(m_Matrix.m, m, sizeof(double) * 16);
}
ATMatrix4::ATMatrix4(double** m)
{
	memcpy(m_Matrix.m[0], m[0], sizeof(double) * 4);
	memcpy(m_Matrix.m[1], m[1], sizeof(double) * 4);
	memcpy(m_Matrix.m[2], m[2], sizeof(double) * 4);
	memcpy(m_Matrix.m[3], m[3], sizeof(double) * 4);
}
double GetDetRank3(double src[3][3])//求3阶行列式值
{
	double det = src[0][0] * src[1][1] * src[2][2]
		+ src[0][1] * src[1][2] * src[2][0]
		+ src[0][2] * src[1][0] * src[2][1]
		- src[0][2] * src[1][1] * src[2][0]
		- src[0][1] * src[1][0] * src[2][2]
		- src[0][0] * src[1][2] * src[2][1];
	return det;
}
double GetCofactor(int Row, int Col, _CMATRIX4 src)//取任意行列3阶代数余子式
{
	double temp[9] = {};
	double dest[3][3] = {};
	double det = 0;
	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != Row && j != Col)
			{
				temp[index++] = src.m[i][j];
			}
		}
	}
	memcpy(dest, temp, sizeof(double) * 9);
	det = pow(double(-1), Row + Col)*GetDetRank3(dest);
	return det;
}
ATMatrix4 ATMatrix4::Transpose()//求转置矩阵
{
	ATMatrix4 temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[j][i];
		}
	}
	return temp;
}
ATMatrix4 ATMatrix4::Adjoint()//求伴随矩阵
{
	ATMatrix4 temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp.m_Matrix.m[j][i] = GetCofactor(i, j, m_Matrix);
		}
	}
	return temp;
}
ATMatrix4 ATMatrix4::Inverse(bool &IsInverse)//求逆矩阵//传入一个逻辑引用参数，来判断是否可逆
{
	ATMatrix4 temp;//初始为0矩阵
	double det = GetDet();
	if (det != 0)
	{
		IsInverse = true;
		temp = Adjoint();
		temp *= (1 / det);
		return temp;
	}
	IsInverse = false;
	return temp;
}
double ATMatrix4::GetDet()
{
	double det = 0;
	for (int i = 0; i < 4; i++)
	{
		det += m_Matrix.m[i][0] * GetCofactor(i, 0, m_Matrix);
	}
	return det;
}
ATMatrix4 ATMatrix4::operator + (const ATMatrix4& other)
{
	ATMatrix4 temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[i][j] + other.m_Matrix.m[i][j];
		}
	}
	return temp;
}
ATMatrix4 ATMatrix4::operator - (const ATMatrix4& other)
{
	ATMatrix4 temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[i][j] - other.m_Matrix.m[i][j];
		}
	}
	return temp;
}
ATMatrix4 ATMatrix4::operator * (const double k)
{
	ATMatrix4 temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[i][j] * k;
		}
	}
	return temp;
}
ATMatrix4 ATMatrix4::operator * (const ATMatrix4& other)
{
	ATMatrix4 temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				temp.m_Matrix.m[i][j] += m_Matrix.m[i][k] * other.m_Matrix.m[k][j];
			}
		}
	}
	return temp;
}
ATMatrix4& ATMatrix4::operator += (const ATMatrix4& other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_Matrix.m[i][j] += other.m_Matrix.m[i][j];
		}
	}
	return *this;
}
ATMatrix4& ATMatrix4::operator -= (const ATMatrix4& other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_Matrix.m[i][j] -= other.m_Matrix.m[i][j];
		}
	}
	return *this;
}
ATMatrix4& ATMatrix4::operator *= (const double k)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_Matrix.m[i][j] *= k;
		}
	}
	return *this;
}
ATMatrix4& ATMatrix4::operator *= (const ATMatrix4& other)
{
	ATMatrix4 temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				temp.m_Matrix.m[i][j] += m_Matrix.m[i][k] * other.m_Matrix.m[k][j];
			}
		}
	}
	memcpy(m_Matrix.m, temp.m_Matrix.m, sizeof(double) * 9);
	return *this;
}
void ATMatrix4::ShowData(char* MatrixName)
{
	if (MatrixName != NULL)
	{
		cout << MatrixName << "[4×4] = \n";
	}
	else
	{
		cout << "A[4×4] = \n";
	}
	cout << "╭                                                   ╮\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "│";
		for (int j = 0; j < 4; j++)
		{
			printf("%12.6lf", m_Matrix.m[i][j]);
			if (j < 3)
			{
				cout << ",";
			}
		}
		cout << "│" << endl;
	}
	cout << "╰                                                   ╯\n";
}

ATMatrix4 ATMatrix4::MakeTranslate(float x, float y, float z)
{
	ATMatrix4 _m;
	_m.m_Matrix._41 = x;
	_m.m_Matrix._42 = y;
	_m.m_Matrix._43 = z;
	return _m;
}
ATMatrix4& ATMatrix4::Translate(float x, float y, float z)//在自己的基础上平移
{
	ATMatrix4 _m;
	_m.m_Matrix._41 = x;
	_m.m_Matrix._42 = y;
	_m.m_Matrix._43 = z;
	(*this) *= _m;
	return *this;
}
ATMatrix4 ATMatrix4::MakeScale(float x, float y, float z)//构造一个缩放矩阵
{
	ATMatrix4 _m;
	_m.m_Matrix._11 = x;
	_m.m_Matrix._22 = y;
	_m.m_Matrix._33 = z;
	return _m;
}
ATMatrix4& ATMatrix4::Scale(float x, float y, float z)//在自己的基础上缩放
{
	ATMatrix4 _m;
	_m.m_Matrix._11 = x;
	_m.m_Matrix._22 = y;
	_m.m_Matrix._33 = z;
	(*this) *= _m;
	return *this;
}
ATMatrix4 ATMatrix4::MakeRotateX_r(float angle)//构造一个绕X轴旋转矩阵
{
	ATMatrix4 _m;
	float c = cos(angle);
	float s = sin(angle);
	_m.m_Matrix._22 = c;
	_m.m_Matrix._23 = s;
	_m.m_Matrix._32 = -s;
	_m.m_Matrix._33 = c;
	return _m;
}
ATMatrix4& ATMatrix4::RotateX_r(float angle)//在自己的基础绕X轴旋转
{
	ATMatrix4 _m;
	float c = cos(angle);
	float s = sin(angle);
	_m.m_Matrix._22 = c;
	_m.m_Matrix._23 = s;
	_m.m_Matrix._32 = -s;
	_m.m_Matrix._33 = c;
	(*this) *= _m;
	return *this;
}
ATMatrix4 ATMatrix4::MakeRotateX_d(float angle)//构造一个绕X轴旋转矩阵
{
	float a = float(angle / 180 * M_PI);
	return MakeRotateX_r(a);
}
ATMatrix4& ATMatrix4::RotateX_d(float angle)//在自己的基础绕X轴旋转
{
	float a = float(angle / 180 * M_PI);
	return RotateX_r(a);
}
ATMatrix4 ATMatrix4::MakeRotateY_r(float angle)//构造一个绕Y轴旋转矩阵
{
	ATMatrix4 _m;
	float c = cos(angle);
	float s = sin(angle);
	_m.m_Matrix._11 = c;
	_m.m_Matrix._13 = -s;
	_m.m_Matrix._31 = s;
	_m.m_Matrix._33 = c;
	return _m;
}
ATMatrix4& ATMatrix4::RotateY_r(float angle)//在自己的基础绕Y轴旋转
{
	ATMatrix4 _m;
	float c = cos(angle);
	float s = sin(angle);
	_m.m_Matrix._11 = c;
	_m.m_Matrix._13 = -s;
	_m.m_Matrix._31 = s;
	_m.m_Matrix._33 = c;
	(*this) *= _m;
	return *this;
}
ATMatrix4 ATMatrix4::MakeRotateY_d(float angle)//构造一个绕Y轴旋转矩阵
{
	float a = float(angle / 180 * M_PI);
	return MakeRotateY_r(a);
}
ATMatrix4& ATMatrix4::RotateY_d(float angle)//在自己的基础绕Y轴旋转
{
	float a = float(angle / 180 * M_PI);
	return RotateY_r(a);
}
ATMatrix4 ATMatrix4::MakeRotateZ_r(float angle)//构造一个绕Z轴旋转矩阵
{
	ATMatrix4 _m;
	float c = cos(angle);
	float s = sin(angle);
	_m.m_Matrix._11 = c;
	_m.m_Matrix._12 = s;
	_m.m_Matrix._21 = -s;
	_m.m_Matrix._22 = c;
	return _m;
}
ATMatrix4& ATMatrix4::RotateZ_r(float angle)//在自己的基础绕Z轴旋转
{
	ATMatrix4 _m;
	float c = cos(angle);
	float s = sin(angle);
	_m.m_Matrix._11 = c;
	_m.m_Matrix._12 = s;
	_m.m_Matrix._21 = -s;
	_m.m_Matrix._22 = c;
	(*this) *= _m;
	return *this;
}
ATMatrix4 ATMatrix4::MakeRotateZ_d(float angle)//构造一个绕Z轴旋转矩阵
{
	float a = float(angle / 180 * M_PI);
	return MakeRotateZ_r(a);
}
ATMatrix4& ATMatrix4::RotateZ_d(float angle)//在自己的基础绕Z轴旋转
{
	float a = float(angle / 180 * M_PI);
	return RotateZ_r(a);
}
ATMatrix4 ATMatrix4::MakeRotateXYZ_r(const ATVector3D& v, float a)
{
	float c = cos(a);
	float s = sin(a);
	ATMatrix4 _m;
	_m.m_Matrix._11 = v.x*v.x*(1 - c) + c;	  _m.m_Matrix._12 = v.x*v.y*(1 - c) - v.z*s; _m.m_Matrix._13 = v.x*v.z*(1 - c) + v.y*s;
	_m.m_Matrix._21 = v.x*v.y*(1 - c) + v.z*s; _m.m_Matrix._22 = v.y*v.y*(1 - c) + c;		_m.m_Matrix._23 = v.y*v.z*(1 - c) - v.x*s;
	_m.m_Matrix._31 = v.x*v.z*(1 - c) - v.y*s; _m.m_Matrix._32 = v.y*v.z*(1 - c) + v.x*s; _m.m_Matrix._33 = v.z*v.z*(1 - c) + c;
	return _m;
}
ATMatrix4& ATMatrix4::RotateXYZ_r(const ATVector3D& v, float a)
{
	float c = cos(a);
	float s = sin(a);
	ATMatrix4 _m;
	_m.m_Matrix._11 = v.x*v.x*(1 - c) + c;	  _m.m_Matrix._12 = v.x*v.y*(1 - c) - v.z*s; _m.m_Matrix._13 = v.x*v.z*(1 - c) + v.y*s;
	_m.m_Matrix._21 = v.x*v.y*(1 - c) + v.z*s; _m.m_Matrix._22 = v.y*v.y*(1 - c) + c;		_m.m_Matrix._23 = v.y*v.z*(1 - c) - v.x*s;
	_m.m_Matrix._31 = v.x*v.z*(1 - c) - v.y*s; _m.m_Matrix._32 = v.y*v.z*(1 - c) + v.x*s; _m.m_Matrix._33 = v.z*v.z*(1 - c) + c;
	(*this) *= _m;
	return *this;
}
ATMatrix4 ATMatrix4::MakeRotateXYZ_d(const ATVector3D& v, float angle)
{
	float a = float(angle / 180 * M_PI);
	return MakeRotateXYZ_r(v, a);
}
ATMatrix4& ATMatrix4::RotateXYZ_d(const ATVector3D& v, float angle)
{
	float a = float(angle / 180 * M_PI);
	return RotateXYZ_r(v, a);
}



void ATMatrix4::Identity()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				m_Matrix.m[i][j] = 1;
			}
			else
			{
				m_Matrix.m[i][j] = 0;
			}
		}
	}
}