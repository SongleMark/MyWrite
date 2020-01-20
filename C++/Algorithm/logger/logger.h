/*************************************************************************
	> File Name: logger.h
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年12月11日 星期三 15时47分59秒
 ************************************************************************/

#ifndef _LOGGER_H
#define _LOGGER_H

#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <iostream>

#define LOGD     Logger::Print
#define LOGE     Logger::PrintError

/************************************************************************
 * 打印log类，外界调用时只需使用LOGD/LOGE
 * 1. LOGD(tag, format, ...); //打印普通log 传入的可变参数格式与printf相同
 *    例如: LOGD("HELLO", "My name is %s, I'm %d years old", "Mark", 23);
 *    输出: xxxx年-xx月-xx日 xx时:xx分:xx秒 [HELLO]: My name is Mark, I'm 23 years old
 * 2. LOGE(tag, format, ...); // 打印程序出错或标志性处log，传入的可变参数格式与printf相同
 *    例如: LOGD("HELLO", "My name is %s, I'm %d years old", "Mark", 23);
 *    输出内容颜色将为红色方便快速定位: xxxx年-xx月-xx日 xx时:xx分:xx秒 [HELLO]: My name is Mark, I'm 23 years old
 ************************************************************************/
class Logger {
public:
    Logger() {}
    ~Logger() {}

    static void Print(const char *tag);
    static void Print(const char *tag, const char *format, ...);
    static void PrintError(const char *tag, const char *format, ...);
};


#endif
