/*************************************************************************
  > File Name: afterlog.h
  > Author:
  > Mail:  
  > Created Time: 2018年10月25日 星期四 10时21分43秒
************************************************************************/

#ifndef _AFTERLOG_H
#define _AFTERLOG_H

#include "common.h"


void read_modify(int efd,int tfd);

void send_user(int efd,int tfd,USE *head);

void send_nfd(int tfd,USE *head);

MES  send_mestouser(int efd,int tfd);

void sendto_user(MES mes);


void pth_recvcli(int efd,int tfd);

void *pthread_task(void *argv);


void pth_recvheart(int efd,int tfd,USE *head);
void *pthread_heart(void *argv);
void recv_heart(int efd,int tfd);
void operation_head(USE **head);









#endif
