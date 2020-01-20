/*
1,   unsigned int my_pow(unsigned int x,unsigned int y);
#include <stdio.h>

unsigned int my_pow(unsigned int x,unsigned  int y);

unsigned int my_pow(unsigned int x,unsigned  int y)
{
		int i,s=1;
		for(i=1;i<=y;i++)
		{
				s *= x;
		}
		return s;
}

int main()
{
		int x,y,ret=1;
		printf("请输入数据：");
		scanf("%d%d",&x,&y);
		ret=my_pow(x,y);
		printf("ret=%d\n",ret);
		return 0;
}

*/

/*
2,  设计函数，求一个整型和一个浮点型数的平均值

3,  设计函数，求两个整型数的最小数

double  ave(int a,double b)
{
		return (a+b)/2;
}

int   min(int a,int b)
{
		return a<b?a:b;
}

*/



/*
4, 计算面积系统

   (1),设计菜单
   (2),设计长方形  三角形   圆的函数
   (3),组合成一个系统

   */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define  PI   3.14159
void  menu()
{
		printf("\t计算图形面积系统\n");
		printf("1,长方形面积\n");
		printf("2,三角形形面积\n");
		printf("3,圆形面积\n");
		printf("0,退出\n");
		printf("请输入你的选择:\n");
}

double  function1(double a,double b)
{
		return a*b;
}

double  function2(double a,double b)
{
		return (double)1/2*a*b;
}

double circle(double r)
{
       return PI*r*r;
}

int main()
{
		int sel,flag=1;
		double a,b,ret;
		while(flag)
		{
				system("clear");
				menu();
				scanf("%d",&sel);
				switch(sel)
				{
						case 1:
								printf("请输入长和宽:");
								scanf("%lf%lf",&a,&b);
								ret=function1(a,b);
								printf("长方形面积为：%.2lf\n",ret);
								sleep(2);
								break;
						case 2:
								printf("请输入底和高:");
								scanf("%lf%lf",&a,&b);
								ret=function2(a,b);
								printf("三角形形面积为：%.2lf\n",ret);
								sleep(2);
								break;
						case 3:
								printf("请输入半径:");
								scanf("%lf",&a);
								ret=circle(a);
								printf("圆形面积为：%.2lf\n",ret);
								sleep(2);
								break;
						case 0:
								flag = 0;
								break;
						default:
								printf("选择有误，请重新输入！\n");
								sleep(2);
								break;

				}

		}
		return 0;
}
