/*************************************************************************
	> File Name: test.cpp
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年12月11日 星期三 16时47分25秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include "quicklysort.h"

int main() {
    int arr[] = {1, 2, 4, 9, 3, 0, 7, 8};
    for(int i = 0; i < 8; i ++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    QuicklySort(arr, 0, 7);
    printf("after quickly sort ...\n");
    for(int i = 0; i < 8; i ++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
