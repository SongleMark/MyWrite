/*
1,从键盘输入一个整数判断是奇数还是偶数
#include <stdio.h>

int main()
{
		int num;
		printf("请输入一个整数:");
		scanf("%d",&num);

		if(num%2 == 0)
		{
				printf("%d是偶数！\n",num);
		}
		else
		{
				printf("%d是奇数！\n",num);
		}
		return 0;
}

*/


/*
2,从键盘输入两个字符，判断两个字符距离是否大于10
#include <stdio.h>
#include <stdlib.h>
int main()
{
		char c1,c2;
		int dis=0;
		printf("please input data:");
		scanf("%c,%c",&c1,&c2);
#if  0	
  		if(c1>c2)
		{
				dis=c1-c2;
		}
		else
		{
				dis=c2-c1;
		}
#endif
		dis=abs(c1-c2);
		if(dis>10)
		{
				printf("距离大于10\n");
		}
		else
		{
				printf("小于10\n");
		}

		return 0;
}


*/
/*
3,从键盘输入一个整数，判断个位是否为3
*/


/*
4,从键盘输入三种水果的价格，如果总价大于50,就打88折，否则不打折，输出最后总价
#include <stdio.h>

int main()
{
		double p1,p2,p3,p;
		printf("请输入三种水果的价格：");
		scanf("%lf%lf%lf",&p1,&p2,&p3);

		p = p1+p2+p3;

		if(p>50)
		{
				p*=0.88;
		}
		printf("%.2lf\n",p);
		return 0;
}

*/

/*
5,从键盘输入两个整数分别保存在变量a,b里，实现a是最大值，b是最小值
#include <stdio.h>

int main()
{
		int a,b,temp;
		printf("请输入数据：");
		scanf("%d%d",&a,&b);

		if(a<b)
		{
				temp = a;
				a = b;
				b = temp;
		}

		printf("a = %d,b=%d\n",a,b);
		return 0;
}
*/

/*
6,从键盘输入三个整数分别保存在变量a,b,c里，实现a是最大值，b是中间值，C 是最小值

   */



#include <stdio.h>

int main()
{
		int a,b,c,temp;
		printf("请输入数据：");
		scanf("%d%d%d",&a,&b,&c);

		if(a<b)
		{
				temp=a;
				a = b;
				b = temp;
		}
		if(a<c)
		{
				temp=a;
				a = c;
				c = temp;
		}

		if(b<c)
		{
				temp = b;
				b = c;
				c = temp;
		}

		printf("a=%d,b=%d,c=%d\n",a,b,c);
		return 0;
}
