#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

/**
 *  C Language
 */

 // 链表

static bool _mIsStop = false;

typedef struct NodeInfo {
    int   _mId;       
    char  _mName[32];
    float _mScore;
    
    struct NodeInfo *_mNext;
} NODEINFO;

void AddNodeInfo(NODEINFO **head) {
    NODEINFO *pnode = NULL;
    NODEINFO *plast = NULL;
    
    while(!_mIsStop) {
        pnode = new NODEINFO[sizeof(NODEINFO)];

    }
}
