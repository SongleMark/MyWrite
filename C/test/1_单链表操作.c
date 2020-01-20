#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct StudentInfo {
	int id;
	char name[32];
	double score;
	struct StudentInfo *next;
} STUDENTINFO;

static int _mIsStop = 0;
static int _mNum = 10001;

/// 创建
void CreateStudentInfoLink(STUDENTINFO **head) {
	STUDENTINFO *pnew = NULL;
	char flag[8];
	
	while(!_mIsStop) {
		pnew = (STUDENTINFO *)malloc(sizeof(STUDENTINFO));
		if(NULL == pnew) {
			perror("malloc pnew error");
			return ;
		}
		printf("请输入姓名:");
		scanf("%s", pnew->name);
		printf("请输入成绩:");
		scanf("%lf", &pnew->score);
		pnew->id = _mNum;
		_mNum ++;

		pnew->next = *head;
		*head = pnew;

		printf("是否继续?(yes/no): ");
		scanf("%s", flag);
		if(0 == strcmp("no", flag) || 0 == strcmp("NO", flag)) {
			break;
		}
	}

}

/// 打印
void ShowStudentInfo(STUDENTINFO *head) {
	if(NULL == head) {
		printf("当前没有存入学生信息 ...\n");
		return ;
	}
	STUDENTINFO *ptemp = head;
	printf("学号\t姓名\t成绩\n");
	while(ptemp) {
		printf("%d\t%s\t%.2lf\n", ptemp->id, ptemp->name, ptemp->score);
		ptemp = ptemp->next;
	}
}

/// 反转
STUDENTINFO *ReverseStudentInfoLink(STUDENTINFO *head) {
	if(NULL == head) {
		printf("当前没有存入学生信息 ...\n");
		return NULL;
	}
	STUDENTINFO *newhead = NULL;
	STUDENTINFO *ptemp = head;
	STUDENTINFO *p = NULL;
	while(ptemp) {
		p = ptemp;
		ptemp = ptemp->next;
		p->next = newhead;
		newhead = p;
	}
	
	return newhead;
}

/// 根据学号删除
void DeleteStudentInfoByID(STUDENTINFO **head, int id) {
	if(NULL == *head) {
		printf("当前没有存入学生信息 ...\n");
		return ;
	}

	/// 先找到要删除的节点并判断查找条件是否正确
	STUDENTINFO *pdel = *head;
	while(pdel) {
		if(id == pdel->id) {
			break;
		}
		pdel = pdel->next;
	}
	if(NULL == pdel) {
		printf("没有找到学号为%d的学生 ...\n", id);
		return ;
	}

	/// 删除该节点
	if(pdel == *head) {
		*head = (*head)->next;
	}
	else {
		STUDENTINFO *predel = *head;
		while(predel->next != pdel) {
			predel = predel->next;
		}
		predel->next = pdel->next;
		free(pdel);
	}
}


int main(int argc, char *argv[]) {
	STUDENTINFO *head = NULL;
	CreateStudentInfoLink(&head);
	ShowStudentInfo(head);
	//head = ReverseStudentInfoLink(head);
	//ShowStudentInfo(head);
	int id;
	printf("请输入要删除节点的学号:");
	scanf("%d", &id);
	DeleteStudentInfoByID(&head, id);
	ShowStudentInfo(head);

	return 0;
}
