/*************************************************************************
  > File Name: sec.h
  > Author:
  > Mail:  
  > Created Time: 2018年10月31日 星期三 09时24分54秒
************************************************************************/

#ifndef _SEC_H
#define _SEC_H
#include "common.h"

int efd;

int epoll_creat(int fd);
void sec_read(int fd,int efd);
USE * login_fuc(int efd,int tfd,REG regg[],int len,int nfd,USE *head);
REG  regist_fuc(int efd,int tfd);
int  com_regist(int fd,REG reg,REG regg[],int len);
void print_regist(REG regg[],int len);
int writelog_tocli(int flag,int fd);
void writereg_tocli(int flag,int fd);
void creat_user(LOG log,int nfd,USE **head);
void del_downuser(int nfd,USE **head);
void daily_record(LOG log,int flag);






#endif
