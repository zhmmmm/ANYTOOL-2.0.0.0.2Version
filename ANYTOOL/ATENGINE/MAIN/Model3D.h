#pragma once

class Model3D
{
public:
	Model3D();
	~Model3D();

	void CreateAsBox(float c, float k, float g);
	void CreateAsZhuiTi(float h, float r, int side);
	void CreateYZT(float h, float r, int side);
	void CreateQT(float r, int side, int layer);
	void CreateZS(float h1, float h2, float r1, float r2, int side);
	void CreateYH(float r1, float r2, int side1, int side2);
	void DrawModel();
	void UpdateColor();
protected:
private:
	void __Clear();
	float* pVertex;//顶点数组的指针
	unsigned char * pColor;//颜色数组的指针
	unsigned int* pIndex;//索引数组的指针
	int vertexCount;//顶点个数
	int indexCount;//索引的个数
};