
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Strlen(const char *str) {
    int len = 0;
    while('\0' != str[len]) {
        len ++;
    }

    return len;
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
    int i = 0;
    int j = Strlen(dest);
    while('\0' != src[i]) {
        dest[j] = src[i];
        i ++;
        j ++;
    }
    dest[j] = '\0';

    return dest;
}

char *ReverseString(char *str) {
    int i = 0;
    int j = Strlen(str) - 1;
    char temp;
    for(;i < j; i ++, j --) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}

char *DeleteSpace(char *str) {
    int i = 0;
    while('\0' != str[i]) {
        if(' ' == str[i]) {
            for(int j = i; j < Strlen(str); j ++) {
                str[j] = str[j + 1];
            }
            continue;
        }

        i ++;
    }

    return str;
}

int main(int argc, char *argv[]) {
    char src[32] = "abcdefg";
    char dest[32] = "123456";
    printf("before strcpy dest = %s\n", dest);
    Strcpy(dest, src);
    printf("after strcpy dest = %s\n", dest);
    ReverseString(dest);
    printf("after reverse dest = %s\n", dest);
    Strcat(dest, "123456");
    printf("after strcat dest = %s\n", dest);

    char str[32] = "abc d e f  g";
    printf("before DeleteSpace str = %s\n", str);
    DeleteSpace(str);
    printf("after DeleteSpace str = %s\n", str);

    return 0;
}

