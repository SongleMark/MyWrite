#include <stdio.h>
/*
1,指针变量的定义：
   type   *var = &a;
   //  var = &a;
   在定义变量是加 *，*是一个标识符，标志这个变量是指针变量，其他任何情况下，指针前面加*都表示
   指针指向的变量
2,  在64位机中，所有的指针变量8字节
    在32位机中，所有的指针变量4字节

3,指针一定要与指针指向的变量类型匹配，不然存储地址一点问题都没有，但读取数据会存在问题


4,指针一定要有指向，不知道指向哪里直接赋值为NULL


5,不允许将一个整数赋值给指针变量



   */
#if   0
int main()
{
		int a = 10;
		int *p=&a;
		printf("a=%d,*p=%d\n",a,*p);
		printf("&a=%p,p=%p\n",&a,p);
		printf("&p=%p\n",&p);
		return 0;
}
#endif

#if   0
int main()
{
		double a = 12.34;
		double *pa ;
		pa= &a;

		printf("a=%lf,*pa=%lf\n",a,*pa);
		printf("&a=%p,pa=%p\n",&a,pa);
		printf("&pa=%p\n",&pa);
		return 0;
}
#endif


#if   0
int main()
{
		printf("sizeof(int*)=%lu,sizeof(double*)=%lu,sizeof(char*)=%lu\n",\
						sizeof(int*),sizeof(double*),sizeof(char*));
		return 0;
}
#endif


#if   0
int main()
{
		int  a= 0x11223344;
		char *p = &a;
		printf("&a = %p,p=%p\n",&a,p);
		printf("a=%#x,*p=%#x\n",a,*p);

		return 0;
}
#endif


#if  0
int main()
{
		int a;
		int *p=NULL;
    	
		return 0;
}
#endif


int main()
{
		int *p = 10;
		*p = 100;
		return 0;
}
