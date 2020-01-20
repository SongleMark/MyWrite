#include <stdio.h>
/*
/:

1,两个整数相除，结果一定是整数，如果有小数部分，小数点后直接截尾，并且没有四舍五入
2,如果有一个是浮点类型的，结果就是浮点类型


自动类型转换：
场合：  1）赋值    2）不同类型运算
1,范围小的转换成范围大的一定问题都没有
  范围大的转换成范围小的有可能导致数据丢失
2,不同类型运算时，范围小的自动转换成范围大的

强制类型转换：
(新的类型)变量或常量




%:
1,必须两个操作数是整数
2,结果符号和左操作数保持一致
   */
/*
//    /
int  main()
{
		int a,b;
		printf("%d / %d = %d\n",6,8,6/8);
		printf("%d / %f = %lf\n",6,8.0,6/8.0);
		printf("%f / %d = %lf\n",6.0,8,6.0/8);
		printf("%lf / %lf = %lf\n",6.0,8.0,6.0/8.0);
		return 0;
}
*/



/*
int main()
{
		int a =12;
		double b;
		b = a;
		printf("a = %d ,b=%lf\n",a,b);
		return 0;
}
*/


/*
int main()
{
		int a = 0x11223344;
		char b ;
		b = (char)a;
		printf("a=%#x,b=%#x\n",a,b); 
		return 0;
}
*/


/*
int main()
{
		int a=6,b=8;
		
		printf("%d %% %d = %d\n",6,8,6%8);
		printf("%d %% %d = %d\n",-6,8,-6%8);
		printf("%d %% %d = %d\n",6,-8,6% -8);
		printf("%d %% %d = %d\n",-6,-8,-6%-8);
		return 0;
}
*/


// ++   --
/*
int main()
{
		int a = 2,b=0;
//		++a; // 前置++  a = a+1
//	    b=++a;//  a=a+1   b=a;
//		printf("a = %d,b=%d\n",a,b);
//        a++;  //后置++++

         b= a++;// b=a,a=a+1
		 printf("a =%d,b=%d\n",a,b);
		return 0;
}
*/

int main()
{
		int a =1,b=0;
//		b=--a;// a=a-1   b=a
  //      printf("a = %d,b=%d\n",a,b);
     	b=a --;//b=a,a= a-1
       printf("a = %d,b=%d\n",a,b);
		return 0;
}





