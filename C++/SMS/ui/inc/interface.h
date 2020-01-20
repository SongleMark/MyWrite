/*************************************************************************
	> File Name: interface.h
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月21日 星期四 13时15分45秒
 ************************************************************************/

#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <iostream>
#include <cstdlib>

#define MAINMENU "\t\t\t********************************************************\n\n"\
                 "\t\t\t*                欢迎使用学生管理系统                  *\n\n"\
                 "\t\t\t********************************************************\n\n"\
                 "\t\t\t*                      请输入选项:                     *\n\n"\
                 "\t\t\t*                     1. 学生登录                      *\n\n"\
                 "\t\t\t*                     2. 教师登录                      *\n\n"\
                 "\t\t\t*                     3. 管理员登录                    *\n\n"\
                 "\t\t\t*                     0. 退出系统                      *\n\n"\
                 "\t\t\t********************************************************\n"

class Interface {
public:
    Interface() {}
    ~Interface() {}

    static inline void MainInterFace() {
        system("clear");
        std::cout << MAINMENU;
    }
};


#endif
