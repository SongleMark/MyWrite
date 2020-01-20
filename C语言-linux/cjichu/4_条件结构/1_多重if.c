#include <stdio.h>
/*
if(expre1)
{
   语句块1;
}
else if(expre2)
{
   语句块2;
}
.....
else
{
   .....
}



ps:
1,else部分可以省略
2,if 或者  else if后面必须加条件表达式
3,条件表达式后面不能加分号
4,每个分支默认只能控制一条语句，如果有两条或者以上必须加{}
   */



//  >=90   A
//  80-90   B
//  70-80   C
// 60-70    D
//  <60     E
#if   0
int main()
{
        double  score;
		printf("请输入一个成绩：");
		scanf("%lf",&score);
        
		if(score<0 || score>100)
		{
				printf("数据不合法！\n");
		}
		else if(score>=90)
		{
				printf("A\n");
		}
		else if(score>=80 )
		{
				printf("B\n");
		}
		else if(score>=70)
		{
				printf("c\n");
		}
		else if(score>=60)
		{
				printf("D\n");
		}
		else if(score<60)
		{
				printf("E\n");
		}


		printf("判断完毕！\n");


		return 0;
}
#endif
