#include "ATMatrix3.h"

ATMatrix3::ATMatrix3()
{
	memset(m_Matrix.m, 0, sizeof(double) * 9);
}
ATMatrix3::ATMatrix3(const ATMatrix3& old)
{
	memcpy(m_Matrix.m, old.m_Matrix.m, sizeof(double) * 9);
}
ATMatrix3::ATMatrix3(double _11, double _12, double _13, double _21, double _22, double _23, double _31, double _32, double _33)
{
	m_Matrix._11 = _11; m_Matrix._12 = _12; m_Matrix._13 = _13;
	m_Matrix._21 = _21; m_Matrix._22 = _22; m_Matrix._23 = _23;
	m_Matrix._31 = _31; m_Matrix._32 = _32; m_Matrix._33 = _33;
}
ATMatrix3::ATMatrix3(double m[3][3])
{
	memcpy(m_Matrix.m, m, sizeof(double) * 9);
}
ATMatrix3::ATMatrix3(double** m)
{
	memcpy(m_Matrix.m[0], m[0], sizeof(double) * 3);
	memcpy(m_Matrix.m[1], m[1], sizeof(double) * 3);
	memcpy(m_Matrix.m[2], m[2], sizeof(double) * 3);
}
double ATMatrix3::GetDet()
{
	double det = m_Matrix._11*m_Matrix._22*m_Matrix._33
		+ m_Matrix._12*m_Matrix._23*m_Matrix._31
		+ m_Matrix._13*m_Matrix._21*m_Matrix._32
		- m_Matrix._13*m_Matrix._22*m_Matrix._31
		- m_Matrix._12*m_Matrix._21*m_Matrix._33
		- m_Matrix._11*m_Matrix._23*m_Matrix._32;
	return det;
}
double GetDetRank2(double src[2][2])//求2阶行列式值
{
	double det = src[0][0] * src[1][1] - src[0][1] * src[1][0];
	return det;
}
double GetCofactor(int Row, int Col, _CMATRIX3 src)//取任意行列2阶代数余子式
{
	double temp[4] = {};
	double det = 0;
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != Row && j != Col)
			{
				temp[index++] = src.m[i][j];
			}
		}
	}
	det = temp[0] * temp[3] - temp[1] * temp[2];
	det *= pow(double(-1), Row + Col);
	return det;
}
ATMatrix3 ATMatrix3::Transpose()//求转置矩阵
{
	ATMatrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[j][i];
		}
	}
	return temp;
}
ATMatrix3 ATMatrix3::Adjoint()//求伴随矩阵
{
	ATMatrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.m_Matrix.m[j][i] = GetCofactor(i, j, m_Matrix);
		}
	}
	return temp;
}
ATMatrix3 ATMatrix3::Inverse(bool &IsInverse)//求逆矩阵//传入一个逻辑引用参数，来判断是否可逆
{
	ATMatrix3 temp;//初始为0矩阵
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
ATMatrix3 ATMatrix3::GetScaleMtr(double x_ratio, double y_ratio)//比例变换矩阵
{
	ATMatrix3 T(x_ratio, 0, 0,
		0, y_ratio, 0,
		0, 0, 1);
	return T;
}
ATMatrix3 ATMatrix3::GetEqlScaleMtr(double s_ratio)//等比例变换矩阵
{
	ATMatrix3 T(1 / s_ratio, 0, 0,
		0, 1 / s_ratio, 0,
		0, 0, 1);//这样处理是不希望要在最后判断H是否为1
	return T;
}
ATMatrix3 ATMatrix3::GetRotateMtr(double angle)//旋转矩阵
{
	ATMatrix3 T(cos(angle), sin(angle), 0,
		-sin(angle), cos(angle), 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::GetTranslationMtr(double x_m, double y_n)//平移
{
	ATMatrix3 T(1, 0, 0,
		0, 1, 0,
		x_m, y_n, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::GetX_Symmetry()//X对称变换
{
	ATMatrix3 T(1, 0, 0,
		0, -1, 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::GetY_Symmetry()//Y对称变换
{
	ATMatrix3 T(-1, 0, 0,
		0, 1, 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::GetO_Symmetry()//原点对称变换
{
	ATMatrix3 T(-1, 0, 0,
		0, -1, 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::Get45_Symmetry()//+45°对称变换
{
	ATMatrix3 T(0, 1, 0,
		1, 0, 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::Get_45_Symmetry()//-45°对称变换
{
	ATMatrix3 T(0, -1, 0,
		-1, 0, 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::Get_Angle_Symmetry(double angle)//关于过原点任意角度直线的对称变换
{
	ATMatrix3 T(cos(2 * angle), sin(2 * angle), 0,
		sin(2 * angle), -cos(2 * angle), 0,
		0, 0, 1);
	return T;
}
ATMatrix3 ATMatrix3::GetX_TiltMtr(double angle)//X错切变换
{
	ATMatrix3 T(1, tan(angle), 0,
		0, 1, 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::GetY_TiltMtr(double angle)//Y错切变换
{
	ATMatrix3 T(1, 0, 0,
		tan(angle), 1, 0,
		0, 0, 1
	);
	return T;
}
ATMatrix3 ATMatrix3::operator + (const ATMatrix3& other)
{
	ATMatrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[i][j] + other.m_Matrix.m[i][j];
		}
	}
	return temp;
}
ATMatrix3 ATMatrix3::operator - (const ATMatrix3& other)
{
	ATMatrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[i][j] - other.m_Matrix.m[i][j];
		}
	}
	return temp;
}
ATMatrix3 ATMatrix3::operator * (const double k)
{
	ATMatrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.m_Matrix.m[i][j] = m_Matrix.m[i][j] * k;
		}
	}
	return temp;
}
ATVector2D ATMatrix3::operator * (ATVector2D& p)
{
	ATMatrix3 O(p.x, p.y, 1, 0, 0, 0, 0, 0, 0);
	O *= (*this);
	ATVector2D ret((float)O.m_Matrix._11, (float)O.m_Matrix._12);
	return ret;
}
ATMatrix3 ATMatrix3::operator * (const ATMatrix3& other)
{
	ATMatrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temp.m_Matrix.m[i][j] += m_Matrix.m[i][k] * other.m_Matrix.m[k][j];
			}
		}
	}
	return temp;
}
ATMatrix3& ATMatrix3::operator += (const ATMatrix3& other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_Matrix.m[i][j] += other.m_Matrix.m[i][j];
		}
	}
	return *this;
}
ATMatrix3& ATMatrix3::operator -= (const ATMatrix3& other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_Matrix.m[i][j] -= other.m_Matrix.m[i][j];
		}
	}
	return *this;
}
ATMatrix3& ATMatrix3::operator *= (const double k)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_Matrix.m[i][j] *= k;
		}
	}
	return *this;
}
ATMatrix3& ATMatrix3::operator *= (const ATMatrix3& other)
{
	ATMatrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temp.m_Matrix.m[i][j] += m_Matrix.m[i][k] * other.m_Matrix.m[k][j];
			}
		}
	}
	memcpy(m_Matrix.m, temp.m_Matrix.m, sizeof(double) * 9);
	return *this;
}
void ATMatrix3::ShowData(char* MatrixName)
{
	if (MatrixName != NULL)
	{
		cout << MatrixName << "[3×3] = \n";
	}
	else
	{
		cout << "A[3×3] = \n";
	}
	cout << "╭                                      ╮\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "│";
		for (int j = 0; j < 3; j++)
		{
			printf("%12.6lf", m_Matrix.m[i][j]);
			if (j < 2)
			{
				cout << ",";
			}
		}
		cout << "│" << endl;
	}
	cout << "╰                                      ╯\n";
}






ATMatrix3& ATMatrix3::Identity()
{
	m_Matrix._11 = 1, m_Matrix._12 = 0, m_Matrix._13 = 0;
	m_Matrix._21 = 0, m_Matrix._22 = 1, m_Matrix._23 = 0;
	m_Matrix._31 = 0, m_Matrix._32 = 0, m_Matrix._33 = 1;
	return *this;
}
ATMatrix3& ATMatrix3::Translate(float x, float y)
{
	ATMatrix3 tmp;
	tmp.m_Matrix._31 = x;
	tmp.m_Matrix._32 = y;
	*this = (*this)*tmp;
	return *this;
}
ATMatrix3 ATMatrix3::SetTranslate(float x, float y)
{
	m_Matrix._31 = x;
	m_Matrix._32 = y;
	return *this;
}
ATMatrix3& ATMatrix3::Scale(float x, float y)
{
	ATMatrix3 tmp;
	tmp.m_Matrix._11 = x;
	tmp.m_Matrix._22 = y;
	*this = (*this)*tmp;
	return *this;
}
ATMatrix3 ATMatrix3::SetScale(float x, float y)
{
	m_Matrix._11 = x;
	m_Matrix._22 = y;
	return *this;
}
ATMatrix3& ATMatrix3::Rotate_R__(float Angle_r)
{
	ATMatrix3 tmp;
	tmp.m_Matrix._11 = cos(Angle_r);
	tmp.m_Matrix._12 = sin(Angle_r);
	tmp.m_Matrix._21 = -tmp.m_Matrix._12;
	tmp.m_Matrix._22 = tmp.m_Matrix._11;
	*this = (*this)*tmp;
	return *this;
}
ATMatrix3 ATMatrix3::SetRotate_R__(float Angle_r)
{
	m_Matrix._11 = cos(Angle_r);
	m_Matrix._12 = sin(Angle_r);
	m_Matrix._21 = -m_Matrix._12;
	m_Matrix._22 = m_Matrix._11;
	return *this;
}
ATMatrix3& ATMatrix3::Rotate_D__(float Angle_d)
{
	return Rotate_R__(float(Angle_d / 180 * M_PI));
}
ATMatrix3 ATMatrix3::SetRotate_D__(float Angle_d)
{
	return SetRotate_R__(float(Angle_d*M_PI / 180));
}