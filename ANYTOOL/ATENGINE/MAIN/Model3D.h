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
	float* pVertex;//���������ָ��
	unsigned char * pColor;//��ɫ�����ָ��
	unsigned int* pIndex;//���������ָ��
	int vertexCount;//�������
	int indexCount;//�����ĸ���
};