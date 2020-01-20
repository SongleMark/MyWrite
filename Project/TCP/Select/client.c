#include "common.h"

void fun(int sig)
{
	printf("recv sig:%d\n",sig);
	return;
}

typedef struct client
{
	int fd;
	int count;
	struct client *next;
}Client;

Client *readFromServer(int fd)
{
	Client *head = NULL;
	Client *p = NULL;

	while(1)
	{
		p = (Client *)malloc(sizeof(Client));
		int ret = read(fd, p, sizeof(Client));
		if(ret < 0)
		{
			perror("read error");
			return head;
		}
		else if(ret == 0)
		{
			break;
		}
		else
		{
			p->next = head;
			head = p;
		}
	}

	Client *s = head;
	printf("fd \t count\n");
	while(s)
	{
		printf("%d \t %d\n", s->fd, s->count);
		s = s->next;
	}
	return head;

}

int main()
{
	int fd;
	struct sockaddr_in saddr;
	int ret;
	char buf[1024];
	Client *head = NULL;

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
	while(1)
	{
		printf("Input:\n");
		scanf("%s",buf);
		ret = write(fd,buf,strlen(buf)+1 );
		if(ret<0)
		{
			perror("ERROR:write");
		}
		else
		{
			printf("send data success.\n");
			//head = readFromServer(fd);
		}
	}
	printf("close...\n");
	close(fd);
}
