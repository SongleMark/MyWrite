#include "common.h"

void fun(int sig)
{
	printf("recv sig:%d\n",sig);
	return;
}

int main()
{
	int fd;
	struct sockaddr_in saddr;
	int ret;

	signal(SIGPIPE,fun);
	printf("socket ..\n");
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("ERROR:socket");
		return -1;
	}

	saddr.sin_family = AF_INET;
	saddr.sin_port   = htons(8000);
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("connect..\n");
	ret = connect(fd, (struct sockaddr*) &saddr ,sizeof(saddr));
	if(ret<0)
	{
		perror("ERROR:connect");
		close(fd);
		return -1;
	}
	printf("send data..\n");
	ret = write(fd,"hello",6);
	if(ret<0)
	{
		perror("ERROR:write");
	}
	else
	{
		printf("send hello success.");
	}

	printf("close...\n");
	close(fd);
}
