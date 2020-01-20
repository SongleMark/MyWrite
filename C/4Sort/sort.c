/*************************************************************************
> File Name: sort.c
> Author: MaSongle
> Mail  : 1830917719@qq.com
> Created Time: 2019年11月29日 星期五 14时19分42秒
************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SwapValue(int *valueA, int *valueB) {
    int temp;
    temp    = *valueA;
    *valueA = *valueB;
    *valueB = temp;
}

void QuicklySort(int *array, int low, int high) {
#if 1
    int key    = array[low];
    int _mLow  = low;
    int _mHigh = high;

    printf("low = %d, high = %d\n", low, high);
    if(low >= high) {
        perror("sort error(low > high)");
        return ;
    }
    while(low < high) {
        while(low < high && key <= array[high]) {
            high --;
        }
        if(key > array[high]) {
            SwapValue(&array[low], &array[high]);
            low ++;
        }
        while(low < high && key >= array[low]) {
            low ++;
        }
        if(key < array[low]) {
            SwapValue(&array[high], &array[low]);
            high --;
        }


    }
        QuicklySort(array, _mLow, _mLow - 1);
        QuicklySort(array, _mLow + 1, _mHigh);
}
    #endif

#if 0
    int i = low;
    int j = height;
    int key = array[low];
    if(low >= height) {
        return ;
    }
    while(low < height) {
        while(low < height && key <= array[height]) {
            height --;
        }
        if(key > array[height]) {
            SwapValue(array[low], array[height]);
            low ++;
        }
        while(low < height && key >= array[low]) {
            low ++;
        }
        if(key < array[low]) {
            SwapValue(array[low], array[height]);
            height --;
        }
    }

        QuicklySort(array, i, low - 1);
        QuicklySort(array, low + 1, j);
#endif     
//}


int main(int argc, char *argv[]) {
    int array[9];
    for(int i = 0; i < 9; i ++) {
        printf("please input array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf("before sort ...\n");
    for(int i = 0; i < 9; i ++) {
        printf("array[%d] = %d ", i, array[i]);
    }
    printf("\n");

    printf("after sort ...\n");
    QuicklySort(array, 0, 8);
    for(int i = 0; i < 9; i ++) {
        printf("array[%d] = %d ", i, array[i]);
    }
    printf("\n");

    return 0;
}
