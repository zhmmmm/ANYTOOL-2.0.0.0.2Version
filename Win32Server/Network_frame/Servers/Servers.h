#pragma once
#include <iostream>
#include <vector>
#include "../Memory/Memory.h"
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")

#include "../Package/SendPackage.h"
#include "../Package/RecvPackage.h"
#include "../TCP/TCPPROTOCOLFAMILY.h"



//�ͻ������ӽ��������
#define _TSE_CONNECTED 0
//�ͻ��˶Ͽ�����
#define _TSE_DISCONNECTED 1
//�ͻ��˷��͹�������
#define _TSE_DATA 2

class TcpServer
{
public:
	//�����¼�
	struct EVENT
	{
		//�����¼�����
		int type;
		//�ͻ��˱�ʾ
		SOCKET sock;
		//����
		char* data;
		//����
		int size;
	};
private:

	//����INVALID_SOCKET����������
	//���������׽��֣��������ӳɹ�֮����׽���
	static SOCKET my_accept(SOCKET listen_sock);

	//����-1�������������
	//����0�����ͻ�����������ʱ���ܷ�������
	//����>0���Ѿ������˶����ֽ�
	static int my_send(SOCKET sock, char* buf, int len);

	//����-2�����ջ������ǿյĵ�ǰ���ɶ�
	//����-1�������������
	//����0���Է����ŶϿ�
	//����>0����ȡ�˶����ֽ�
	static int my_recv(SOCKET sock, char* buf, int len);

	//��������
	void _Accept();
	//��������
	void _Send();
	//��������
	void _Recv();
	//���������
	int m_Max;
	//������ݽ��ճ���
	int m_MaxRecv;
	//�����׽���
	SOCKET m_Listen;

	//�����¼���
	std::vector<EVENT> m_Events;
	//�ڴ��
	MemoryPool m_MemoryPool;

	//�������ݰ�
	struct SENDDATA
	{
		//�������ݵ��׵�ַ
		char* data;
		//�������ݵ��ܳ���
		int size;
		//�Ѿ����͵ĳ���
		int send_size;
	};

	//�ͻ���
	struct CLIENT
	{
		//�׽���
		SOCKET sock;
		//�������ݱ�
		std::vector<SENDDATA> send_data;
		//��������
		char* recv_data;
		int recv_size;
	};

	//�ͻ��˱�
	std::vector<CLIENT> m_Clients;
	//�ͷſͻ��������Ϣ
	void _Delete(CLIENT* client);

public:

	//��ʼ��
	bool Init(
		//�˿ں�
		unsigned short port,
		//�����������
		int max,
		//���������ݳ���
		int max_recv = 1024);
	//����
	void Run();

	//�õ������¼�
	bool GetEvent(EVENT* e);
	//�ͷ������¼��ڴ�
	void FreeEventMemory(EVENT* e);
	//�������ݸ�ָ���ͻ���
	bool Send(SOCKET sock, const void* data, int size);
	//�Ͽ�ָ���ͻ���
	bool Disconnect(SOCKET sock);
	//����
	void End();
};



class User
{
	SendPackage m_SendPackage;
	RecvPackage m_RecvPackage;

public:
	void User_Connected(SOCKET Socket, TcpServer &Server);
	void User_Disconnected(SOCKET Socket, TcpServer &Server);
	void User_Dataed(SOCKET Socket, const void *Data, int DataSize, TcpServer &Server);



private:
	void _Program();
};


class Server
{

	TcpServer m_TcpServer;

	User m_User;

public:
	Server();
	void RunServer();
	void CloseServer();
};

//=======================================================