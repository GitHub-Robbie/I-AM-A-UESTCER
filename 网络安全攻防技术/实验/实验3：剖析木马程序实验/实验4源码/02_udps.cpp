#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
BOOL InitWinsock();
void main()
{
	SOCKET socket1;

	InitWinsock();
	struct sockaddr_in local;
	struct sockaddr_in from;
	int fromlen =sizeof(from);
	local.sin_family=AF_INET;
	local.sin_port=htons(1000);             ///监听端口
	local.sin_addr.s_addr=INADDR_ANY;       ///本机

	socket1=socket(AF_INET,SOCK_DGRAM,0);

	bind(socket1,(struct sockaddr*)&local,sizeof local);

	while (1)
	{
		char buffer[1024]="\0";
		printf("waiting for message from others-------------\n");
		if (recvfrom(socket1,buffer,sizeof buffer,0,(struct sockaddr*)&from,&fromlen)!=SOCKET_ERROR)
		{
			printf("Received datagram from %s--%s\n",inet_ntoa(from.sin_addr),buffer);
			////给cilent发信息
			sendto(socket1,buffer,sizeof buffer,0,(struct sockaddr*)&from,fromlen);

		}
		Sleep(500);
	}

	closesocket(socket1);


}

BOOL InitWinsock()
{
	int Error;
	WORD VersionRequested;
	WSADATA WsaData;
	VersionRequested=MAKEWORD(2,2);
	Error=WSAStartup(VersionRequested,&WsaData); //启动WinSock2
	if(Error!=0)
	{
		return FALSE;
	}
	else
	{
		if(LOBYTE(WsaData.wVersion)!=2||HIBYTE(WsaData.wHighVersion)!=2)
		{
			WSACleanup();
			return FALSE;
		}
		
	}
	return TRUE;
}