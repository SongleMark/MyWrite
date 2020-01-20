/*

   定义一个表示学生的结构体，分别编写两个程序，一个程序创建一条链表，
   并将该链表的数据存入文件，另一个程序从文件中将数据读取出来，形成一条链表，
   并打印
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>




struct student
{
		int num;
		char name[32];
		double score;
		struct student *next;
};


struct student*  creat_list()
{
		struct student *head=NULL,*pnew=NULL;
		char ch;
		printf("是否创建链表?");
		scanf("%c",&ch);
		while(getchar()!='\n');
		while(ch == 'y'||ch == 'Y')
		{
				pnew = (struct student*)malloc(sizeof(struct student));
				if(pnew == NULL)
				{
						printf("malloc error! %s,%d\n",__FILE__,__LINE__);
						return head;
				}
				printf("请输入学号：");
				scanf("%d",&(pnew->num));
				while(getchar()!='\n');
				printf("请输入姓名：");
				scanf("%s",pnew->name);
				while(getchar()!='\n');
				printf("请输入成绩：");
				scanf("%lf",&pnew->score);
				while(getchar()!='\n');

				pnew->next = head;
				head = pnew;

				printf("是否继续？");
				scanf("%c",&ch);
				while(getchar()!='\n');
		}
		return head;
}


void  write_data(struct student*  head)
{
		struct student *p=head;
		int fd,ret;
		 fd = open("student",O_WRONLY|O_CREAT|O_TRUNC,0640);
		 if(fd<0)
		 {
				 perror("open");
		 }
		while(p!=NULL)
		{
				ret=write(fd,p,sizeof(struct student));
				if(ret<0)
				{
						perror("write");
				}
				p = p->next;
		}
}



int main()
{
		struct student *head=NULL;
		head=creat_list();
		write_data(head);
		return 0;
}



