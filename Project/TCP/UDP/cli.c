#include "common.h"


int main()
{
	int fd;
	struct sockaddr_in saddr;
	int ret;

printf("socket ..\n");
	fd = socket(AF_INET,SOCK_DGRAM,0);
	if(fd<0)
	{
		perror("ERROR:socket");
		return -1;
	}

	saddr.sin_family = AF_INET;
	saddr.sin_port   = htons(8000);
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ret = sendto(fd,"hello",6,0,(struct sockaddr*)&saddr,sizeof(saddr));
	if(ret<0)
	{
		perror("sendto error.");
	}
	else
	{
		printf("sendto success.\n");
	}
			
	close(fd);
}
