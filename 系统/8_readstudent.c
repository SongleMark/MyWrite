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



struct student*  read_data()
{
      int fd,ret;
	  struct student *head=NULL,*pnew=NULL;
	  fd = open("student",O_RDONLY);
	  if(fd<0)
	  {
			  perror("open");
	  }

	  while(1)
	  {
             pnew = (struct student*)malloc(sizeof(struct student));
			 if(pnew==NULL)
			 {
					 printf("malloc error! %s,%d\n",__FILE__,__LINE__);
					 return head;
			 }
			 ret=read(fd,pnew,sizeof(struct student));
			 if(ret == 0)
					 break;

			 pnew->next = head;
			 head = pnew;
	  }
	  close(fd);
	  free(pnew);
	  return head;
}



void  print_list(struct student *head)
{
		if(head==NULL)
		{
				printf("空链表！\n");
		        return;
		}

		struct student *p=head;
		while(p!=NULL)
		{
				printf("%d\t%s\t%.2lf\n",p->num,p->name,p->score);
				p = p->next;
		}
}



int main()
{
		struct student  *head=NULL;
		head=read_data();
		print_list(head);
		return 0;
}
