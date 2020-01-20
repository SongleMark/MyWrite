/*************************************************************************
  > File Name: socket.h
  > Author:
  > Mail:  
  > Created Time: 2018年10月23日 星期二 14时45分59秒
************************************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H
#include "./common.h"

int socket_cli(int port,char ip[]);   //客户端socket函数
void hangle(int sig);                 //信号处理
int socket_sec();                     //服务端socket函数











#endif
