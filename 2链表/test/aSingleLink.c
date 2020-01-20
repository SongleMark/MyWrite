/*************************************************************************
	> File Name: aSingleLink.c
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月28日 星期四 15时24分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int _mIdNumber = 10001;
static int _mIsStop = 0;

typedef struct NodeInfo {
    int    iId;       // id
    int    iAge;      // age
    char   iName[32]; // name
    float  iScore     // score
    struct NodeInfo *next;
} NODEINFO;

/**
 * @brief: addNodetoLink
 * @function: add a nodeinfo to link
 */
void addNodetoLink(NODEINFO **head) {
    NODEINFO *pnew = NULL;
    while(!_mIsStop) {
        pnew = (NODEINFO *)mallo(sizeof(NODEINFO));
        if(NULL == pnew) {
            perror("malloc pnew error");
            return;
        }
        printf("please input name:");
        scanf("%s", pnew->iName);
        getchar();
        printf("please input age:");
        scanf("%d", pnew->iAge);
        getchar();
        printf("please input ");
    }
}

int main(int argc, char *argv[]) {
    return 0;
}
