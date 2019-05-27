/*
����˵��:==>
*/
#include "Scene.h"

void Scene::Start()
{
	S = new Sprite("1.bmp");

	this->m_Windows_X = 10;
	this->m_Windows_Y = 10;
	this->m_WindowsWidth = 800;
	this->m_WindowsHeight = 600;
	this->m_CameraPos_Y = 20;
	this->m_CameraPos_Z = 50;
}


static int Angle = 0;
float trag[] =
{
	0,10,+30,0,255,255,//��¼���Ƕ���λ�úͶ�����ɫ
	+30,10,-30,255,255,0,
	-30,10,-30,255,0,0
};

unsigned char color[] =
{
255,0,0,
255,255,0,
255,255
};

float jzt[] = 
{
	//0,1,2
	0,+20,0,255,0,0,//�����������ɫ����
	-20,0,0,255,255,0,
	0,0,+20,0,0,255,
	//0,2,3
	0,+20,0,255,0,0,
	0,0,+20,0,0,255,
	+20,0,0,0,255,0,
	//0,3,4
	0,+20,0,255,0,0,
	+20,0,0,0,255,0,
	0,0,-20,0,255,255,

	//0,4,1
	0,+20,0,255,0,0,
	0,0,-20,0,255,255,
	-20,0,0,255,255,0,

	//1,3,2
	-20,0,0,255,255,0,
	+20,0,0,0,255,0,
	0,0,+20,0,0,255,
	//1,4,3
	-20,0,0,255,255,0,
	0,0,-20,0,255,255,
	+20,0,0,0,255,0,
};

unsigned int index[] =
{
	0,1,2,0,2,3,
	4,6,5,4,7,6,
	0,4,5,0,5,1,
	2,6,7,2,7,3,
	2,1,5,2,5,6,
	0,3,7,0,7,4
};

float box[] =
{
	-20,+20,-20,//255,255,0,
	-20,+20,+20,//255,0,255,
	+20,+20,+20,//0,255,255,
	+20,+20,-20,//255,0,0,
	-20,-20,-20,//0,255,0,
	-20,-20,+20,//0,0,255,
	+20,-20,+20,//127,0,127,
	+20,-20,-20,//0,127,0,
};

void Scene::Update()
{
	Camera::CameraToWorld(this);

	AT->ATENGINE_VertexPointer(
		3,//ά��
		GL_FLOAT,//��������
		12,//���������붥������֮����ֽڼ����
		box);

	AT->ATENGINE_ColorPointer(
		3,//������ɫ��������
		GL_FLOAT,
		12,//��ɫ����ɫ����֮����ֽڼ����
		color);

	//ʹ����������
	AT->ATENGINE_DrawElements(
		GL_TRIANGLES,//Ҫ����ͼԪ����
		36,//��������
		GL_UNSIGNED_INT,//�������������ͣ��������޷��ŵ�����
		index);//�����ַ

}

void Scene::OnOrdinaryKeyboardDownEvent(unsigned char Key, int X, int Y)
{
	CVector3D T(m_LookAt_X,m_LookAt_Y,m_LookAt_Z);
	CVector3D C(m_CameraPos_X,m_CameraPos_Y,m_CameraPos_Z);

	CVector3D n = (T - C).normalized();

	std::cout << "��ͨ���£�" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 'w' || Key == 'W')
	{
		//m_CameraPos_Z -= m_MoveSpeed_Z;
		CVector3D t(m_CameraPos_X, m_CameraPos_Y, m_CameraPos_Z);
		t += n * m_MoveSpeed_Z;
		m_CameraPos_Z = t.z;
	}
	if (Key == 's' || Key == 'S')
	{
		//m_CameraPos_Z += m_MoveSpeed_Z;
		CVector3D t(m_CameraPos_X, m_CameraPos_Y, m_CameraPos_Z);
		t -= n * m_MoveSpeed_Z;
		m_CameraPos_Z = t.z;
	}
	if (Key == 'a' || Key == 'A')
	{
		m_CameraPos_X -= m_MoveSpeed_X;
	}
	if (Key == 'd' || Key == 'D')
	{
		m_CameraPos_X += m_MoveSpeed_X;
	}
	if (Key == '\r')
	{
		exit(0);
	}
}
void Scene::OnSpecialKeyboardDownEvent(int Key, int X, int Y)
{
	std::cout << "���ܰ��£�" << Key << " X = " << X << " Y = " << Y << std::endl;
	if (Key == 101)
	{
		ATA->VolumeAdd();
	}
	if (Key == 103)
	{
		ATA->VolumeReduce();
	}
}
void Scene::OnMouseMoveEvent(int Mouse_X, int Mouse_Y)
{
	std::cout << "����ƶ� " << "X = " << Mouse_X << " Y = " << Mouse_Y << std::endl;
	//m_LookAt_X = Mouse_X - m_WindowsWidth / 2;
	//m_LookAt_Y = -(Mouse_Y - m_WindowsHeight / 2);
}

void Scene::End()
{
	delete S;
	S = NULL;
}