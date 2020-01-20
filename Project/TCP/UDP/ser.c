#include "common.h"


int main()
{
	int fd,nfd;
	struct sockaddr_in saddr,caddr;
	int ret;
	int addr_len;
	char buf[1024];

printf("socket ..\n");
	fd = socket(AF_INET,SOCK_DGRAM,0);
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
printf("recvfrom..\n");
	addr_len = sizeof(caddr);
	ret =recvfrom(fd,buf,1024,0,(struct sockaddr*)&caddr,&addr_len);

	if(ret<0)
	{
		perror("recv from error.\n");
	}
	else
	{
		printf("success buf:%s\n",buf);
	}


	close(fd);
	return 0;
}
