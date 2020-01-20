#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8000

int socketfd;
struct sockaddr_in saddr;
struct sockaddr_in caddr;

void RecvSignal(int sig)
{
	printf("recv signal is : %d\n", sig);
}

int InitSocket()
{
	signal(SIGPIPE, RecvSignal);
	int result = 0;
	printf("socket ...\n");
	socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd < 0)
	{
		perror("socket error : ");
		return -1;
	}

	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = INADDR_ANY;

	printf("bind ...\n");
	result = bind(socketfd, (struct sockaddr *)&saddr, sizeof(saddr));
	if(result < 0)
	{
		perror("bind error : ");
		return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int len;
	int flag = 1;
	int result = 0;
	char buf[1024];

	result = InitSocket();
	if(result < 0)
	{
		printf("init socket error ...\n");
		return -1;
	}
	len = sizeof(caddr);
	printf("socketfd = %d\n", socketfd);

	while(flag)
	{
		printf("recvfrom ...\n");
		result = recvfrom(socketfd, buf, 1024, 0, (struct sockaddr *)&saddr, &len);
		if(result < 0)
		{
			perror("recv error : ");
			return -1;
		}
		printf("recv data = %s\n", buf);
		
		result = sendto(socketfd, "hello", 6, 0, (struct sockaddr *)&saddr, sizeof(saddr));
		if(result < 0)
		{
			perror("write error: ");
			return -1;
		}
		printf("write hello success ...\n");
	}

	return 0;
}
