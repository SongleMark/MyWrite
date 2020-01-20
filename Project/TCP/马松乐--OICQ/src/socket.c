/*************************************************************************
  > File Name: socket.c
  > Author:
  > Mail:  
  > Created Time: 2018年10月23日 星期二 14时36分06秒
************************************************************************/

#include "../inc/common.h"
#include "../inc/socket.h"

//客户端socket函数
int socket_cli(int port,char ip[])
{
    int fd,ret;
    struct sockaddr_in saddr;

    fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd<0)
    {
        perror("socket");
        return -1;
    }
//printf("port:%d ip:%s\n",port,ip);   
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = inet_addr(ip);

    ret = connect(fd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret<0)
    {
        perror("connect");
        close(fd);
        return -1;
    }

    return fd;
}

//信号处理函数
void hangle(int sig)
{
    printf("signal pipe sig:%d\n ",sig);
}

//服务端socket函数
int socket_sec()
{
    int fd,ret;
    struct sockaddr_in saddr;

    fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd<0)
    {
        perror("socket");
        return -1;
    }

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8000);
    saddr.sin_addr.s_addr = INADDR_ANY;

    ret = bind(fd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret<0)
    {
        perror("bind");
        close(fd);
        return -1;
    }

    ret = listen(fd,20);
    if(ret<0)
    {
        perror("listen");
        close(fd);
        return -1;
    }

    return fd;
}
