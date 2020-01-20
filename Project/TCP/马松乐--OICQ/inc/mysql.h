/*************************************************************************
  > File Name: mysql.h
  > Author:
  > Mail:  
  > Created Time: 2018年10月24日 星期三 16时49分49秒
************************************************************************/

#ifndef _MYSQL_H
#define _MYSQL_H
#include "common.h"

int write_mysql(REG reg);

int mysql_init_connect(MYSQL *mysql);

void writeto_mysql(MYSQL *mysql,REG reg);

int read_mysql(REG reg[]);

int mysql_operation(MYSQL *mysql,const char *sql,MYSQL_RES **result);

void modify_mysql(LOG log);












#endif
