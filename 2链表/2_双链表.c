#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINT  printf

// while死循环变量
static int mIsStop = 0;

// 学号自增加
static int mId = 10001;

enum {
	ERROR   = -1,
	SUCCESS
};

// 学生信息结构体
typedef struct StudentInformation {
	int   id;       // 学号
	int   age;      // 年龄
	char  name[32]; // 姓名
	char  sex[12];  // 性别
	float score;    // 成绩
	// 指针域
	struct StudentInformation *pre;
	struct StudentInformation *next;
} STUDENTINFORMATION;

/**
 * @name: AddOneStudentInformation
 * @function: 增加学生
 **/
int AddOneStudentInformation(STUDENTINFORMATION **head) {
	STUDENTINFORMATION *pnew  = NULL;
	STUDENTINFORMATION *plast = NULL;
	while(!mIsStop) {
		pnew = (STUDENTINFORMATION *)malloc(sizeof(STUDENTINFORMATION));
		if(NULL == pnew) {
			perror("malloc pnew error");
			return ERROR;
		}
		PRINT("请输入姓名:");
		scanf("%s", pnew->name);
		getchar();
		PRINT("请输入年龄:");
		scanf("%d", &pnew->age);
		getchar();
		PRINT("请输入性别:");
		scanf("%s", pnew->sex);
		getchar();
		PRINT("请输入成绩:");
		scanf("%f", &pnew->score);
		getchar();
		pnew->id = mId;
		mId ++;
		pnew->pre  = NULL;
		pnew->next = NULL;
		

		if(NULL == *head) {
			*head = pnew;
		}
		else {
			pnew->next = plast;
			plast->pre = pnew;
		}
		plast = pnew;

		char sel[6];
		PRINT("是否继续添加?(yes/no)\n");
		scanf("%s", sel);
		getchar();
		if(0 == strcmp(sel, "NO") || 0 == strcmp(sel, "no") || 0 == strcmp(sel, "No")) {
			break;
		}
	}

	return SUCCESS;
}

/**
 * 打印链表
 */ 
int ShowStudentLinkTable(STUDENTINFORMATION *head) {
	if(NULL == head) {
		PRINT("链表为空, 无法打印\n");
		return ERROR;
	}
	STUDENTINFORMATION *p = head;
	printf("学号\t姓名\t性别\t年龄\t成绩\n");
	while(p) {
		printf("%d\t%s\t%s\t%d\t%.2f\n", p->id, p->name, p->sex, p->age, p->score);
		p = p->next;
	}

	return SUCCESS;
}


int main(int argc, char *argv[]) {
	STUDENTINFORMATION *head = NULL;
	if(SUCCESS != AddOneStudentInformation(&head)) {
		perror("添加失败 !!!");
		return -1;
	}
	ShowStudentLinkTable(head);

	return 0;
}
