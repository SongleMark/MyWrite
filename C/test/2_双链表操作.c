#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *pre;
	struct node *next;
} NODE;

int _mIsStop = 0;

/// 创建双链表
void CreateNodeLink(NODE **head) {
	NODE *pnew = NULL;
	NODE *last = *head;
	char flag[8];
	while(!_mIsStop) {
		pnew = (NODE *)malloc(sizeof(NODE));
		if(NULL == pnew) {
			perror("malloc error");
			return ;
		}
		printf("input :");
		scanf("%d", &pnew->data);
		if(NULL == *head) {
			*head = pnew;
		}
		else {
			last->next = pnew;
			pnew->pre = last;
		}
		last = pnew;

		printf("是否继续添加(yes/no)? ");
		scanf("%s", flag);
		if(0 == strcmp("no", flag) || 0 == strcmp("NO", flag)) {
			break;
		}
	}
}

/// 打印
void ShowNodeInfoLink(NODE *head) {
	if(NULL == head) {
		printf("当前无节点存入 ...\n");
		return ;
	}

	while(head) {
		printf("[%d] --> ", head->data);
		head = head->next;
	}
	printf("\n");

}

void DeleteNodeInfoByData(NODE **head, int data) {
	if(NULL == *head) {
		printf("当前无节点存入 ...\n");
		return ;
	}

	NODE *p = *head;
	while(p) {
		if(data == p->data) {
			break;
		}
		p = p->next;
	}
	if(NULL == p) {
		printf("输入的data错误 ...\n");
		return ;
	}

	if(p == *head) {
		*head = (*head)->next;
	}
	else {
		p->pre->next = p->next;
		p->next->pre = p->pre;
		free(p);
	}
}


int main(int argc, char *argv[]) {
	NODE *head = NULL;
	CreateNodeLink(&head);
	ShowNodeInfoLink(head);

	int data;
	printf("请输入要删除的data:");
	scanf("%d", &data);
	DeleteNodeInfoByData(&head, data);
	ShowNodeInfoLink(head);
	
	return 0;
}
