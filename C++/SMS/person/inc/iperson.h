/*************************************************************************
	> File Name: iperson.h
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月20日 星期三 17时29分17秒
 ************************************************************************/

#ifndef _IPERSON_H
#define _IPERSON_H

/*       学生信息结构体          */
typedef struct StudentInformation {
    int   iId;               // 学号
    int   iAge;              // 年龄
    int   iClass;            // 班级
    char  iName[32];         // 姓名
    char  iProfessional[32]; // 专业
    float iScore;            // 成绩
} STUDENTINFORMATION;


class IPerson {
public:
    IPerson() {}
    ~IPerson() {}
    virtual AddPerson() = 0;
    virtual DelPerson() = 0;
    virtual ModifyPerson() = 0;
    virtual FoundPerson() = 0;

};

#endif
