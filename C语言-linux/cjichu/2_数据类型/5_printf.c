#include <stdio.h>
/*

printf的用法：
1,printf("普通字符");
普通字符原样输出

2,printf(“普通字符  格式说明符1  格式说明符2  ......”,var1,var2.......);
格式说明符和输出列表变量个数一致，并且一一对应


ps:
1,双引号中以%开头的都是格式说明符，


   */

/*
int main()
{
		int num = 10;
		printf("hello world  num = %d\n",num);
		return 0;
}   
*/


//整型
/*

int ------>%d (%o  %x  %#o  %#x)

unsigned int   ----->  %u


long  int ------>%ld(%lo %lx)
unsigned  long  int  ----->  %lu



short  int  --->%hd (%ho  %hx)
unsigned  short  int ---->  %hu


int main()
{
		int num1 = 10,num2 = 20;
		printf("num1 = %d,num2 =%d\n",num1,num2);
	    //printf("num1 = 0%o,num2 = 0%o\n",num1,num2) ;
	    //printf("num1 = x%x,num2 = x%x\n",num1,num2) ;
	    printf("num1 = %#o,num2 = %#o\n",num1,num2) ;
	    printf("num1 = %#x,num2 = %#x\n",num1,num2) ;
		
		long  int a=10;
		printf("a = %ld,a = %lo,a=%lx\n",a,a,a);
		
        short  int b =20;
        printf("b = %hd,b=%ho,b=%hx\n",b,b,b);

		return 0;




}
   */


/*
//%3d    宽度为3  右对齐  不够位 左边补空格
// %-3d   宽度为3  左对齐  不够位  右边部空格
//  超出设置的宽度，则按照实际的宽度对齐
int main()
{
		int a = 1234,b=13;
		printf("%3d|%3d\n",a,b);
		return 0;
}
*/



/*
//浮点类型
//   float  ---->%f (%e)
//   double ---->%lf (%e)
int  main()
{
		float   a = 12.34;
		double  b = 56.786767676;
		printf("a = %f\n",a);//默认小数点后保留6位小数
		printf("b = %lf\n",b);
     
		printf("b = %.3lf\n",b);//有四舍五入
		printf("a = %.2e\n",a);
		printf("b = %e \n",b);
		return 0;
}
*/


/*
//字符类型
//   char   ----->%c  
int main()
{
		char  a = '0';
		printf("a=%d,a=%c\n",a,a);
		return 0;
}


*/



//其他
// 输出双引号       \"
// 输出一个百分号   %%
int main()
{
		printf("\"hello world\"\n");
        printf("%%100\n");

		printf("学号\t姓名\t成绩\n");
   		return 0;
}

