#include <stdio.h>
#include <string.h>

struct date
{
		int year;
		int month;
		int day;
};

struct student
{
		int num;
		char name[32];
		double score;
		struct date   bir;
//		int year;
//		int month;
//		int day;
};


int main()
{
		struct student s1={1001,"zhangsan",90,{1999,10,1}};

		printf("请输入学号：");
		scanf("%d",&s1.num);
		getchar();
		printf("请输入姓名：");
		scanf("%s",s1.name);
		getchar();
		printf("请输入成绩：");
		scanf("%lf",&s1.score);
		getchar();
		printf("请输入出生日期(yy-mm-dd):");
		scanf("%d-%d-%d",&s1.bir.year,&s1.bir.month,&s1.bir.day);
		getchar();
		printf("s1.num = %d\n",s1.num);
		printf("s1.name=%s\n",s1.name);
		printf("s1.score=%.2lf\n",s1.score);
		printf("%d-%d-%d\n",s1.bir.year,s1.bir.month,s1.bir.day);
		return 0;
}
