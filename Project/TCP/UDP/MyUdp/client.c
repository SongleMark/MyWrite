#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>

#define PORT 8000
#define IP   "192.168.8.100"

int Socketfd;
struct sockaddr_in saddr, caddr;;

void RecvSignal(int sig)
{
	printf("recv signal is : %d\n", sig);
}

int InitUdpSocket()
{
	signal(SIGPIPE, RecvSignal);
	printf("socket ...\n");
	Socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(Socketfd < 0)
	{
		perror("socket error:");
		return -1;
	}

	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = inet_addr(IP);

	return 0;
}

int main(int argc, char *argv[])
{
	int result = InitUdpSocket();
	int flag = 1;
	char data[32];
	if(result < 0)
	{
		perror("init socket error:");
		return -1;
	}
	
	printf("socketfd = %d\n", Socketfd);
	printf("init socket success ...\n");
	while(flag)
	{
		printf("please input : ");
		scanf("%s", data);
		getchar();
		
		printf("sendto ...\n");
		int ret = sendto(Socketfd, data, strlen(data) + 1, 0, (struct sockaddr *)&saddr, (socklen_t)sizeof(saddr));
		if(ret < 0)
		{
			perror("send to error:");
			return -1;
		}
		else
		{
			char buf[32];
			int len = sizeof(caddr);
			printf("send message successed ...\n");
			int ret = recvfrom(Socketfd, buf, 32, 0, (struct sockaddr *)&saddr, &len);
			if(ret < 0)
			{
				perror("read error: ");
				return -1;
			}
			printf("read buf = %s\n", buf);
		}
	}

	return 0;
}
