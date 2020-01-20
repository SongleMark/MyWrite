#include<stdio.h>
#include <string.h>


struct stu
{
		int num;
		double score;
};

/*

->:

结构体指针->成员     表示指针指向的结构体变量的某个成员

   */

int main()
{
		struct stu  s1={1001,90};
        struct stu  *ps=NULL;
		ps = &s1;

//        printf("(*ps).num = %d\n",(*ps).num);
//		printf("(*ps).score=%.2lf\n",(*ps).score);

		printf("请输入学号:");
		scanf("%d",&(*ps).num);
//		scanf("%d",&(ps->num));
		printf("请输入成绩：");
		scanf("%lf",&ps->score);
        printf("ps->num:%d\n",ps->num);
		printf("ps->score:%.2lf\n",ps->score);
		return 0;
}
