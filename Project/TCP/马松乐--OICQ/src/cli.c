/*************************************************************************
  > File Name: cli.c
  > Author:
  > Mail:  
  > Created Time: 2018年10月23日 星期二 14时48分11秒
************************************************************************/
#include "../inc/common.h"
#include "../inc/socket.h"
#include "../inc/cli.h"
#define CMP_PAS if(strcmp(log.name,"用户名正确")==0&&strcmp(log.password,"密码正确")==0)
pthread_mutex_t mutex ;
USE *head = NULL;
int flag;


//客户端主函数
int main()
{
    int fd,ret;
    char ip[32];
    int port;
    struct sockaddr_in saddr;

    signal(SIGPIPE,hangle);

    ip_port(&port,ip);

    fd = socket_cli(port,ip);
    if(fd<0)
    {
        perror("socket");
        return -1;
    }

    cli_write(fd,port,ip);

    return 0;
}

//端口以及ip地址初始化函数
void ip_port(int *port,char ip[])
{
    /*char buf[128];
    char ch;*/
    *port = 8000;
    strcpy(ip,"127.0.0.1");
    /*FILE *fp = NULL;
    fp = fopen("ip_port.conf","r");
    if(fp == NULL)
    {
        perror("fopen");
        return ;
    }

    fprintf(fp,"%s\n%c%c%c%c%c%d\n%c%c%c\n%c%c%c%s",buf,&ch,&ch,&ch,&ch,&ch,*port,&ch,&ch,&ch,&ch,&ch,&ch,ip);
    int len = strlen(ip);
    ip[len] = '\0';*/
}

//界面函数
void menu()
{
    sleep(1);
    system("clear");
    printf("\t\t\t$$$$$$$\n");
    printf("\t\t\t1.登录\n");
    printf("\t\t\t2.注册\n");
    printf("\t\t\t3.退出\n");
    printf("请输入你的选择:");
}

//客户端发送数据函数
void cli_write(int fd,int port,char ip[])
{
    int select;
    int count = 0;
    LOG log;
loop:     menu();

    //send_hearttosec(fd);
loop1:    scanf("%d",&select);
    getchar();
    system("clear");

    switch(select)
    {
        case 1:
            log = cli_login(fd,log);
            clilog_read(fd,log);
            goto loop;
        case 2:
            cli_register(fd,port,ip);
            clireg_read(fd);
            goto loop;
        case 3:
            break;
        default:
            count ++;
            if(count >=3)
            {
                break;
            }
            printf("请输入1-3之间的数!!!\n");
            goto loop1;
    }

}

//进行登录操作时操作函数
LOG cli_login(int fd,LOG log)
{
    int ret;

    printf("请输入帐号:");
    scanf("%s",log.name);
    getchar();
    printf("请输入密码:");
    scanf("%s",log.password);
    getchar();
    system("clear");

    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(LOG));
    if(p == NULL)
    {
        perror("malloc error");
        close(fd);
    }

    p->type = 1;
    p->len = sizeof(LOG);

    memcpy(p->data,&log,sizeof(LOG));
    ret = write(fd,p,sizeof(PAK)+sizeof(LOG));
    if(ret<0)
    {
        perror("write1");
        close(fd);
    }
    
    p->type = 0;
    ret = write(fd,p,sizeof(PAK));
    if(ret<0)
    {
        perror("write2");
        close(fd);
    }
    return log;
}

//客户端从服务器获取登录成功与否信息
void clilog_read(int fd,LOG logg)
{
    int ret;
    LOG log;
    PAK *p = (PAK *)malloc(sizeof(PAK));
    if(p == NULL)
    {
        perror("malloc");
        close(fd);
        return ;
    }
    while(1)
    {
        ret = read(fd,p,sizeof(PAK));
        if(ret<0)
        {
            perror("read");
            close(fd);
            return ;
        }
        if(p->type == 0)
        {
            break;
        }
        else if(p->type == 1)
        {
            ret = read(fd,&log,sizeof(LOG));
            if(ret<0)
            {
                perror("read");
                close(fd);
                return ;
            }
        }
    }
    printf("\t\t\t%s%s\n",log.name,log.password);

    CMP_PAS
    {
        after_login(fd,logg);
    }
    else
    {
        printf("\t\t\t请输入正确且不重复帐号重新登陆\n");
        return ;
    }
}

//客户端注册时操作函数
void cli_register(int fd,int port,char ip[])
{
    REG reg;;
    PAK *p = NULL;
    int ret;

    reg = creat_regist(port,ip);
    p = (PAK *)malloc(sizeof(PAK)+sizeof(REG));
    if(p == NULL)
    {
        perror("malloc error");
        close(fd);
        return ;
    }

    p->type = 2;
    p->len = sizeof(REG);
    
    memcpy(p->data,&reg,sizeof(REG));
    ret = write(fd,p,sizeof(PAK)+sizeof(REG));
    if(ret<0)
    {
        perror("write");
        close(fd);
        return ;
    }
    
    p->type = 0;
    ret = write(fd,p,sizeof(PAK));
    if(ret<0)
    {
        perror("write");
        close(fd);
        return;
    }
}

//客户端获取注册成功与否的信息
void clireg_read(int fd)
{
    LOG log;
    int ret;

    PAK *p = (PAK *)malloc(sizeof(PAK));
    if(p == NULL)
    {
        perror("malloc");
        close(fd);
        return ;
    }

    while(1)
    {
        ret = read(fd,p,sizeof(PAK));
        if(ret < 0)
        {
            perror("read");
            close(fd);
            return ;
        }

        if(p->type == 0)
        {
            break;
        }
        else if(p->type == 2)
        {
            ret = read(fd,&log,sizeof(LOG));
            if(ret < 0)
            {
                perror("read");
                close(fd);
                return ;
            }
        }
    }
    printf("\t\t\t%s%s\n",log.name,log.password);

}

//注册界面函数
REG creat_regist(int port,char ip[])
{
    REG reg;
    printf("请输入帐号:");
    scanf("%s",reg.name);
    getchar();
    printf("请输入密码:");
    scanf("%s",reg.password);
    getchar();

    reg.port = port;
    strcpy(reg.ip,ip);
    return reg;
}

//登录之后的操作
void after_login(int fd,LOG log)
{
    int select;
    int count = 0;
loop:    printf("\t\t\t1.获取当前在线用户\n");
         printf("\t\t\t2.发送信息\n");
         printf("\t\t\t3.接受消息\n");
         printf("\t\t\t4.修改密码\n");
         printf("\t\t\t0.返回上一级\n");
         printf("请输入你的选择:");
loop1:   scanf("%d",&select);
         getchar();

    switch(select)
    {
        case 0:
            break;
        case 1:
            get_onuser(fd);
            head = read_onuser(fd);
            goto loop;
        case 2:
            //send_messagee(fd,log);
            send_message(fd,head,log);
            //pthread_message(fd,head,log);
            goto loop;
        case 3:
            recv_message(fd);
            goto loop;
        case 4:
            modify_pasd(fd,log);
            goto loop;
        default:
            count++;
            if(count>=3)
            {
                printf("错误次数过多,自动退出!!!\n");
                break;
            }
            printf("请输入1-3之间的数:");
            goto loop1;
    }
}

//获取当前在线用户
void get_onuser(int fd)
{
    int i=0;
    int ret;

    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(int));
    if(p==NULL)
    {
        perror("malloc");
        close(fd);
        return;
    }

    p->type = 4;
    p->len = sizeof(int);
    memcpy(p->data,&i,sizeof(int));

    ret = write(fd,p,sizeof(PAK)+sizeof(int));
    if(ret<0)
    {
        perror("write i");
        close(fd);
        return ;
    }
    p->type = 0;
    ret = write(fd,p,sizeof(PAK));
    if(ret<0)
    {
        perror("write error");
        close(fd);
        return ;
    }

}

//获取在线用户链表
USE *read_onuser(int fd)
{
    int ret;
    USE *head = NULL,*pnew = NULL,*last = NULL;

    PAK *p = (PAK *)malloc(sizeof(PAK));
    if(p == NULL)
    {
        perror("malloc");
        close(fd);
        return NULL;
    }

    while(1)
    {
        ret = read(fd,p,sizeof(PAK));
        if(ret<0)
        {
            perror("read");
            close(fd);
            return NULL;
        }

        if(p->type == 0)
        {
            break;
        }
        else if(p->type == 3)
        {
            pnew = (USE *)malloc(sizeof(USE));
            if(pnew == NULL)
            {
                perror("malloc");
                close(fd);
            }

            ret = read(fd,pnew,sizeof(USE));

            if(ret<0)
            {
                perror("read");
                close(fd);
                return NULL;
            }
            pnew->next = head;
            head = pnew;
            
        }
    }

    print_online(head);

    return head;
}

//线程发信息
int pthread_message(int fd,USE *head,LOG log)
{
    pthread_t ph_t;

    int *p = NULL;
    p=(int *)malloc(sizeof(int));
    if(p == NULL)
    {
        perror("malloc");
    }

    *p = fd;

    pthread_mutex_init(&mutex,NULL);
    pthread_create(&ph_t,NULL,pthread_task,(void *)p);
    pthread_mutex_lock(&mutex);
    
    send_message(fd,head,log);

    pthread_mutex_unlock(&mutex);
    //sleep(4);

}

//线程收信息
void *pthread_task(void *argv)
{
    int fd;

    fd = *(int *)argv;
    free(argv);

    pthread_mutex_lock(&mutex);
    
    recv_message(fd);

    pthread_mutex_unlock(&mutex);

    //sleep(4);

}


//发送信息
void send_message(int fd,USE *head,LOG log)
{
    int sel;
    int count = 0;
    MES mes;
    USE *p = NULL,*f = NULL;

    if(head == NULL)
    {
        printf("当前无其他用户在线,无法发送信息\n");
        return ;
    }

    printf("请选择发送信息的标记:");
loop:    scanf("%d",&sel);
         getchar();
    USE *pf = head;
    while(pf)
    {
        if(pf->nfd==sel)
        {
            break;
        }
        pf = pf->next;
    }
    if(pf == NULL)
    {
        count++;
        if(count>=3)
        {
            printf("输入错误次数过多,已退出!!!\n");
            return ;
        }
        printf("输入错误,重新输入:");
        goto loop;
    }

    printf("请输入发送消息的内容:");
    scanf("%s",mes.msg);
    getchar();
    mes.nfd = sel;
    mes.fd = fd;
    strcpy(mes.name,log.name);
    //printf("姓名:%s nfd:%d 内容:%s fd:%d\n",mes.name,mes.nfd,mes.msg,mes.fd);
    writemes_sec(fd,mes);
}

//发送消息给服务器
void writemes_sec(int fd,MES mes)
{
    int ret;
    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(MES));
    if(p == NULL)
    {
        perror("malloc");
        close(fd);
    }

    p->type = 5;
    p->len = sizeof(MES);
    memcpy(p->data,&mes,sizeof(MES));

    ret = write(fd,p,sizeof(PAK)+sizeof(MES));
    if(ret<0)
    {
        perror("write");
        close(fd);
    }

    p->type = 0;
    ret = write(fd,p,sizeof(PAK));
    if(ret<0)
    {
        perror("write");
        close(fd);
    }
}

//客户端接受另一个客户端信息
void recv_message(int fd)
{
    char ch;
    int ret;
    MES mes;
    PAK *p = (PAK *)malloc(sizeof(PAK));
    if(p == NULL)
    {
        perror("malloc");
        close(fd);
    }
    while(1)
    {
        ret = read(fd,p,sizeof(PAK));
        if(p == NULL)
        {
            printf("当前无用户给你发消息!!!\n");
            return ;
        }
        if(ret<0)
        {
            perror("read");
        }
        if(p->type == 0)
        {
            break;
        }
        else if(p->type == 5)
        {
            ret = read(fd,&mes,sizeof(MES));
            if(ret<0)
            {
                perror("write");
            }
        }

    }
    if(strlen(mes.msg) == 0)
    {
        printf("当前无用户给你发消息!!!\n");
        return ;
    }
    printf("姓名%s,nfd(标记)为%d的用户对你发了如下消息:\n",mes.name,mes.fd);
    printf(">>>%s<<<\n",mes.msg);
}

//登录用户修改自身密码
void modify_pasd(int fd,LOG log)
{
    char buf[32];
    int ret;
    char ch;

    printf("请输入你修改的密码:");
    scanf("%s",buf);
    getchar();
    strcpy(log.password,buf);
    printf("是否保存修改?(y/n):");
    scanf("%c",&ch);
    getchar();
    if(ch=='y' || ch=='Y')
    {

        PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(LOG));
        if(p == NULL)
        {
            perror("malloc");
            close(fd);
            return ;
        }

        p->type = 3;
        p->len = sizeof(LOG);
        memcpy(p->data,&log,sizeof(LOG));

        ret = write(fd,p,sizeof(PAK)+sizeof(LOG));
        if(ret<0)
        {
            perror("write");
            close(fd);
            return ;
        }

        p->type = 0;
        ret = write(fd,p,sizeof(PAK));
        if(ret<0)
        {
            perror("write");
            close(fd);
            return ;
        }
    }
    else
    {
        return;
    }
}

//打印在线用户
void print_online(USE *head)
{
    if(head == NULL)
    {
        printf("当前无其他用户在线!!!\n");
        return ;
    }
    printf("当前在线的用户有:\n");
    while(head)
    {
        printf("标记(nfd):%d 帐号:%s\n",head->nfd,head->name);
        head = head->next;
    }
}


//发送心跳包
void send_hearttosec(int fd)
{
    int num = 2;
    int ret;
    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(int));
    if(p == NULL)
    {
        perror("malloc");
    }

    p->type = 6;
    p->len = sizeof(int);
    memcpy(p->data,&num,sizeof(int));

    ret = write(fd,p,sizeof(PAK)+sizeof(int));
    if(ret<0)
    {
        printf("write error");
        close(fd);
    }
    p->type = 0;
    ret = write(fd,p,sizeof(PAK));
    if(ret<0)
    {
        perror("write");
        close(fd);
    }

}
