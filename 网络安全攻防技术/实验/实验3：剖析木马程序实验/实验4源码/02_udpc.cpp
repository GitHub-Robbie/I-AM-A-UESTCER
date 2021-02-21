#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <stdio.h>
BOOL InitWinsock();
void main()
{
	SOCKET socket1;

	InitWinsock();
	struct sockaddr_in server;
	int len =sizeof(server);
	server.sin_family=AF_INET;
	server.sin_port=htons(1000);                      ///server的监听端口
	server.sin_addr.s_addr=inet_addr("12.1.34.217"); ///server的地址 

	socket1=socket(AF_INET,SOCK_DGRAM,0);
	while (1)
	{

		char buffer[1024]="\0";
		printf("input message\n");
		scanf("%s",buffer);
		if (strcmp(buffer,"bye")==0)
			break;
		if (sendto(socket1,buffer,sizeof buffer,0,(struct sockaddr*)&server,len)!=SOCKET_ERROR)
		{	
			if (recvfrom(socket1,buffer,sizeof buffer,0,(struct sockaddr*)&server,&len)!=SOCKET_ERROR)
				printf("rece from server:%s\n",buffer);
		}		
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