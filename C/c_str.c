/*************************************************************************
	> File Name: c_str.c
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月26日 星期二 15时42分23秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Strlen(const char *str) {
    int length = 0;
    while('\0' != str[length]) {
        length ++;
    }

    return length;
}

char *Strcpy(char *dest, const char *src) {
    int i = 0;
    while('\0' != src[i]) {
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';

    return dest;
}

char *Strcat(char *dest, const char *src) {
    int i   = 0;
    int len = Strlen(dest);
    while('\0' != src[i]) {
        dest[len] = src[i];
        i   ++;
        len ++;
    }
    dest[len] = '\0';

    return dest;
}

char *ReverseStr(char *str) {
    int  i = 0;
    int  j = Strlen(str) - 1;
    char temp;
    for(; i < j; i ++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}

int main(int argc, char *argv[]) {
    char str[32] = "abcdefg";
    printf("str = %s\n", str);
    ReverseStr(str);
    printf("after reverse str = %s\n", str);

    char dest[32] = "hello";
    char src[32]  = "abcdefg";
    printf("dest = %s, src = %s\n", dest, src);
    Strcpy(dest, src);
    printf("after strcpy dest = %s\n", dest);
    Strcat(dest, src);
    printf("after strcat dest = %s\n", dest);


    return 0;
}

