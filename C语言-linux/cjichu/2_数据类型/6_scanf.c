#include <stdio.h>
/*
scanf语法：
scanf("格式说明符1  格式说明符2......"，&var1,&var2,......)
格式说明符和输入参数个数一致，并且一一对应


ps:
1,输入参数变量前一定要加&
2,如果获取多个数据，格式说明符放在一起，默认从键盘输入数据，以空白键分割，但如果中间
  有字符格式说明符，数据会出错，所以，如果有字符格式说明符的话，推荐每个格式说明符之间
  自己添加一个分割符，那么从键盘输入数据数据时，以自定义的分隔符分割每个数据
3,scanf不允许加'\n'
4,使用scanf之前带提示输入，调用完后清空缓冲区


   */
/*
int main()
{
		int a;
        printf("请输入一个整数：");
		scanf("%d",&a);
		printf("a = %d\n",a);
		return 0;
}
*/


/*
int main()
{
		int a;
		double b;
        char   c;
		printf("please  input data:");
		scanf("%d%c%lf",&a,&c,&b);

		printf("a = %d,b=%lf,c=%c\n",a,b,c);
		return 0;
}
*/


/*
int main()
{
		int a;
		double b;
		char c;
		printf("please  input data:");
		scanf("%d,%lf,%c",&a,&b,&c);
		printf("a = %d,b=%lf,c=%c\n",a,b,c);
		return 0;
}
*/



/*
int main()
{
		int a ;
		printf("please  input data:");
		scanf("%d\n",&a);//scanf加'\n'表示忽略空白字符
		printf("a = %d\n",a);
		return 0;
}


*/




int main()
{
		int a;
		printf("please input data:");
		scanf("a=%d",&a);
		printf("a=%d\n",a);
		return 0;
}
