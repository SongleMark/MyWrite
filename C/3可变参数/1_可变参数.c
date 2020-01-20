/*************************************************************************
  > File Name: 1_可变参数.c
  > Author: MaSongle
  > Mail  : 1830917719@qq.com
  > Created Time: 2019年11月21日 星期四 08时44分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#if 0
void fun(int a, ...) {
    int *temp = &a;
    temp ++;
    for(int i = 0; i < a; i ++) {
        printf("第%d个参数为%d\n", i, *temp);
        temp ++;
    }
}

int main(int argc, char *argv[]) {
    fun(4, 1, 2, 3, 4);

    return 0;
}
#endif

int demo(char *msg, ...) {
    // 定义保存函数参数的结构
    va_list argp;
    int argno = 0;
    char *para;

    // argp指向传入的第一个可选参数，msg为最后一个确定的参数
    va_start(argp, msg);
    while(*msg ++) {
        para = va_arg(argp, char *);
        if(0 == strcmp(para, "")) {
            break;
        }

        printf("第%d个参数为%s\n", argno + 1, para);
        argno ++;
    }

    // 将指针指向nullptr
    va_end(argp);

    return 0;
}


void foo(char *fmt, ...) {
    va_list ap;
    int d;
    char c, *s;
    float ft;

    va_start(ap, fmt);
    while (*fmt) {
        switch (*fmt++) {
            case 's':              /* string */
                s = va_arg(ap, char *);
                printf("string %s\n", s);
                break;
            case 'd':              /* int */
                d = va_arg(ap, int);
                printf("int %d\n", d);
                break;
            case 'c':              /* char */
                /* need a cast here since va_arg only
                   takes fully promoted types */
                c = (char) va_arg(ap, int);
                printf("char %c\n", c);
                break;
            case 'f':
                ft = (float)va_arg(ap, double);
                printf("float is %f\n", ft);
                break;
        }
    }

    va_end(ap);
}

int MyPrint(const char *fmt, ...) {
    char sprint_buf[1024];
    va_list args;
    int n;
    va_start(args, fmt);
    n = vsprintf(sprint_buf, fmt, args);
    va_end(args);
    //write(stdout, sprint_buf, n);
    printf("%s\n", sprint_buf);

    return 0;
}

int main(int argc, char *argv[]) {
    //demo("demo", "hello", "worlid");
    //foo("%s %d %s %f", "hello", 1, "hehda", 0.8);
    MyPrint("my name is %s age is %d, address is %s", "masongle", 23, "安徽安庆");
    
    return 0;
}
