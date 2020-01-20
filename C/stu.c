#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	int id;
	char name[32];
	float score;
	struct Student *next;
}Stu_Info;

Stu_Info *Create_Stu();
void Show_stuinfo(Stu_Info *head);
Stu_Info *Reserve_StuList(Stu_Info *head);
Stu_Info *DelNode(Stu_Info *head, int id);

int main(int argc,char **argv)
{
	int id;
	Stu_Info *head = NULL;
	head = Create_Stu();
	Show_stuinfo(head);
	printf("please input id: ");
	scanf("%d", &id);
	head = DelNode(head, id);
	Show_stuinfo(head);

	//Stu_Info *p = Reserve_StuList(head);
	//Show_stuinfo(p);
	return 0;
}

Stu_Info *Create_Stu()
{
	Stu_Info *head = NULL;
	Stu_Info *pnew = NULL;
	Stu_Info *last = NULL;

	while(1)
	{
		pnew = (Stu_Info *)malloc(sizeof(Stu_Info));
		if(pnew == NULL)
		{
			perror("malloc pnew");
			return head;
		}

		printf("please input your name:");
		scanf("%s",pnew->name);
		getchar();
		printf("please input your id:");
		scanf("%d",&pnew->id);
		getchar();
		printf("please inut your score:");
		scanf("%f",&pnew->score);
		getchar();
		pnew->next = NULL;

		if(head == NULL)
		{
			head = pnew;
		}
		else
		{
			last = head;
			while(last->next != NULL)
			{
				last = last->next;
			}
			last->next = pnew;
		}

		char ch;
		printf("是否继续?(y/n)");
		scanf("%c",&ch);
		getchar();

		if(ch == 'n' || ch == 'N')
		{
			break;
		}
	}

	return head;

}

void Show_stuinfo(Stu_Info *head)
{
	if(head == NULL)
	{
		printf("没有学生存入!!!\n");
		return ;
	}

	system("clear");
	printf("姓名\t学号\t成绩\n");
	Stu_Info *p = head;
	while(p)
	{
		printf("%s\t%d\t%.2f\n",p->name,p->id,p->score);
		p = p->next;
	}
}

Stu_Info *DelNode(Stu_Info *head, int id)
{
	if(NULL == head)
	{
		printf("can't delete node ...");
		return head;
	}

	Stu_Info *pdel = head;
	Stu_Info *pre = head;
	if(id == head->id)
	{
		head = head->next;
		free(head);
		return head;
	}
	else
	{
		while(pdel)
		{
			if(id == pdel->id)
			{
				break;
			}

			pdel = pdel->next;
		}

		if(pdel == NULL)
		{
			printf("please input correct id!!!\n");
			return head;
		}

		pre = head;
		while(pre->next != pdel)
		{
			pre = pre->next;
		}
		pre->next = pdel->next;
		free(pdel);
	}

	return head;
}

Stu_Info *Reserve_StuList(Stu_Info *head)
{
	Stu_Info *p = head;
	Stu_Info *newhead = NULL;
	while(head)
	{
		p = head;
		p->next = newhead;
		newhead = p;
		head = head->next;
	}

	return newhead;
}


