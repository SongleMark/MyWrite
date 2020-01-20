#include "common.h"

void fun(int sig)
{
	printf("recv sig:%d\n",sig);
	return;
}

int main()
{
	int fd,nfd;
	struct sockaddr_in saddr,caddr;
	int ret;
	int addr_len;
	char buf[1024];

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
	saddr.sin_addr.s_addr = INADDR_ANY;
	printf("bind..\n");
	ret = bind(fd,(struct sockaddr*) &saddr,sizeof(saddr));
	if(ret<0)
	{
		perror("ERROR:bind");
		close(fd);
		return -1;
	}
	printf("listen\n");
	ret = listen(fd,20);
	if(ret<0)
	{
		perror("ERROR:listen");
		close(fd);
		return -1;
	}
	while(1) {
	printf("accept.\n");
	addr_len = sizeof(caddr);
	nfd = accept(fd,(struct sockaddr *)&caddr,&addr_len);


	printf("read.\n");
	ret = read(nfd,buf,1024);
	if(ret<0)
	{
		perror("ERROR:read");
		close(nfd);
	}
	else if(ret == 0)
	{
		printf("TCP broken.\n");
		close(nfd);
	}
	else
	{
		printf("read buf:%s\n",buf);
	}
	}

	printf("close.\n");
	close(nfd);
	close(fd);
	return 0;
}
