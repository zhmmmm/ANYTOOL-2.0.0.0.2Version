#include "Camera.h"


Camera::Camera(Object Obj)
{
	ATENGINE->ATENGINE_MatrixMode();
	gluLookAt(
		Obj.m_CameraPos_X, Obj.m_CameraPos_Y, Obj.m_CameraPos_Z,//�۾� (�����λ��)
		Obj.m_LookAt_X, Obj.m_LookAt_Y, Obj.m_CameraPos_Z - Obj.m_CameraPos_Z,//��Ա (����������λ��)
		0, 1, 0);//������Ϸ������� (��ʾ�ֳ�����������������)
}

Camera::Camera(Object *Obj)
{
	ATENGINE->ATENGINE_MatrixMode();
	gluLookAt(
		Obj->m_CameraPos_X, Obj->m_CameraPos_Y, Obj->m_CameraPos_Z,//�۾� (�����λ��)
		Obj->m_LookAt_X, Obj->m_LookAt_Y, Obj->m_LookAt_Z - Obj->m_CameraPos_Z,//��Ա (����������λ��)
		0, 1, 0);//������Ϸ������� (��ʾ�ֳ�����������������)
}

void Camera::CameraToWorld(Object Obj)
{
	Camera::Camera(Obj);
}
void Camera::CameraToWorld(Object *Obj)
{
	Camera::Camera(Obj);
}