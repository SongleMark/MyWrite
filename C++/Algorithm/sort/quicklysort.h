/*************************************************************************
> File Name: quicklysort.h
> Author: MaSongle
> Mail  : 1830917719@qq.com
> Created Time: 2019年12月11日 星期三 16时36分05秒
************************************************************************/

#ifndef _QUICKLYSORT_H
#define _QUICKLYSORT_H

template <typename T>
void SwapValue(T &valueA, T &valueB) {
    T temp;
    temp = valueA;
    valueA = valueB;
    valueB = temp;
}

template <typename T>
void QuicklySort(T *array, int low, int high) {
    int key    = array[low];
    int _mLow  = low;
    int _mHigh = high;
    if(low >= high) {
        return ;
    }
    while(low < high) {
        while(low < high && key <= array[high]) {
            high --;
        }
        if(key > array[high]) {
            SwapValue(array[low], array[high]);
            low ++;
        }
        while(low < high && key >= array[low]) {
            low ++;
        }
        if(key < array[low]) {
            SwapValue(array[low], array[high]);
            high --;
        }
    }

    QuicklySort(array, _mLow, _mLow - 1);
    QuicklySort(array, _mLow + 1, _mHigh);
}

#endif
