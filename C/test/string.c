
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myStrlen(const char *str) {
    int length = 0;
    while('\0' != str[length]) {
        length ++;
    }

    return length;
}

char *myStrcpy(char *dest, const char *src) {
    int i = 0;
    while('\0' != src[i]) {
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';

    return dest;
}

char *myStrcat(char *dest, const char *src) {
    int i = myStrlen(dest);
    int j = 0;
    while('\0' != src[j]) {
        dest[i] = src[j];
        i ++;
        j ++;
    }
    dest[j] = '\0';

    return dest;
}

char *reverseString(char *str) {
    int i = 0;
    int j = myStrlen(str) - 1;
    char temp;
    for(; i < j; i ++, j --) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}

