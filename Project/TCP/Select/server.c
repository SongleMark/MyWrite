#include "common.h"

void fun(int sig)
{
	printf("recv sig:%d\n",sig);
	return;
}

#if 0
int  cli_recv(int fd)
{
	char buf[1024];
	int ret;

	while(1)
	{
		printf("read.\n");
		ret = read(fd,buf,1024);
		if(ret<0)
		{
			perror("ERROR:read");
			close(fd);
			return -1;
		}
		else if(ret == 0)
		{
			printf("TCP broken.\n");
			close(fd);
			return -1;
		}
		else
		{
			printf("read buf:%s\n",buf);
		}
	}
	return 0;

}
#endif

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

struct cli_node
{
	int fd;
	struct sockaddr_in caddr;
	struct cli_node *next;
};

typedef struct client
{
	int fd;
	int count;
	struct client *next;
}Client;

int count = 0;
Client *chead = NULL,*cp = NULL;

void sendAllToClient(Client *head, int fd)
{
	Client *p = head;
	while(p)
	{
		int ret = write(fd, p, sizeof(Client));
		if(ret < 0)
		{
			perror("write headerror");
			return ;
		}
		else
		{
			printf("write success\n");
		}

		p = p->next;
	}

	Client *s = head;
	printf("fd \t count\n");
	while(s)
	{
		printf("%d \t %d\n", s->fd, s->count);
		s = s->next;
	}

}

int main()
{
	int fd,nfd,maxfd,tfd;
	struct sockaddr_in saddr,caddr;
	int ret;
	int addr_len;
	char buf[1024];
	pid_t pid;
	fd_set rset,set;
	struct cli_node *head = NULL;
	struct cli_node *p;

	signal(SIGPIPE,fun);

	fd = sock_init(8000);
	if(fd<0)
	{
		printf("sock init error.\n");
		return -1;
	}

	FD_ZERO(&set);
	FD_SET(fd,&set);

	maxfd = fd;

	while(1)
	{
		rset = set;
		printf("select..\n");
		ret = select(maxfd+1,&rset,NULL,NULL,NULL);
		printf("select ret = %d\n",ret);
		if(ret<0)
		{
			perror("select..\n");
		}
		if(FD_ISSET(fd,&rset))
		{
			printf("accept.\n");
			addr_len = sizeof(caddr);
			nfd = accept(fd,(struct sockaddr *)&caddr,&addr_len);
			count ++;
			cp = (Client *)malloc(sizeof(Client));
			cp->fd = nfd;
			cp->count = count;
			cp->next = chead;
			chead = cp;
			
			printf("nfd = %d\n",nfd);
			FD_SET(nfd,&set);
			if(maxfd<nfd)
				maxfd = nfd;


			p = malloc(sizeof(struct cli_node));
			p->fd = nfd;
			p->caddr = caddr;

			p->next = head;
			head = p;
		}

		for(p=head;p!=NULL;p=p->next)
		{
			tfd = p->fd;
			if(!FD_ISSET(tfd,&rset))
			{
				printf("continue to p = p->next\n");
				continue;
			}
			ret = read(tfd,buf,1024);
			printf("标记--fd = %d\n",tfd);
			if(ret <0)
			{
				perror("read error");
				return -1;
			}
			else if(ret == 0)
			{
				perror("TCP broken");
				close(tfd);
				FD_CLR(tfd, &set);
			}
			else
			{
				printf("read buf:%s\n",buf);
				sendAllToClient(chead, tfd);
			}
		}

	}

	printf("close.\n");
	close(fd);
	return 0;
}
