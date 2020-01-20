/*************************************************************************
	> File Name: student.h
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月21日 星期四 13时39分29秒
 ************************************************************************/

#ifndef _STUDENT_H
#define _STUDENT_H

#include "iperson.h"

class StudentService : public IPerson {
public:
    StudentService();
    ~StudentService();
    void AddPerson();
    void DelPerson();
    void ModifyPerson();
    void FoundPerson();

private:
    STUDENTINFORMATION mInformation;
};

#endif
