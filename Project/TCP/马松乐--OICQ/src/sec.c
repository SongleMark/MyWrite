/*************************************************************************
  > File Name: sec.c
  > Author:
  > Mail:  
  > Created Time: 2018年10月23日 星期二 15时50分41秒
 ************************************************************************/

#include "../inc/common.h"
#include "../inc/mysql.h"
#include "../inc/socket.h"
#include "../inc/afterlog.h"
#include "../inc/sec.h"

#define CMP_ABC if(strcmp(log.name,"abc")==0 && strcmp(log.password,"abc")==0)



USE *head = NULL;
//服务端主函数
int main()
{
    int fd,ret;
    struct sockaddr_in saddr,caddr;
    struct epoll_event ev,evs[10];

    signal(SIGPIPE,hangle);
    printf("socket...\n");  
    fd = socket_sec();
    if(fd<0)
    {
        perror("socket");
        return -1;
    }
    printf("epoll...\n");
    efd = epoll_creat(fd);
    printf("epoll over...\n");
    if(efd<0)
    {
        perror("epoll_creat error");
        close(fd);
        return -1;
    }

    sec_read(fd,efd);

    return 0;
}

//epoll创建函数
int epoll_creat(int fd)
{
    int efd;

    efd = epoll_create(10);
    if(efd<0)
    {
        perror("epoll_creat error");
        close(fd);
        return -1;
    }

    return efd;
}

//服务器采用epoll读主函数
void sec_read(int fd,int efd)
{
    int tfd,nfd,ret;
    int addr_len,i=0;
    int count;
    struct sockaddr_in caddr;
    struct epoll_event ev,evs[10];
    addr_len = sizeof(caddr);
    PAK *p = NULL;
    LOG log;
    REG reg;
    int flag;
    REG regg[10];
    int len=0;
    USE *head = NULL;

    ev.events = EPOLLIN;
    ev.data.fd = fd;
    printf("ctl1...\n");
    ret = epoll_ctl(efd,EPOLL_CTL_ADD,fd,&ev);
    if(ret<0)
    {
        perror("epoll_ctl error");
        close(fd);
        return ;
    }
    while(1)
    {
        printf("wait ...\n");
        count = epoll_wait(efd,evs,10,-1);
        if(count<0)
        {
            perror("epoll_wait error");
            close(fd);
            return ;
        }

        for(i=0;i<count;i++)
        {
            tfd = evs[i].data.fd;
            if(tfd == fd)
            {
                printf("accept ...\n");
                nfd = accept(fd,(struct sockaddr*)&caddr,&addr_len);
                printf("accept over ...nfd = %d\n",nfd);            
                if(nfd<0)
                {
                    perror("accept error");
                    close(fd);
                    return ;
                }
                ev.data.fd = nfd;
                ret = epoll_ctl(efd,EPOLL_CTL_ADD,nfd,&ev);
                if(ret<0)
                {
                    perror("epoll_ctl error");
                    close(fd);
                    return ;
                }
            }
            else
            {
                p = (PAK *)malloc(sizeof(PAK));
                if(p == NULL)
                {
                    perror("malloc error");
                    close(fd);
                    return ;
                }
                printf("read1...\n");
                ret = read(tfd,p,sizeof(PAK));
                if(ret<0)
                {
                    perror("read");
                    close(fd);
                    return ;
                }
                if(ret == 0)
                {
                    del_downuser(nfd,&head);
                    epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
                    close(tfd);
                    //close(nfd);
                    //close(fd);
                }
                if(p->type == 0)
                {
                    break;
                }
                else if(p->type == 2)
                {
                    len = read_mysql(regg);
                    reg = regist_fuc(efd,tfd);
                    flag = com_regist(tfd,reg,regg,len);
                    if(flag == 1)
                    {
                        write_mysql(reg);
                    }
                    else if(flag == 2)
                    {
                        printf("不写入数据库\n");
                    }
                    len = read_mysql(regg);
                    print_regist(regg,len);
                }
                else if(p->type == 1)
                {
                    len = read_mysql(regg);
                    head = login_fuc(efd,tfd,regg,len,nfd,head);
                }
                else if(p->type == 3)
                {
                    read_modify(efd,tfd);
                }
                else if(p->type == 4)
                {
                    send_user(efd,tfd,head);
                }
                else if(p->type == 5)
                {
                    //send_mestouser(efd,tfd);
                    pth_recvcli(efd,tfd);
                }
                /*else if(p->type == 6)
                {
                    pth_recvheart(efd,tfd,head);
                }*/
            }

        }
    }
}

//服务器处理客户端登录函数
USE * login_fuc(int efd,int tfd,REG regg[],int len,int nfd,USE *head)
{
    LOG log;
    int ret;
    int flag;
    int i=0;

    printf("read2...\n");
    ret = read(tfd,&log,sizeof(LOG));
    printf("ret = %d\n",ret);
    if(ret < 0)
    {
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else if(ret == 0)
    {
        printf("pipe broken\n");
        epoll_ctl(efd,EPOLL_CTL_DEL,tfd,NULL);
        close(tfd);
    }
    else
    {
        USE *p = head;
        while(p)
        {
            if(strcmp(p->name,log.name)==0)
            {
                flag = 2;
                daily_record(log,flag);
                writelog_tocli(flag,tfd);
                return head;
            }
            p = p->next;
        }
        for(i=0;i<len;i++)
        {
            if(strcmp(log.name,regg[i].name)==0&&strcmp(log.password,regg[i].password)==0)
            {
                flag = 1;
                printf("登录成功\n");
                
                daily_record(log,flag);

                creat_user(log,nfd,&head);

                writelog_tocli(flag,tfd);
                printf("帐号:%s 密码:%s\n",log.name,log.password);
                return head;
            }
            else
            {
                continue;
            }
        }

        flag = 2;
        printf("登录失败\n");
        daily_record(log,flag);
        writelog_tocli(flag,tfd);
        printf("帐号:%s 密码:%s\n",log.name,log.password);
        
        return head;
    }
    return head;
}

//服务器反馈登录信息给客户端
int writelog_tocli(int flag,int fd)
{
    LOG log;
    int ret;

    if(flag == 1)
    {
        strcpy(log.name,"用户名正确");
        strcpy(log.password,"密码正确");
    }
    else if(flag == 2)
    {
        strcpy(log.name,"用户名或密码不正确");
        strcpy(log.password,"或重复登录");
    }
    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(LOG));
    if(p == NULL)
    {
        perror("malloc error");
        close(fd);
        return -1;
    }
    p->type = 1;
    p->len = sizeof(LOG);
    memcpy(p->data,&log,sizeof(LOG));
    ret = write(fd,p,sizeof(PAK)+sizeof(LOG));
    if(ret<0)
    {
        perror("write");
        close(fd);
        return -1;
    }
    p->type = 0;
    ret = write(fd,p,sizeof(PAK));
    if(ret<0)
    {
        perror("write");
        close(fd);
        return -1;
    }

}

//服务器将注册信息读出
REG regist_fuc(int efd,int tfd)
{
    REG reg;
    int ret;
    int i=0;

    printf("read3...\n");
    ret = read(tfd,&reg,sizeof(REG));

    if(ret < 0)
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
        return reg;
    }
    return reg;
}

//比较注册信息的对错
int com_regist(int fd,REG reg,REG regg[],int len)
{
    int flag;
    int i=0;
    for(i=0;i<len;i++)
    {
        if(strcmp(reg.name,regg[i].name)==0)
        {
            printf("注册失败\n");
            flag = 2;
            writereg_tocli(flag,fd);
            return flag;
        }
        else
        {
            continue;
        }
    }
    printf("注册成功\n");
    flag = 1;
    writereg_tocli(flag,fd);
    return flag;

}
//将注册信息反馈给客户端
void writereg_tocli(int flag,int fd)
{
    LOG log;
    int ret;

    if(flag == 1)
    {
        strcpy(log.name,"注册");
        strcpy(log.password,"成功");
    }
    else if(flag == 2)
    {
        strcpy(log.name,"注册失败,不写入数据库");
        strcpy(log.password,"请重新注册");
    }

    PAK *p = (PAK *)malloc(sizeof(PAK)+sizeof(LOG));
    if(p == NULL)
    {
        perror("malloc");
        close(fd);
        return ;
    }
    p->type = 2;
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
    if(ret < 0)
    {
        perror("write");
        close(fd);
        return ;
    }
}

//打印注册用户信息
void print_regist(REG regg[],int len)
{
    int i = 0;
    printf("注册帐号\t注册密码\t注册端口\t注册ip\n");
    for(i=0;i<len;i++)
    {
        printf("%s\t%s\t%d\t%s\n",regg[i].name,regg[i].password,regg[i].port,regg[i].ip);
    }
}

//创建在线用户链表
void creat_user(LOG log,int nfd,USE **head)
{
    USE *pnew = NULL;
    
    pnew = (USE *)malloc(sizeof(USE));
    if(pnew == NULL)
    {
        perror("malloc");
    }
    pnew->nfd = nfd;
    strcpy(pnew->name,log.name);
    pnew->count = 20;
    pnew->next = NULL;

    pnew->next = *head;
    *head = pnew;

    USE *p = *head;
    while(p)
    {
        printf("标记:%d\t姓名:%s\n",p->nfd,p->name);
        p = p->next;
    }


}

//删除下线节点
void del_downuser(int nfd,USE **head)
{
    
    USE *p = *head,*q = NULL;
    while(p->nfd!=nfd)
    {
        p = p->next;
    }   
    
    if(p == *head)
    {
        *head = (*head)->next;
        free(p);
    }
    else
    {
        q = *head;
        while(q->next!=p)
        {
            q = q->next;
        }
        q->next = p->next;
        free(p);
    }
    
}

//获取日志
void daily_record(LOG log,int flag)
{
    time_t t;
    struct tm * lt;
    time(&t);
    char buf[32];
    lt = localtime(&t);
    if(flag == 1)
    {
        strcpy(buf,"登录成功");
    }
    else if(flag == 2)
    {
        strcpy(buf,"登陆失败");
    }

    FILE *fp = NULL;
    fp = fopen("daily.txt","a");
    if(fp == NULL)
    {
        perror("fopen");
        return;
    }

    fprintf(fp,"用户:%s在%d年-%d月-%d日-%d时-%d分-%d秒%s\n",log.name,lt->tm_year+1900,lt->tm_mon,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec,buf);
    fclose(fp);
}
