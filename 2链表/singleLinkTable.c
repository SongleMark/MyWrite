#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//组成学生链表的节点
typedef struct Student
{
	int id;              /*学号        */
	char name[32];       /*姓名        */
	char major[32];      /*专业        */
	float score;         /*成绩        */
	struct Student *next;/*指向下一节点*/
}StuInfo;

enum
{
	EXIT,
	ADDSTU,
	DELSTU,
	MODSTU,
	SHOWSTU,
	QUERY,
	DESTORY,
	REVERSE
};

enum
{
	RETURN,
	QUERYID,
	QUERYNAME
};

enum
{
	MODIFYNAME = 1,
	MODIFYSCORE,
	MODIFYMAJOR
};

int num = 10001; //用于学号自赠

void AddStudent(StuInfo **head); //添加学生            
void ShowStudent(StuInfo *head);//打印整条学生链表
void MainMenu();//主界面
void KeepScreen();//保留屏幕函数
StuInfo *DelStudent(StuInfo *head);//根据学号删除一个链表节点
void DestroyLinkTable(StuInfo **head); //摧毁整条链表
//[查找学生信息]
void QueryStudentFromLinkTable(StuInfo *head);
void QueryStuById(StuInfo *head);
void QueryStuByName(StuInfo *head);
//[修改学生信息]
void ModifyStudentInfo(StuInfo **head);
void ModifyStuByName(StuInfo *p);
void ModifyStuByScore(StuInfo *p);
void ModifyStuByMajor(StuInfo *p);
//反转
StuInfo *ReverseLinkNode(StuInfo **head);

int main(int argc, char *argv[])
{
	int sel;
	int IsStop = 0;
	StuInfo *head = NULL;

	while(!IsStop)
	{
		MainMenu();
		scanf("%d", &sel);
		getchar();
		switch(sel)
		{
			case ADDSTU://增加一个学生
				AddStudent(&head);
				break;
			case DELSTU://删除一个学生
				head = DelStudent(head);
				break;
			case MODSTU://修改学生信息
				ModifyStudentInfo(&head);
				break;
			case SHOWSTU://打印学生信息
				ShowStudent(head);
				break;
			case QUERY://查找学生
				QueryStudentFromLinkTable(head);
				break;
			case DESTORY:
				DestroyLinkTable(&head);
				break;
			case REVERSE:
				head = ReverseLinkNode(&head);
				break;
			default:
			case EXIT://退出
				IsStop = 1;
				system("clear");
				exit(0);
		}
	}

	return 0;
}

/**************************************
 *创建学生链表
 *尾插法
 *************************************/
void AddStudent(StuInfo **head)
{
	StuInfo *pnew = NULL;
	StuInfo *plast ;
	char sel[] = "yes";
	int IsRuning = 1;
	while(IsRuning)
	{
		pnew = (StuInfo *)malloc(sizeof(StuInfo));
		if(!pnew)
		{
			perror("malloc pnew: ");
			printf("malloc pnew failed ...\n");
			return ;
		}

		printf("请输入姓名:");
		scanf("%s", pnew->name);
		getchar();
		printf("请输入专业:");
		scanf("%s", pnew->major);
		getchar();
		printf("请输入成绩:");
		scanf("%f", &pnew->score);
		getchar();
		pnew->id = num;
		pnew->next = NULL;
		num ++;

		//尾查法创建
		if(NULL == *head)
		{
			*head = pnew;
		}
		else
		{
			plast = *head;
			while( plast->next != NULL)
			{
				plast = plast->next;
			}
			plast->next = pnew;
		}

		printf("是否继续添加学生信息?(yes/no):\n");
		scanf("%s", sel);
		getchar();
		if(strcmp(sel, "no") == 0 || strcmp(sel, "NO") == 0)
		{
			system("clear");
			printf("\t\t\t\n\n添加成功...\n");
			break;
		}
	}

}

/***********************************************
 *根据学号删除一个学生
 * *********************************************/
StuInfo *DelStudent(StuInfo *head)
{
	if(NULL == head)
	{
		printf("当前没有存入学生无法删除!!!\n");
		KeepScreen();
		return head;
	}

	int id;
	char ch[8];
	StuInfo *p = head;
	StuInfo *pre = head;//用于保存要删除节点的前一个节点
	ShowStudent(head); //先打印一下整个链表方便从中查找
	printf("请输入要删除的学号:");
	scanf("%d", &id);
	getchar();

	//先找到要删除的节点
	while(NULL != p)
	{
		if(id == p->id)
		{
			break;
		}
		p = p->next;
	}
	if(NULL == p)//当p==NULL时说明根据学号查找节点时没找到
	{
		printf("输入的学号不存在!!!\n");
		KeepScreen();
		return head;
	}
	printf("是否确认删除?(yes/no): ");
	scanf("%s", ch);
	getchar();
	if(0 == strcmp(ch, "yes") || 0 == strcmp(ch, "YES"))
	{
		if(head == p)//如果要删除的节点是链表的第一个节点
		{
			head = head->next;
		}
		else//如果要删除的节点在链表中间或尾部
		{
			pre = head;
			while(pre->next != p)
			{
				pre = pre->next;
			}
			pre->next = p->next;
			free(p);
		}
		printf("删除学号为%d的学生成功...\n", id);
		KeepScreen();
	}
	else
	{
		printf("没有进行删除...\n");
		KeepScreen();
	}

	return head;
}

/**********************************************
 *打印一条学生链表信息
 *需传入头指针
 * ********************************************/
void ShowStudent(StuInfo *head)
{
	if(NULL ==head)
	{
		printf("当前没有存入学生 ...\n");
		KeepScreen();
		return ;
	}

	StuInfo *p = head;
	printf("\t\t\t学号\t姓名\t成绩\t专业\n");
	while(p)
	{
		printf("\t\t\t%d\t%s\t%.2f\t%s\n", p->id, p->name, p->score, p->major);
		p = p->next;
	}
	KeepScreen();
}

/*************************************************
 *打印主页面选项信息
 * ***********************************************/
void MainMenu()
{
	system("clear");
	printf("\t\t\t**************************\n");
	printf("\t\t\t*       单链表操作       *\n");
	printf("\t\t\t**************************\n\n");
	printf("\t\t\t*       请输入选项:      *\n");
	printf("\t\t\t*     1.添加学生信息     *\n");
	printf("\t\t\t*     2.删除学生信息     *\n");
	printf("\t\t\t*     3.修改学生信息     *\n");
	printf("\t\t\t*     4.打印学生信息     *\n");
	printf("\t\t\t*     5.查找学生信息     *\n");
	printf("\t\t\t*     6.摧毁整条链表     *\n");
	printf("\t\t\t*     7.反转整条链表     *\n");
	printf("\t\t\t*     0.退出             *\n");
	printf("\t\t\t**************************\n\n");
}

/**************************************************
 *保留屏幕函数
 * ************************************************/
void KeepScreen()
{
	printf("\nplease input any to press ... ");
	getchar();
}

/**************************************************
 *摧毁整个链表
 * ************************************************/
void DestroyLinkTable(StuInfo **head)
{
	if(NULL == *head)
	{
		printf("当前没有存入学生...\n");
		KeepScreen();
		return ;
	}

	StuInfo *p = *head;
	while(NULL != *head)
	{
		p = *head;
		*head = (*head)->next;
		free(p);
	}
	printf("摧毁成功...\n");
	KeepScreen();

}

/**************************************************
 *根据学号/姓名查找学生节点
 * ************************************************/
void QueryStudentFromLinkTable(StuInfo *head)
{
	if(NULL == head)
	{
		printf("当前没有学生...\n");
		KeepScreen();
		return ;
	}

	int select;
	int IsStop = 0;

	while(!IsStop)
	{
		system("clear");
		printf("\t\t\t*************************\n");
		printf("\t\t\t*     请输入选项:       *\n");
		printf("\t\t\t*    1.根据学号查找     *\n");
		printf("\t\t\t*    2.根据姓名查找     *\n");
		printf("\t\t\t*    0.返回上一级       *\n");
		printf("\t\t\t*************************\n");
		scanf("%d", &select);
		getchar();

		switch(select)
		{
			case QUERYID:
				QueryStuById(head);
				break;
			case QUERYNAME:
				QueryStuByName(head);
				break;
			case RETURN:
			default:
				IsStop = 1;
				break;
		}
	}
}

/***********************************************
 *根据学号查找
 * *********************************************/
void QueryStuById(StuInfo *head)
{
	if(NULL == head)
	{
		return ;
	}

	int id;
	StuInfo *p = head;
	printf("请输入要查找的ID: ");
	scanf("%d", &id);
	getchar();
	while(p)
	{
		if(id == p->id)
		{
			break;
		}
		p = p->next;
	}
	if(NULL == p)
	{
		printf("输入的ID不存在...\n");
		KeepScreen();
		return ;
	}
	printf("该学生信息如下:\n");
	printf("\t\t\t学号\t姓名\t专业\t成绩\n");
	printf("\t\t\t%d\t%s\t%s\t%f\n", p->id, p->name, p->major, p->score);
	KeepScreen();

}

/***********************************************
 *根据姓名查找
 * *********************************************/
void QueryStuByName(StuInfo *head)
{
	if(NULL == head)
	{
		return ;
	}

	char name[32];
	StuInfo *p = head;
	printf("请输入要查找的学生姓名: ");
	scanf("%s", name);
	getchar();
	while(p)
	{
		if(0 == strcmp(name, p->name))
		{
			break;
		}
		p = p->next;
	}
	if(NULL == p)
	{
		printf("输入的姓名不存在...\n");
		KeepScreen();
		return ;
	}
	printf("该学生信息如下:\n");
	printf("\t\t\t学号\t姓名\t专业\t成绩\n");
	printf("\t\t\t%d\t%s\t%s\t%f\n", p->id, p->name, p->major, p->score);
	KeepScreen();

}

/***********************************************
 *修改姓名/成绩/专业
 * *********************************************/
void ModifyStudentInfo(StuInfo **head)
{
	if(NULL == *head)
	{
		printf("当前没有学生,不可修改...\n");
		KeepScreen();
		return ;
	}

	int id;
	int select;
	int IsStop = 0;
	printf("请输入要修改学生的id:");
	scanf("%d", &id);
	getchar();

	StuInfo *p = *head;
	while(NULL != p)
	{
		if(id == p->id)
		{
			break;
		}
		p = p->next;
	}
	if(NULL == p)
	{
		printf("不存在ID为%d的学生...\n", id);
		KeepScreen();
		return ;
	}

	while(!IsStop)
	{
		system("clear");
		printf("\t\t\t*************************\n");
		printf("\t\t\t*     请输入选项:       *\n");
		printf("\t\t\t*    1.修改姓名         *\n");
		printf("\t\t\t*    2.修改成绩         *\n");
		printf("\t\t\t*    3.修改专业         *\n");
		printf("\t\t\t*    0.返回上一级       *\n");
		printf("\t\t\t*************************\n");
		scanf("%d", &select);
		getchar();

		switch(select)
		{
			case MODIFYNAME:
				ModifyStuByName(p);
				break;
			case MODIFYSCORE:
				ModifyStuByScore(p);
				break;
			case MODIFYMAJOR:
				ModifyStuByMajor(p);
				break;
			case RETURN:
			default:
				IsStop = 1;
				break;
		}
	}

}

/***********************************************
 *修改姓名
 * *********************************************/
void ModifyStuByName(StuInfo *p)
{
	printf("请输入新姓名:");
	scanf("%s", p->name);
	getchar();
	printf("修改成功...\n");
	KeepScreen();
}

/***********************************************
 *修改成绩
 * *********************************************/
void ModifyStuByScore(StuInfo *p)
{
	printf("请输入新成绩:");
	scanf("%f", &p->score);
	getchar();
	printf("修改成功...\n");
	KeepScreen();
}

/***********************************************
 *修改专业
 * *********************************************/
void ModifyStuByMajor(StuInfo *p)
{
	printf("请输入新专业:");
	scanf("%s", p->major);
	getchar();
	printf("修改成功...\n");
	KeepScreen();
}

//反转
StuInfo *ReverseLinkNode(StuInfo **head)
{
	if(NULL == *head)
	{
		printf("当前无节点存入...\n");
		KeepScreen();
		return NULL;
	}

	StuInfo *p = *head;
	StuInfo *newhead = NULL;
	while(*head)
	{	
		p = *head;
		*head = (*head)->next;
		p->next = newhead;
		newhead = p;
	}

	return newhead;
}
