
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Signal {
    int data;
    struct NodeInfo *next;
} SINGLE;

typedef struct NodeInfo {
    int data;
    struct NodeInfo *pre;
    struct NodeInfo *next;
} NODEINFO;


