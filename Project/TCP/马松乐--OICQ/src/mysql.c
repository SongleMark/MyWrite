/*************************************************************************
  > File Name: mysql.c
  > Author:
  > Mail:  
  > Created Time: 2018年10月24日 星期三 16时04分03秒
************************************************************************/

#include "../inc/common.h"
#include "../inc/mysql.h"
#define NUM 10

#define HOST "localhost"
#define USER "root"
#define PASSWD "123456"
#define DB "QICQ"

//数据库操作存入总函数
int write_mysql(REG reg)
{
    MYSQL mysql;
    mysql_init_connect(&mysql);
    writeto_mysql(&mysql,reg);
}

//数据库初始化函数
int mysql_init_connect(MYSQL *mysql)
{
    if(NULL == mysql_init(mysql))
    {
        printf("数据库初始化失败!!!\n");
        return -1;
    }

    if(NULL == mysql_real_connect(mysql,HOST,USER,PASSWD,DB,0,NULL,0))
    {
        printf("%s\n",mysql_error(mysql));
        return -1;
    }
    mysql_set_character_set(mysql,"utf8");
    return 0;
}

//将注册信息存入数据库
void writeto_mysql(MYSQL *mysql,REG reg)
{
    char sql[128];
    sprintf(sql,"insert into user values('%s','%s',%d,'%s')",reg.name,reg.password,reg.port,reg.ip);
    
    if(0!=mysql_query(mysql,sql))
    {
        printf("%s",mysql_error(mysql));
        return ;
    }
    else
    {
        printf("数据库执行成功\n");
    }
}

//将注册信息从数据库中读出
int read_mysql(REG reg[])
{
    MYSQL mysql;
    mysql_init_connect(&mysql);
    
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    int i=0;
    int num_fields = 0,num_rows = 0,index = 0;
    char sql[128];

    sprintf(sql,"select *from user");
    mysql_operation(&mysql,sql,&result);
    num_fields = mysql_num_fields(result);
    num_rows = mysql_num_rows(result);

    while((row = mysql_fetch_row(result))!=NULL)
    {
        for(i=0;i<num_fields;i++)
        {
            if(i==0)
            {
                strcpy(reg[index].name,row[i]);
            }
            else if(i==1)
            {
                strcpy(reg[index].password,row[i]);
            }
            else if(i==2)
            {
                reg[index].port = atoi(row[i]);
            }
            else if(i==3)
            {
                strcpy(reg[index].ip,row[i]);
            }
        }
        index++;
    }
    mysql_free_result(result);
    return num_rows;
}

int mysql_operation(MYSQL *mysql,const char *sql,MYSQL_RES **result)
{
    MYSQL_RES *res = NULL;
    if(0!=mysql_query(mysql,sql))
    {
        printf("%s",mysql_error(mysql));
        return -1;
    }

    res = mysql_store_result(mysql);
    if(result!=NULL)
    {
        *result = res;
    }
    return 0;
}

//修改密码并保存入库
void modify_mysql(LOG log)
{
    MYSQL mysql;
    char sql[128];

    mysql_init_connect(&mysql);

    sprintf(sql,"update user set password='%s' where name='%s'",log.password,log.name);
    
    if(0!=mysql_query(&mysql,sql))
    {
        printf("%s",mysql_error(&mysql));
        return ;
    }
    else
    {
        printf("数据库执行成功\n");
    }
    
}
