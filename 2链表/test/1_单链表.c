
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum RETURNTYPE{
    CORRECT_TYPE = 0,
    ERROR_TYPE
};

typedef struct NodeData {
    int data;
    struct NodeData *next;
} NODEDATA;

//int isStop_ = 0;

static int dataNum_ = 10001;

int AddDataNodeToLink(NODEDATA **head) {
    NODEDATA *nodePtr = NULL;

    nodePtr = (NODEDATA *)malloc(sizeof(NODEDATA));
    if(NULL == nodePtr) {
        perror("malloc error");
        return ERROR_TYPE;
    }
    nodePtr->data = dataNum_;
    nodePtr->next = *head;
    *head = nodePtr;
    dataNum_ ++;
    printf("add node successed ...\n");

    return CORRECT_TYPE;
}

int DelDataNodeFromLink(NODEDATA **head) {
    if(NULL == head) {
        printf("当前未存入数据, 不可进行删除操作 ...\n");
        return ERROR_TYPE;
    }
    int delData;
    NODEDATA *delPtr = *head;
    printf("please input del data: ");
    scanf("%d", &delData);
    while(NULL != delPtr) {
        if(delData == delPtr->data) {
            break;
        }
        delPtr = delPtr->next;
    }
    if(NULL == delPtr) {
        printf("输入的数据不存在 !!!\n");
        return ERROR_TYPE;
    }

    if(delPtr == *head) {
        *head = (*head)->next;
    }
    else {
        NODEDATA *prePtr = *head;
        while(prePtr->next != delPtr) {
            prePtr = prePtr->next;
        }
        prePtr->next = delPtr->next;
        free(delPtr);
    }
    printf("delete node from link successed ...\n");

    return CORRECT_TYPE;
}

void ShowDataLink(NODEDATA *head) {
    if(NULL == head) {
        printf("当前未存入数据 ...\n");
        return ;
    }
    NODEDATA *tempPtr = head;
    while(NULL != tempPtr) {
        printf("%d ==> ", tempPtr->data);
        tempPtr = tempPtr->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    NODEDATA *head = NULL;
#if 0
    AddDataNodeToLink(&head);
    AddDataNodeToLink(&head);
    AddDataNodeToLink(&head);
    AddDataNodeToLink(&head);
    ShowDataLink(head);
    DelDataNodeFromLink(&head);
    ShowDataLink(head);
    DelDataNodeFromLink(&head);
    ShowDataLink(head);
#endif

    return 0;
}


