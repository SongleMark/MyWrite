/*
0,定义一个字符类型的变量，并保存该变量的地址
  打印该变量的地址
  打印该变量的内容
  打印指针变量的地址
   
   
1,编写程序，实现用指针来求两个单精度浮点数的平均值，数据从键盘输入

#include <stdio.h>

int main()
{
		float a1,a2;
		float *p1=&a1,*p2=&a2;
		printf("请输入数据：");
		scanf("%f%f",p1,p2);

		printf("ave=%.2f\n",(*p1+*p2)/2);
		return 0;
}
*/


/*

2,编写程序，实现用指针来交换两个整型变量的值

#include <stdio.h>
int main()
{
		int a=1,b=3,temp;
		int *pa=&a,*pb = &b;
        

		temp = *pa;
		*pa = *pb;
		*pb = temp;

		printf("a =%d,b=%d\n",a,b);

		return 0;
}

*/

/*
3,编写程序，实现用指针将三个整型变量的值按从小到大排列
   */


#include <stdio.h>
int main()
{
		int a =3,b=0,c=-9,temp;
		int *pa=NULL,*pb=NULL,*pc=NULL;
		pa = &a,pb=&b,pc=&c;

		if(*pa>*pb)
		{
              temp = *pa;
			  *pa = *pb;
			  *pb = temp;
		}

		if(*pa >*pc)
		{
				temp = *pa;
				*pa = *pc;
				*pc = temp;
		}

		if(*pb>*pc)
		{
				temp = *pb;
				*pb = *pc;
				*pc = temp;
		}

		printf("a = %d,b=%d,c=%d\n",a,b,c);
		return 0;

}




