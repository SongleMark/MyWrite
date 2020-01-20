/*************************************************************************
  > File Name: cli.h
  > Author:
  > Mail:  
  > Created Time: 2018年10月31日 星期三 09时21分52秒
************************************************************************/

#ifndef _CLI_H
#define _CLI_H
#include "common.h"

void ip_port(int *port,char ip[]);
void menu();
void cli_write(int fd,int port,char ip[]);
LOG  cli_login(int fd,LOG log);
void cli_register(int fd,int port,char ip[]);
REG  creat_regist(int port,char ip[]);
void clilog_read(int fd,LOG logg);
void clireg_read(int fd);
void after_login(int fd,LOG log);
void get_onuser(int fd);
USE *read_onuser(int fd);
void modify_pasd(int fd,LOG log);
void print_online(USE *head);
void send_message(int fd,USE *head,LOG log);
void writemes_sec(int fd,MES mes);
void recv_message(int fd);

int pthread_message(int fd,USE *head,LOG log);
void *pthread_task(void *argv);
void send_messagee(int fd,LOG log);


void send_hearttosec(int fd); //心跳










#endif
