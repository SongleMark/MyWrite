#include "common.h"

void fun(int sig)
{
	printf("recv sig:%d\n",sig);
	return;
}

void * cli_recv(void *arg)
{
	char buf[1024];
	int ret;
	int fd;

	if(arg == NULL)
		return NULL;

	fd = *(int *)arg;

	free(arg);

	while(1)
	{
		printf("read.\n");
		ret = read(fd,buf,1024);
		if(ret<0)
		{
			perror("ERROR:read");
			close(fd);
			return NULL;
		}
		else if(ret == 0)
		{
			printf("TCP broken.\n");
			close(fd);
			return NULL;
		}
		else
		{
			printf("read buf:%s\n",buf);
		}
	}
	return NULL;

}


int sock_init(unsigned short port)
{
	int fd;
	struct sockaddr_in saddr;
	int ret;

	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		perror("ERROR:socket");
		return -1;
	}

	saddr.sin_family = AF_INET;
	saddr.sin_port   = htons(port);
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
	return fd;
}

int main()
{
	int fd,nfd;
	struct sockaddr_in saddr,caddr;
	int ret;
	int addr_len;
	char buf[1024];
	pid_t pid;
	pthread_t pth_id;
	int *pfd;

	signal(SIGPIPE,fun);

	fd = sock_init(8000);
	if(fd<0)
	{
		printf("sock init error.\n");
		return -1;
	}

	while(1)
	{
		printf("accept.\n");
		addr_len = sizeof(caddr);
		nfd = accept(fd,(struct sockaddr *)&caddr,&addr_len);
		printf("标记--nfd = %d\n",nfd);
		pfd = malloc(sizeof(int));
		*pfd = nfd;
		ret = pthread_create(&pth_id,NULL,cli_recv,(void*)pfd);

	}

	printf("close.\n");
	close(fd);
	return 0;
}
