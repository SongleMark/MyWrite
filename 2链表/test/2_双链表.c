
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum RETURN_TYPE {
    RETURN_CORRECT = 0,
    RETURN_ERROR
};

typedef struct NodeInfo {
    int data;
    struct NodeInfo *pre;
    struct NodeInfo *next;
} NODEINFO;

static int dataNum = 10001;

int AddNodeToLink(NODEINFO **head) {
    NODEINFO *nodePtr = NULL;
    NODEINFO *lastNodePtr = NULL;
    nodePtr = (NODEINFO *)malloc(sizeof(NODEINFO));
    if(NULL == nodePtr) {
        perror("malloc error");
        return RETURN_ERROR;
    }
    #if 0 // 头插法
    nodePtr->data = dataNum;
    nodePtr->next = *head;
    *head = nodePtr;
    nodePtr->pre = *head;
    dataNum ++;
    #endif
    #if 1 // 尾插法1
    nodePtr->data = dataNum;
    nodePtr->next = NULL;
    nodePtr->pre = NULL;
    dataNum ++;
    if(NULL == *head) {
        *head = nodePtr;
    }
    else {
        lastNodePtr = *head;
        while(lastNodePtr->next != NULL) {
            lastNodePtr = lastNodePtr->next;
        }

        lastNodePtr->next = nodePtr;
        nodePtr->pre = lastNodePtr;
    }

    //lastNodePtr = nodePtr;
    #endif

    return RETURN_CORRECT;
}

void ShowNodeFromLink(NODEINFO *head) {
    if(NULL == head) {
        printf("当前未存入数据 ...\n");
        return ;
    }
    NODEINFO *tempPtr = head;
    while(NULL != tempPtr) {
        printf("%d ==> ", tempPtr->data);
        tempPtr = tempPtr->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    NODEINFO *head = NULL;
    AddNodeToLink(&head);
    AddNodeToLink(&head);
    AddNodeToLink(&head);
    ShowNodeFromLink(head);
    return 0;
}
