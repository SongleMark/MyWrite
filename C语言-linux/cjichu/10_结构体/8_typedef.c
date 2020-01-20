#include <stdio.h>

typedef  int   YS_INT;
typedef  int *   P_INT;


typedef struct student
{
		int num;
		double score;
}STU,*PSTU;


//typedef  struct student  STU;
//typedef  struct student*  PSTU;

int main()
{
		YS_INT  a;//  int a
		P_INT   b;//  int *p
        STU  s1;//  struct student s1;
		PSTU  ps = &s1;// struct student *ps   = &s1
		return 0;
}
