/*************************************************************************
  > File Name: common.h
  > Author:
  > Mail:  
  > Created Time: 2018年10月23日 星期二 14时27分32秒
************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>
#include <mysql/mysql.h>
#include <pthread.h>

typedef struct pack
{
    int type;
    int len;
    char data[0];
}PAK;

typedef struct login
{
    char name[128];
    char password[128];
}LOG;

typedef struct regist
{
    char name[128];
    char password[128];
    int port;
    char ip[32];
}REG;

typedef struct user
{
    int nfd;
    char name[128];
    int count;
    struct user *next;
}USE;

typedef struct message
{
    int fd;  //自身fd
    int nfd; //发送目标的fd
    char msg[128];//发送内容
    char name[32];
}MES;

struct time
{
    int ti_hour;
    int ti_min;
    int ti_sec;
    int ti_hund;
};

#endif
