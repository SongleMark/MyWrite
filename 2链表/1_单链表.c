#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NodeInfo {
	int data;
	struct NodeInfo *next;
} NODEINFO;

int _mIsStop = 0;

/// 创建一个链表
int CreateNodeInfoLink(NODEINFO **head) {
	NODEINFO *pnew = NULL;
	while(!_mIsStop) {
		pnew = (NODEINFO *)malloc(sizeof(NODEINFO));
		if(NULL == pnew) {
			perror("malloc error");
			return -1;
		}
		printf("please input data:");
		scanf("%d", &pnew->data);
		getchar();
		pnew->next = *head;
		*head = pnew;

		char flag[6];
		printf("continue to add node?(yes/no)\n");
		scanf("%s", flag);
		getchar();
		if(0 == strcmp("no", flag) || 0 == strcmp("NO", flag)) {
			break;
		}
	}

	return 0;
}

/// 根据链表节点的某个值删除一个节点
int DeleteNodeFromLinkByData(NODEINFO **head, int data) {
	if(NULL == *head) {
		printf("当前无节点可删除 ...\n");
		return -1;
	}

	// 先找到要删除的节点
	NODEINFO *pdel = *head;
	while(NULL != pdel) {
		if(data == pdel->data) {
			break;
		}
		pdel = pdel->next;
	}

	// 如果pdel为null说明没找到，传入的data不对，链表中没有
	if(NULL == pdel) {
		printf("没有找到data = %d的节点\n", data);
		return -1;
	}

	//找到后开始删除该节点，两种情况
	//1.该节点为第一个节点
	if(*head == pdel) {
		*head = (*head)->next;
	}
	else { // 2. 该节点为中间节点或最后一个
		NODEINFO *pre = *head;  // 先找到要删除节点的前一个节点
		while(pre->next != pdel) {
			pre = pre->next;
		}
		pre->next = pdel->next;
		free(pre);
	}

	return 0;
}

/// 摧毁整个链表
void DestroyFullNodeLink(NODEINFO **head) {
	if(*head == NULL) {
		printf("空链表 ...\n");
		return ;
	}

	NODEINFO *pdel = *head;
	while(NULL != *head) {
		pdel = *head;
		*head = (*head)->next;
		free(pdel);
	}
}

/// 打印整条链表值
void ShowNodeInfoFromLink(NODEINFO *head) {
	if(NULL == head) {
		printf("空链表 ...\n");
		return ;
	}

	NODEINFO *pshow = head;
	while(pshow) {
		printf(" [data] = %d ->", pshow->data);
		pshow = pshow->next;
	}
	printf("\n");
}

void DeleteOneNode(NODEINFO **head, int data) {
	if(NULL == *head) {
		printf("空链表 ...\n");
		return ;
	}
	NODEINFO *pdel = *head;
	while(pdel) {
		if(data == pdel->data) {
			break;
		}
		pdel = pdel->next;
	}
	if(NULL == pdel) {
		printf("没有data = %d的节点\n", data);
		return ;
	}
	if(*head == pdel) {
		*head = (*head)->next;
	}
	else {
		NODEINFO *pre = *head;
		while(pre->next != pdel) {
			pre = pre->next;
		}
		pre->next = pdel->next;
		free(pdel);
	}

}


int main(int argc, char *argv[]) {
	NODEINFO *head = NULL;
	int data;

	CreateNodeInfoLink(&head);
	printf("当前链表为: \n");
	ShowNodeInfoFromLink(head);

#if 0
	printf("请输入要删除的值:");
	scanf("%d", &data);
	DeleteNodeFromLinkByData(&head, data);
	printf("删除data = %d后 \n", data);
	ShowNodeInfoFromLink(head);
#endif

	printf("请输入要删除的值:");
	scanf("%d", &data);
	DeleteOneNode(&head, data);
	printf("删除data = %d后 \n", data);
	ShowNodeInfoFromLink(head);

	DestroyFullNodeLink(&head);
	printf("摧毁整个链表后 ...\n");
	ShowNodeInfoFromLink(head);

	return 0;
}
