#include <stdio.h>
#include <string.h>



struct stu
{
		int num;
		double score;
};


struct stu get_stu_info()
{
		struct stu s1;
		printf("请输入学号：");
		scanf("%d",&s1.num);
		printf("请输入成绩:");
		scanf("%lf",&s1.score);
		return s1;
}

void  show_stu_info(struct stu s2)
{
		printf("学号:%d\n",s2.num);
		printf("成绩：%.2lf\n",s2.score);
}


void  mod_stu_info(struct stu *ps)
{
		printf("请输入新的学号：");
		scanf("%d",&ps->num);
		printf("请输入新的成绩：");
		scanf("%lf",&ps->score);
}




int  main()
{
		struct stu s1={1001,99},s2;
//		s2 = s1;
//		s2 = get_stu_info();
        mod_stu_info(&s1)	;	
		show_stu_info(s1);
		return 0;
}
