#include <stdio.h>
#include <string.h>
#include "head.h"
#if  0
//定义结构体   本质就是定义一种数据类型   类型名称就是  struct  student
struct student
{
		int num;
		char name[32];
		double score;
}s2;
#endif

struct 
{
		int  num;
		char name[32];
}s3,s4;
#if   0
int  main()
{
		struct student s1={1001,"zahngsan",89.9};


		//		s1.num = 2222;
		//      strcpy(s1.name,"xiaoqi");
		//	s1.score = 99.99;


		printf("请输入学号：");
		scanf("%d",&s1.num);
        getchar();
		printf("请输入姓名:");
		scanf("%s",s1.name);
        getchar();
		printf("请输入成绩：");
		scanf("%lf",&s1.score);
        getchar();


				printf("s1.num=%d\n",s1.num);
		printf("s1.name=%s\n",s1.name);
		printf("s1.score=%.2lf\n",s1.score);
		return 0;

}
#endif




int main()
{
		struct student s[5]={{1001,"zhangsan",90},{1002,"lisi",99}};

		int i;
		for(i=0;i<5;i++)
		{
				printf("请输入第%d个学生的学号:",i+1);
				scanf("%d",&s[i].num);
				getchar();
				printf("请输入第%d个学生的姓名：",i+1);
				scanf("%s",s[i].name);
				getchar();
				printf("请输入第%d个学生的成绩:",i+1);
				scanf("%lf",&s[i].score);
				getchar();
		}


		for(i=0;i<5;i++)
		{
				printf("%d\t%s\t%.2lf\n",s[i].num,s[i].name,s[i].score);
		}
		return 0;
}
