/*
1,定义一个结构体表示员工信息，成员包括：
  工号   姓名   部门   薪资    住址
   
  定义一个员工，数据分别使用初始化   赋值   从键盘输入三种方法获取，并输出


2,定义一个数组存储20个学生信息，信息有：学号  姓名   成绩
  学号：1-20
  姓名：noname
  成绩：0

   */


#include <stdio.h>
#include <string.h>

#include "head.h"

int main()
{
		struct student s[20];
		int i;
		for(i=0;i<20;i++)
		{
				s[i].num = i+1;
				strcpy(s[i].name,"noname");
				s[i].score = 0;
		}
		return 0;
}
