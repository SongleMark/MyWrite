#include<stdio.h>
#if   0
//函数声明
double add_function(int,double);

int main()
{
        int a=2;
		double b=3,ret=0;

		ret=add_function(a,b);//  函数调用   a,b  实参
                          //  int add_function(int,int);
		printf("ret=%.2lf\n",ret);
		return 0;
}
//函数定义
double add_function(int a,double b)  // x ,y 形参
{
		double  ret = a+b;
		return ret;
}
#endif




void  function()
{
		int a;
		double b;
		printf("请输入数据：");
		scanf("%d%lf",&a,&b);
		printf("%.2lf\n",a+b);
}


void  menu()
{
		printf("1,添加学生\n");
		printf("2,删除学生\n");
}
int main()
{
//		function();
         menu();
    		return 0;
}
