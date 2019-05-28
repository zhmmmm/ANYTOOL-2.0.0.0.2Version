#include "Model3D.h"
#include <gl/glew.h>
#include <gl/glut.h>
#include <iostream>
using namespace std;
#include <Windows.h>
#include <cmath>
#define M_PI       3.14159265358979323846

Model3D::Model3D()
{
	pVertex = NULL;
	pColor = NULL;
	pIndex = NULL;
	vertexCount = indexCount = 0;
}
Model3D::~Model3D()
{
	__Clear();
}

void Model3D::__Clear()
{
	if (pVertex != NULL)
	{
		delete[] pVertex;
		delete[] pColor;
		delete[] pIndex;
	}
	pVertex = NULL;
	pColor = NULL;
	pIndex = NULL;
	vertexCount = indexCount = 0;
}
void Model3D::CreateAsBox(float c, float k, float g)
{
	__Clear();
	vertexCount = 8;
	indexCount = 36;
	pVertex = new float[vertexCount * 3];
	pColor = new unsigned char[vertexCount * 3];
	pIndex = new unsigned int[36];//12个三角形*每个三角形三个索引


	float cc = c / 2, kk = k / 2, gg = g / 2;

	for (int i = 0; i < vertexCount; i++)
	{
		float* p = i * 3 + pVertex;
		//设置x
		if (i == 0 || i == 3 || i == 4 || i == 7)
		{
			p[0] = -cc;
		}
		else
		{
			p[0] = cc;
		}
		//设置y
		if (i < 4)
		{
			p[1] = gg;
		}
		else
		{
			p[1] = -gg;
		}
		//设置z
		if (i == 0 || i == 1 || i == 4 || i == 5)
		{
			p[2] = kk;
		}
		else
		{
			p[2] = -kk;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		unsigned char* p = i * 3 + pColor;
		p[0] = rand() % 256;
		p[1] = rand() % 256;
		p[2] = rand() % 256;
	}

	pIndex[0] = 0; pIndex[1] = 1; pIndex[2] = 2;
	pIndex[3] = 0; pIndex[4] = 2; pIndex[5] = 3;
	pIndex[6] = 4; pIndex[7] = 5; pIndex[8] = 1;
	pIndex[9] = 4; pIndex[10] = 1; pIndex[11] = 0;
	pIndex[12] = 0; pIndex[13] = 3; pIndex[14] = 7;
	pIndex[15] = 0; pIndex[16] = 7; pIndex[17] = 4;
	pIndex[18] = 5; pIndex[19] = 6; pIndex[20] = 2;
	pIndex[21] = 5; pIndex[22] = 2; pIndex[23] = 1;
	pIndex[24] = 2; pIndex[25] = 6; pIndex[26] = 7;
	pIndex[27] = 2; pIndex[28] = 7; pIndex[29] = 3;
	pIndex[30] = 4; pIndex[31] = 7; pIndex[32] = 6;
	pIndex[33] = 4; pIndex[34] = 6; pIndex[35] = 5;
}
void Model3D::CreateAsZhuiTi(float h, float r, int side)
{
	__Clear();
	pVertex = new float[(side + 2) * 3];
	pColor = new unsigned char[(side + 2) * 3];
	pIndex = new unsigned int[side * 2 * 3];

	vertexCount = (side + 2) * 3;
	indexCount = side * 2 * 3;

	//
	pVertex[vertexCount - 6] = pVertex[vertexCount - 4] = 0; pVertex[vertexCount - 5] = h;//设置的上面的顶点
	pVertex[vertexCount - 3] = pVertex[vertexCount - 2] = pVertex[vertexCount - 1] = 0;

	for (int i = 0; i < side; ++i)
	{
		//得到的是每一个中间边的顶点
		float* p = pVertex + i * 3;
		float angle = M_PI * 2 / side * i;
		p[1] = 0;
		p[0] = r * sin(angle);
		p[2] = r * cos(angle);
	}


	//颜色
	for (int i = 0; i < vertexCount / 3; i++)
	{
		unsigned char* p = i * 3 + pColor;
		p[0] = rand() % 256;
		p[1] = rand() % 256;
		p[2] = rand() % 256;
	}

	//填充索引
	for (int i = 0; i < side; i++)
	{
		unsigned int * p = pIndex + i * 3;
		p[0] = i;
		p[1] = (i + 1) % side;//2,3 3,4
		p[2] = side;
	}
	for (int i = 0; i < side; i++)
	{
		unsigned int *p = pIndex + side * 3 + i * 3;
		p[0] = (i + 1) % side;
		p[1] = i;
		p[2] = side + 1;
	}
}
void Model3D::CreateYZT(float h, float r, int side)
{
	__Clear();
	pVertex = new float[(side * 2) * 3];
	pColor = new unsigned char[(side * 2) * 3];
	pIndex = new unsigned int[(side - 1) * 4 * 3];

	vertexCount = (side * 2) * 3;
	indexCount = (side - 1) * 4 * 3;

	for (int i = 0; i < side; ++i)
	{
		float* p1 = pVertex + i * 3;
		float* p2 = pVertex + side * 3 + i * 3;
		float angle = M_PI * 2 / side * i;
		p2[0] = p1[0] = r * sin(angle);
		p1[1] = h / 2; p2[1] = -h / 2;
		p2[2] = p1[2] = r * cos(angle);
	}

	for (int i = 0; i < side - 2; ++i)
	{
		//0	12
		//0	23
		unsigned int* p1 = pIndex + i * 3;
		p1[0] = 0;
		p1[1] = i + 1;
		p1[2] = i + 2;
		unsigned int* p2 = pIndex + (side - 2) * 3 + i * 3;
		p2[0] = side;
		p2[1] = side + i + 2;
		p2[2] = side + i + 1;
	}
	for (int i = 0; i < side; i++)
	{
		unsigned int* p = pIndex + (side - 2) * 6 + i * 6;
		p[0] = i;
		p[1] = side + i;
		p[2] = (side + i + 1) % side + side;
		p[3] = i;
		p[4] = (side + i + 1) % side + side;
		p[5] = (i + 1) % side;
	}

	for (int i = 0; i < vertexCount / 3; i++)
	{
		unsigned char* p = i * 3 + pColor;
		p[0] = rand() % 256;
		p[1] = rand() % 256;
		p[2] = rand() % 256;
	}
}
void Model3D::CreateQT(float r, int side, int layer)//layer 包含顶点上下两层
{
	__Clear();
	pVertex = new float[(side*(layer - 1) + 2) * 3];
	pColor = new unsigned char[(side*(layer - 1) + 2) * 3];
	pIndex = new unsigned int[(side * 2 + (layer - 2) * 2 * side) * 3];
	vertexCount = (side*(layer - 1) + 2) * 3;
	indexCount = (side * 2 + (layer - 2) * 2 * side) * 3;
	for (int i = 0; i < vertexCount / 3; i++)
	{
		unsigned char* p = i * 3 + pColor;
		p[0] = rand() % 50 + 200;
		p[1] = rand() % 256;
		p[2] = 0;
	}

	for (int i = 0; i < layer - 1; ++i)
	{
		float angle = M_PI / layer * (i + 1);
		float x = abs(r*sin(angle));//每一层圆的半径
		float y = r * cos(angle);
		for (int j = 0; j < side; j++)
		{
			float* p = pVertex + i * side * 3 + j * 3;
			float angle2 = M_PI * 2 / side * j;
			p[0] = x * sin(angle2);
			p[1] = y;
			p[2] = x * cos(angle2);
		}
	}
	pVertex[vertexCount - 6] = 0; pVertex[vertexCount - 5] = r; pVertex[vertexCount - 4] = 0;
	pVertex[vertexCount - 3] = 0; pVertex[vertexCount - 2] = -r; pVertex[vertexCount - 1] = 0;

	for (int j = 0; j < layer - 2; j++)//多少层
	{
		for (int i = 0; i < side; i++)//一层多少次
		{
			unsigned int* p = pIndex + j * side * 6 + i * 6;
			p[0] = i + side * j;
			p[1] = side + i + side * j;
			p[2] = (side + i + 1) % side + side + side * j;
			p[3] = i + side * j;
			p[4] = (side + i + 1) % side + side + side * j;
			p[5] = (i + 1) % side + side * j;
		}
	}
	for (int i = 0; i < side; ++i)
	{
		unsigned int idtop = (layer - 1)*side;//上面顶点的索引号
		unsigned int idbutton = idtop + 1;
		unsigned int * p1 = pIndex + (layer - 2)*side * 6 + i * 3;
		unsigned int * p2 = p1 + side * 3;
		p1[0] = idtop;
		p1[1] = i;
		p1[2] = (i + 1) % side;
		p2[0] = idbutton;
		p2[1] = (layer - 2)*side + (i + 1) % side;
		p2[2] = (layer - 2)*side + i;
	}
}
void Model3D::CreateZS(float h1, float h2, float r1, float r2, int side)
{
	__Clear();
	pVertex = new float[(side * 2 + 1) * 3];
	pColor = new unsigned char[(side * 2 + 1) * 3];
	pIndex = new unsigned int[(side - 2 + side * 2 + side) * 3];
	vertexCount = (side * 2 + 1) * 3;
	indexCount = (side - 2 + side * 2 + side) * 3;

	for (int i = 0; i < side; i++)
	{
		float* p1 = pVertex + i * 3;
		float* p2 = pVertex + side * 3 + i * 3;
		float angle1 = M_PI * 2 / side * i;
		float angle2 = angle1 + M_PI / side;
		p1[0] = r1 * sin(angle1);
		p1[1] = h1;
		p1[2] = r1 * cos(angle1);
		p2[0] = r2 * sin(angle2);
		p2[1] = 0;
		p2[2] = r2 * cos(angle2);
	}
	pVertex[vertexCount - 3] = pVertex[vertexCount - 1] = 0; pVertex[vertexCount - 2] = -h2;

	for (int i = 0; i < vertexCount / 3; i++)
	{
		unsigned char* p = i * 3 + pColor;
		p[0] = rand() % 256;
		p[1] = rand() % 256;
		p[2] = rand() % 256;
	}

	for (int i = 0; i < side - 2; i++)
	{
		unsigned int* p = pIndex + i * 3;
		p[0] = 0;
		p[1] = i + 1;
		p[2] = i + 2;
	}

	for (int i = 0; i < side; i++)
	{
		unsigned int* p = pIndex + (side - 2) * 3 + i * 6;
		p[0] = i;
		p[1] = side + i;
		p[2] = (i + 1) % side;
		p[3] = (i + 1) % side;
		p[4] = side + i;
		p[5] = (side + i + 1) % side + side;
		unsigned int* p1 = pIndex + (side - 2) * 3 + side * 2 * 3 + i * 3;
		p1[0] = side * 2;
		p1[1] = (side + i + 1) % side + side;
		p1[2] = side + i;
	}
}
//r1:圆环大半径
//r2:圆环小半径
//side1 圆环大分区
//side2	圆截面分区
void Model3D::CreateYH(float r1, float r2, int side1, int side2)
{
	__Clear();
	pVertex = new float[side1*side2 * 3];
	pColor = new unsigned char[side1*side2 * 3];
	pIndex = new unsigned int[side1 * 2 * side2 * 3];
	vertexCount = side1 * 3 * side2;//27,36
	indexCount = side1 * 2 * side2 * 3;//54,72

	for (int i = 0; i < side1; i++)
	{
		float angle1 = M_PI * 2 / side1 * i;
		for (int j = 0; j < side2; j++)
		{
			int id = i * side2 * 3 + j * 3;
			cout << id << endl;
			float* p = pVertex + i * side2 * 3 + j * 3;
			float angle2 = M_PI * 2 / side2 * j;
			p[0] = (r2*sin(angle2) + r1)*cos(angle1);
			p[1] = r2 * cos(angle2);
			p[2] = (r2*sin(angle2) + r1)*sin(angle1);
		}
	}
	for (int i = 0; i < vertexCount / 3; i++)
	{
		unsigned char* p = i * 3 + pColor;
		p[0] = rand() % 256;
		p[1] = rand() % 256;
		p[2] = rand() % 256;
	}
	for (int i = 0; i < side1; ++i)
	{
		for (int j = 0; j < side2; j++)
		{
			unsigned int* p = pIndex + i * side2 * 6 + j * 6;
			if (i < side1 - 1)
			{
				p[0] = side2 * i + j;
				p[1] = side2 * (i + 1) + j;
				p[2] = side2 * (i + 1) + (j + 1) % side2;
				p[3] = side2 * i + j;
				p[4] = side2 * (i + 1) + (j + 1) % side2;
				p[5] = side2 * i + (j + 1) % side2;
			}
			else
			{
				p[0] = side2 * i + j;
				p[1] = j;
				p[2] = (j + 1) % side2;
				p[3] = side2 * i + j;
				p[4] = (j + 1) % side2;
				p[5] = side2 * i + (j + 1) % side2;
			}
		}
	}
}
void Model3D::UpdateColor()
{
	for (int i = 0; i < vertexCount / 3; i++)
	{
		unsigned char* pc = pColor + i * 3;
		pc[0] += 1;
		pc[1] += 1;
		pc[2] += 1;
	}
}
void Model3D::DrawModel()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glVertexPointer(
		//顶点的维度，可以是2、3、4
		3,
		//顶点数组的类型
		GL_FLOAT,
		//每个顶点之间的间隔字节数，
		//一般就填写0即可
		0,
		//要绘制的顶点地址
		pVertex);

	glColorPointer(
		//颜色的分量
		3,
		//颜色分量的类型
		GL_UNSIGNED_BYTE,
		//每个颜色的间隔字节数
		0,
		//颜色数组
		pColor);
	//索引绘制立方体
	glDrawElements(
		//要绘制图元类型
		GL_TRIANGLES,
		//索引数量
		indexCount,
		//索引类型，必须是无符号的
		GL_UNSIGNED_INT,
		//索引数组
		pIndex);
}