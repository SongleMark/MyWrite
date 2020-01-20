
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SINGLE
// #define DOUBLE

typedef struct SingleNodeInfo {
    int data;
    struct SingleNodeInfo *next;
} SINGLENODEINFO;

typedef struct DoubleNodeInfo {
    int data;
    struct DoubleNodeInfo *pre;
    struct DoubleNodeInfo *next;
} DOUBLENODEINFO;

#ifdef SINGLE
void AddNodeToLink(SINGLENODEINFO **head) {
    SINGLENODEINFO *ptrnew  = NULL;
    SINGLENODEINFO *ptrlast = NULL;

}
