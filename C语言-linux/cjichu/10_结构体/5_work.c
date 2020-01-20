/*
1,使用嵌套结构体表示学生信息：
   学号   姓名  成绩(语文  数学  英语)  入学日期(年  月  日)

   定义一个数组存储5个学生的基本信息，数据从键盘输入，并输出数据，
   要求使用指针实现
 
*/



#include <stdio.h>
#include <string.h>


struct score 
{
		double chinese;
		double math;
		double english;
};


struct date
{
		int year;
		int month;
		int day;
};


struct stu
{
		int num;
		char name[32];
		struct score s;
        struct date  d;
};


int  main()
{
		struct  stu s1[5];
        struct  stu *ps = &s1[0];
		int i;
		for(i=0;i<5;i++)
		{
				printf("请输入第%d个学生的学号:",i+1);
				scanf("%d",&(ps+i)->num);
				printf("请输入第%d个学生的姓名：",i+1);
				scanf("%s",s1[i].name);
				printf("请输入第%d个学生的成绩:",i+1);
				scanf("%lf%lf%lf",&((ps+i)->s).chinese,&(*(ps+i)).s.math,&s1[i].s.english);
				printf("请输入第%d个学生的入学日期:",i+1);
				scanf("%d-%d-%d",&s1[i].d.year,&s1[i].d.month,&s1[i].d.day);
		}

        for(i=0;i<5;i++) 
		{
				printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\t%d-%d-%d\n",
					ps[i].num,ps[i].name,ps[i].s.chinese,ps[i].s.math,ps[i].s.english,ps[i].d.year,ps[i].d.month,ps[i].d.day);
		}		

		return  0;
}
