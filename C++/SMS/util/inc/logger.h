/*************************************************************************
> File Name: logger.h
> Author: MaSongle
> Mail  : 1830917719@qq.com
> Created Time: 2019年11月20日 星期三 17时33分10秒
************************************************************************/

#ifndef _LOGGER_H
#define _LOGGER_H

#include <cstdio>
#include <time.h>
#include <cstdarg>
#include <iostream>

/** 
struct tm {
    int tm_sec;    // Seconds (0-60) 
    int tm_min;    // Minutes (0-59) 
    int tm_hour;   // Hours (0-23) 
    int tm_mday;   // Day of the month (1-31) 
    int tm_mon;    // Month (0-11) 
    int tm_year;   // Year - 1900 
    int tm_wday;   // Day of the week (0-6, Sunday = 0) 
    int tm_yday;   // Day in the year (0-365, 1 Jan = 0) 
    int tm_isdst;  // Daylight saving time 
};
*/

#define LOGD     Logger::Print
#define LOGE     Logger::PrintError
#define OUTPUT   std::cout
#define NEWLINE  std::endl
#define OUTPRINT printf
#define REDCOLOR "\e[31m"
#define SRCCOLOR "\e[0m"

/**
 * 打印日志log类 LOGD LOGE
 * 1. 可打印当前系统时间，精确到秒(2019/11/21 12:08:08)
 * 2. 传入的第一个参数为类名或函数名,用于快速定位log发生处(2019/11/21 12:08:08 [Logger])
 * 3. 传入的第三个参数格式与printf相同
 * 
 * example:
 *      char *name     = "SongleMark";
 *      int   age      = 23;
 *      char *hometown = "安徽安庆";
 *      LOGD("Logger", "my name is %s, I'm %d years old, my hometown is %s", name, age, hometown);
 *      此时输出为: 2019-11-21 12:08:08 [Logger]:my name is SongleMark I'm 23 years old, my hometown is 安徽安庆
 * 从以上例子可以快速找出事件发生的时间和类
 */
class Logger {
public:
    Logger()  {}
    ~Logger() {}

    /**
     * @brief:    Logger:Print
     * @function: 打印当前系统时间和当前所在类名称
     * @format  : 2000/1/1 10:18:18 [class name]
     */
    static inline void Print(const char *tag) {
        char str[66];
        time_t mtm = time(nullptr);
        struct tm *currenttime = localtime(&mtm);
        //OUTPRINT("%d/%d/%d %d:%d:%d [%s]:", currenttime->tm_year + 1900, currenttime->tm_mon + 1, currenttime->tm_mday, currenttime->tm_hour, currenttime->tm_min, currenttime->tm_sec, tag);
        strftime(str, 66, "%F %T", currenttime);
        OUTPRINT("%s [%s]", str, tag);
        
    }

    /**
     * @brief   : Logger::Print
     * @function: 用于打印普通log 
     * @format  : LOGD("class name", "output");
     */
    template <typename T>
    static void Print(const char *tag, const T &data) {
        Print(tag);
        OUTPUT << data << NEWLINE;
    }
    
    /**
     * @brief   : Logger::Print
     * @function: 用于打印普通组合log，采用可变参数形式类似printf
     * @format  : LOGD("class name", "value is %s, value2 is %d value3 is %f", value, value2, value3);
     */
    static inline void Print(const char *tag, const char *fmt, ...) {
        char printBuf[2048];
        // 保存函数参数指针
        va_list argp;
        // 打印当前系统时间和当前所在类名称(不换行)
        Print(tag);
        // arpg指向第一个可选参数，fmt为最后一个确定的参数
        va_start(argp, fmt);
        // 将fmt中具体内容输入到printBuf中
        vsprintf(printBuf, fmt, argp);
        // 打印log内容
        OUTPUT << printBuf << NEWLINE;
    }

    /**
     * @brief   : Logger::PrintError
     * @function: 用于打印错误发生处的log
     * @format  : LOGE("class name", "value is %s value1 is %d ...", value, value1);
     */
    static inline void PrintError(const char *tag, const char *fmt, ...) {
        char printBuf[2048];
        // 保存函数的指针
        va_list argp;
        // argp指向第一个可变参数，fmt为最后一个确定的参数
        va_start(argp, fmt);
        // 将fmt中具体内容输:wq
        // 入到printBuf
        vsprintf(printBuf, fmt, argp);
        // 将argp指针指向nullptr
        va_end(argp);
        // 输出时间和类名
        Print(tag);
        // 将错误信息输出为红色
        OUTPUT << REDCOLOR << printBuf << SRCCOLOR << NEWLINE;
    }
};

#endif
