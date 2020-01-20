/*
   1,输入一个字符，判断是否是数字字符
#include<stdio.h>
int main()
{
		char c;
		int a;
		printf("输入一个字符：");
		scanf("%c",&c);
		a=c;
		if(a>'0'&&a<'9')
		{
				printf("%d是一个数字字符\n",a);
		}	
		else
		{
				printf("%d不是一个数字字符\n",a);
		} 

		return 0;
}		

 */

/*

   2,输入一个年份，判断是平年还是闰年
   润年条件，满足其中之一：
   （1）能被4整除，不能被100整除
   （2）能被400整除
#include<stdio.h>

int main()
{
		int  year;
		printf("请输入一个年份:");
		scanf("%d",&year);
		if((year%4==0&&year%100!=0)  || year%400==0)
		{
				printf("%d 是润年！\n",year);
		}
		else
		{
				printf("%d是平年！\n",year);
		}
		return 0;
}


*/


/*
   3,输入一个五位数整数，判断是否是回文数字
   12321      12345
*/

#include <stdio.h>

int main()
{
		int num,g,s,q,w;
		printf("请输入一个整数:");
		scanf("%d",&num);
		g = num%10;
		s = num/10%10;
		q = num/1000%10;
		w = num/10000;

		if(g==w &&s==q)
		{
				printf("%d是回文数字！\n",num);
		}
		else
		{
				printf("%d不是回文 数字！\n",num);
		}
		return 0;
}


/*
   4,输入三种商品的价格，如果有一种商品的价格大于50,或者总价大于100,则折扣率为3%，否则为0;
   输出最后总价

 */
