#ifndef STUDENT_H
#define STUDENT_H

typedef struct student
{
	int iId;
	char caName[32];
	char caPwd[16];
	float fChinese;
	float fMath;
	float fEnglish;
}STU,*stu;

struct student array[100];

#endif
