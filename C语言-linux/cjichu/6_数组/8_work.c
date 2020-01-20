/*
1,从键盘输入三个学生的三门科成绩（语文、数学、英语），输出该三个学生的所有成绩并输出
每门科的平均成绩
#include <stdio.h>

int main()
{
		double a[3][3];
		int i,j;
		double a_c=0,a_m=0,a_e=0;
		for(i=0;i<3;i++)
		{
		        printf("请输入第%d个学生的成绩：",i+1);
				for(j=0;j<3;j++)
				{
						scanf("%lf",&a[i][j]);
				}
		}

        printf("学号\t语文\t数学\t英语\n");
		for(i=0;i<3;i++)
		{
				printf("%d\t",i+1);
				for(j=0;j<3;j++)
				{
						printf("%.2lf\t",a[i][j]);
						if(j==0)
						{
                               a_c += a[i][j];
						}
						else if(j==1)
						{
								a_m+=a[i][j];
						}
						else if(j==2)
						{
								a_e+=a[i][j];
						}
				}
				printf("\n");
		}
		printf("平均分\t%.2lf\t%.2lf\t%.2lf\n",a_c/3,a_m/3,a_e/3);


		return 0;
}


*/
/*

2,定义一个数组，储存2010-2017年每月的降水量（数据初始化），输出年降水总量、年降水平均量、月降水平均量

#include <stdio.h>

int main()
{
		double a[8][12]={
		                {1,2,3,4,5,6,7,8,9,0,1,2},
		                {0,2,3,4,5,6,7,8,9,0,1,0},
		                {1,1,3,4,5,6,7,8,9,0,2,2},
		                {1,2,0,4,5,6,7,8,9,12,1,2},
		                {1,2,3,12,5,6,7,8,0,0,1,2},
		                {1,2,3,4,4,6,7,8,0,0,1,2},
		                {1,2,3,4,5,3,7,0,9,0,1,2},
		                {1,2,3,4,5,6,0,8,9,0,1,2}
		};


		int i,j;
		double sum=0,total_sum=0;;
		printf("年份\t总降水量\n");
		for(i=0;i<8;i++)
		{
				printf("%d\t",2010+i);
				for(sum=0,j=0;j<12;j++)
				{
                     sum += a[i][j];
				}
				total_sum += sum;
				printf("%.2lf\n",sum);
		}

		printf("\n年降水平均量：%.2lf\n",total_sum/8);
       


		printf("\n月份\t平均降水量\n");
		for(j=0;j<12;j++)
		{
				printf("%d月份\t",j+1);
				for(sum=0,i=0;i<8;i++)
				{
                    sum += a[i][j];
				}
				printf("%.2lf\n",sum/8);
		}
		return 0;


}


*/

/*

3,定义一个数组，存储一个四维矩阵

1   3  5  7
7   8  9  2
12 56 89 90 
23 45 66 99
分别输出正对角线和逆对角线之和
#include <stdio.h>

int main()
{
		int a[4][4]={
		    {1,3,5,7},
			{7,8,9,2},
			{12,56,89,90},
			{23,45,66,99}
		};

		int sum1=0,sum2=0;
        int i,j;
		for(i=0;i<4;i++)
		{
				for(j=0;j<4;j++)
				{
						if(i == j)
						{
                             sum1 += a[i][j];
						}
						if(i+j ==3 )
						{
								sum2 += a[i][j];
						}
				}
		}

		printf("sum1=%d,sum2=%d\n",sum1,sum2);
		return 0;
}

*/

/*

4,定义一个int  a[3][4] ,数据从键盘输入，找出每列的最小值，存储到指定的一维数组中去
*/
#include <stdio.h>

#define  NUM1  3
#define  NUM2  4



int main()
{
		int a[NUM1][NUM2];
        int b[NUM2],min;
		int i,j;
		for(i=0;i<NUM1;i++)
		{
				for(j=0;j<NUM2;j++)
				{
						printf("请输入第%d行第%d列的数据:",i+1,j+1);
						scanf("%d",&a[i][j]);
				}
		}



		for(j=0;j<NUM2;j++)
		{
				for(i=0,min=a[0][j];i<NUM1;i++)
				{
						if(a[i][j]<min)
						{
								min=a[i][j];
						}
				}
				b[j] = min;
		}

		for(i=0;i<NUM2;i++)
		{
				printf("第%d列最小值为:%d\n",i+1,b[i]);
		}


		return 0;
}









