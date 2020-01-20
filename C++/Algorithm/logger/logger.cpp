/*************************************************************************
	> File Name: logger.cpp
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年12月11日 星期三 15时55分45秒
 ************************************************************************/

#include "logger.h"

#define OUT      std::cout
#define NEWLINE  std::endl
#define PRINT    printf
#define REDCOLOR "\e[31m"
#define SRCCOLOR "\e[0m"
#define BUFSIZE  2048

/************************************************************************
 * 打印时间以及名称(类名/函数功能名)
 ************************************************************************/
void Logger::Print(const char *tag) {
    char buf[BUFSIZE];
    time_t tTime = time(NULL);
    tm *currentTime = localtime(&tTime);
    strftime(buf, BUFSIZE, "%F %T", currentTime);
    PRINT("%s [%s]:", buf, tag);
}

/************************************************************************
 * 打印普通log，格式为 xxxx年-xx月-xx日 xx时:xx分:xx秒 [tag]: content
 ************************************************************************/
void Logger::Print(const char *tag, const char *format, ...) {
    char buf[BUFSIZE];
    va_list argp;
    va_start(argp, format);
    vsprintf(buf, format, argp);

    Print(tag);
    OUT << buf << NEWLINE;
}

/************************************************************************
 * 打印程序出错地/标志性log, 将log颜色标红,格式与普通log相似
 ************************************************************************/
void Logger::PrintError(const char *tag, const char *format, ...) {
    char buf[BUFSIZE];
    va_list argp;
    va_start(argp, format);
    vsprintf(buf, format, argp);

    OUT << REDCOLOR;
    Print(tag);
    OUT << buf << SRCCOLOR << NEWLINE;
}
