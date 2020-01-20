/*************************************************************************
	> File Name: test.c
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2020年01月04日 星期六 14时44分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int mIsStop = 0;

static int mIdNum  = 10001;

typedef struct StudentNode {
    int   mId;
    int   mAge;
    char  mName[32];
    float mScore;
    struct StudentNode *mNext;
} STUDENT_NODE;

void AddStudentNode(STUDENT_NODE **head) {
    STUDENT_NODE *ptrNode = NULL;
    char isBrake[8];
    while(!mIsStop) {
        ptrNode = (STUDENT_NODE *)malloc(sizeof(STUDENT_NODE));
        if(NULL == ptrNode) {
            perror("malloc error");
            return;
        }
        printf("please input age: ");
        scanf("%d", &ptrNode->mAge);
        getchar();
        printf("please input name: ");
        scanf("%s", ptrNode->mName);
        getchar();
        printf("please input score: ");
        scanf("%f", &ptrNode->mScore);
        getchar();
        ptrNode->mId = mIdNum;
        mIdNum ++;
        
        ptrNode->mNext = *head;
        *head = ptrNode;

        printf("continue (yes/no)?\n");
        scanf("%s", isBrake);
        getchar();
        if(0 == strcmp("no", isBrake) || 0 == strcmp("NO", isBrake)) {
            break;
        }
    }
}

void ShowStudentInfo(STUDENT_NODE *head) {
    if(NULL == head) {
        printf("无学生存入!!!\n");
        return ;
    }
    STUDENT_NODE *ptrShow = head;
    printf("ID\tNAME\tAGE\tSCORE\n");
    while(NULL != ptrShow) {
        printf("%d\t%s\t%d\t%.2f\n", ptrShow->mId, ptrShow->mName, ptrShow->mAge, ptrShow->mScore);
        ptrShow = ptrShow->mNext;
    }
}


int main(int argc, char *argv[]) {
    STUDENT_NODE *head = NULL;
    AddStudentNode(&head);
    ShowStudentInfo(head);

    return 0;
}
