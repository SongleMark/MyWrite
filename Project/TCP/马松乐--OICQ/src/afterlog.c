/*************************************************************************
  > File Name: afterlog.c
  > Author:
  > Mail:  
  > Created Time: 2018年10月25日 星期四 10时03分25秒
************************************************************************/

#include "../inc/common.h"
#include "../inc/afterlog.h"
#include "../inc/mysql.h"
#include "../inc/sec.h"

pthread_mutex_t mutex;

//获取用户修改密码信息并保存入库
void read_modify(int efd,int tfd)
{
    LOG log;
    int ret;

    ret = read(tfd,&log,sizeof(LOG));
    if(ret<0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else if(ret == 0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else
    {
        modify_mysql(log);
    }

}

//接受用户获取在线用户信号
void send_user(int efd,int tfd,USE *head)
{
    int ret;
    int num;
    ret = read(tfd,&num,sizeof(int));
    if(ret<0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else if(ret == 0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else
    {
        send_nfd(tfd,head);
    }
}
//发送在线用户
void send_nfd(int tfd,USE *head)
{
    int ret;


    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(USE));
    if(p == NULL)
    {
        perror("malloc");
        close(tfd);
        return ;
    }

    p->type = 3;
    p->len = sizeof(USE);

    USE *pp = head;
    while(pp!=NULL)
    {
        memcpy(p->data,pp,sizeof(USE));

        ret = write(tfd,p,sizeof(PAK)+sizeof(USE));
        if(ret<0)
        {
            perror("write head");
            close(tfd);
            return ;
        }
        pp = pp->next;
    }


    PAK *p1 = malloc(sizeof(PAK));
    p1->type = 0;
    ret = write(tfd,p1,sizeof(PAK));
    if(ret<0)
    {
        perror("write p->type=0");
        close(tfd);
        return ;
    }

}

//服务器线程收客户端信息
void pth_recvcli(int efd,int tfd)
{
    pthread_t ph_t;
    MES *mes = NULL;

    pthread_mutex_init(&mutex,NULL);


    mes = (MES *)malloc(sizeof(MES));


    pthread_mutex_lock(&mutex);
    
    *mes = send_mestouser(efd,tfd);
    
    pthread_mutex_unlock(&mutex);
    pthread_create(&ph_t,NULL,pthread_task,(void *)mes);

    //sleep(4);

}

//服务器线程发信息给客户端
void *pthread_task(void *argv)
{
    MES mes;
    mes = *(MES *)argv;
    free(argv);

    pthread_mutex_lock(&mutex);

    sendto_user(mes);

    pthread_mutex_unlock(&mutex);

    //sleep(4);
}

//接受客户端发过来消息
MES  send_mestouser(int efd,int tfd)
{
    int ret;
    MES mes;

    ret = read(tfd,&mes,sizeof(MES));
    if(ret<0)
    {
        perror("read");
    }
    if(ret<0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else if(ret == 0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else
    {
        mes.fd = tfd;
        //sendto_user(mes);
        return mes;
    }
    return mes;
}

//发送信息给客户端
void sendto_user(MES mes)
{
    int ret;
    
    //printf("姓名:%s 消息:%s nfd:%d tfd:%d\n",mes.name,mes.msg,mes.nfd,mes.fd);
    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(MES));
    if(p == NULL)
    {
        perror("malloc");
        return;
    }

    p->type = 5;
    p->len = sizeof(MES);
    memcpy(p->data,&mes,sizeof(MES));

    ret = write(mes.nfd,p,sizeof(PAK)+sizeof(MES));
    if(ret<0)
    {
        perror("write mes");
        return;
    }

    p->type = 0;
    ret = write(mes.nfd,p,sizeof(PAK));
    if(ret<0)
    {
        perror("write mesg");
    }
}


//线程调用接收心跳包函数
void pth_recvheart(int efd,int tfd,USE *head)
{
    pthread_t ph_t;

    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_lock(&mutex);
    
    recv_heart(efd,tfd);

    pthread_mutex_unlock(&mutex);
    pthread_create(&ph_t,NULL,pthread_heart,(void *)head);
}

//线程处理心跳包函数对在线用户链表处理
void *pthread_heart(void *argv)
{
    USE *head = NULL;
    head = (USE *)argv;

    pthread_mutex_lock(&mutex);

    operation_head(&head);

    pthread_mutex_unlock(&mutex);

}

//服务器接受心跳包
void recv_heart(int efd,int tfd)
{
    int ret;
    int num;;

    ret = read(tfd,&num,sizeof(MES));
    if(ret<0)
    {
        perror("read");
    }
    if(ret<0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else if(ret == 0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else
    {
        printf("num = %d\n",num);
    }
}

//服务器处理发送心跳包的在线用户
void operation_head(USE **head)
{
    USE *p = *head;
    while(1)
    {
        sleep(1);
        p = *head;
        while(p)
        {
            p->count--;
            if(p->count<=0)
            {
                printf("nfd = %d\n",p->nfd);
                close(p->nfd);
                epoll_ctl(efd,EPOLL_CTL_DEL,p->nfd,NULL);

                del_downuser(p->nfd,head);
            }

            p = p->next;
        }
    }
}

