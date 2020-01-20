/*
1,打印1-100之间所有整数，一行打印10个数，并且右对齐
#include <stdio.h>

int main()
{
		int i=1;
		while(i<=100)
		{
				printf("%3d ",i);
				if(i%10  == 0)
				{
						printf("\n");
				}
				i++;
		}
		return 0;
}

*/

/*
2,从键盘输入一行字符，统计空格字符的个数
*/
#include <stdio.h>
#if   0
int main()
{
        int count=0;
		char ch;
        ch = getchar();
		while(ch !='\n')
		{
				if(ch == ' ')
				{
						count++;
				}
				ch = getchar();
		}
		printf("count=%d\n",count);
		return 0;
}


int main()
{
		int  count=0;
		char ch;

		while((ch=getchar())!='\n')
		{
				if(ch == ' ')
				{
						count ++;
				}
		}
		printf("count = %d\n",count);
		return 0;
}


int main()
{
		int count=0;
		char ch;
		while(1)
		{
				ch=getchar();
				if(ch == '\n')
				{
						break;
				}
				if(ch == ' ')
				{
						count++;
				}
		}
		printf("count=%d\n",count);
		return 0;

}

#endif

/*
3，输出1——100之间所有奇数之和


#include <stdio.h>

int main()
{
		int i=1,sum=0;
#if  0
		while(i<=100)
		{
             if(i%2 != 0)
			 {
					 sum += i;
			 }
			 i ++;
		}
#endif

		while(i<=100)
		{
				sum += i;
				i += 2;
		}
		printf("sum = %d\n",sum);
		return 0;
}

*/

/*

4,输入任意一个整数，输出该整数反转后的结果
1234  =======》4321
1200  =======》0021
#include <stdio.h>
int main()
{
		int num;
		printf("请输入一个整数：");
		scanf("%d",&num);

		while(num)
		{
				printf("%d",num%10);
				num /= 10;
		}
		printf("\n");
		return 0;
}

*/

/*

5,
一框鸡蛋：
1个1个拿，刚好拿完
2个2个拿，还剩1个
3个3个拿，刚好拿完
4个4个拿，还剩1个
5个5个拿，还差1个
6个6个拿，还剩3个
7个7个拿，刚好拿完
8个8个拿，还剩1个
9个9个拿，刚好拿完
问：框里至少有几个鸡蛋？

#include <stdio.h>

int main()
{
		int num=1;

		while(1)
		{
				if(num%2==1 && num%3==0 && num%4==1 && num%5==4 
								&& num%6==3 && num%7==0 && num%8==1 &&num%9==0)
				{
						break;
				}
				num ++;
		}
		printf("num = %d\n",num);
		return 0;
}

*/

/*

6,从键盘输入一行字符序列，统计小写字符，大写字符、控制字符、数字字符、其他字符分别出现的次数
#include <stdio.h>

int main()
{
		char ch;
		int c1=0,c2=0,c3=0,c4=0,c5=0;
		printf("请输入一行字符:");

		while((ch=getchar())!='\n')
		{
				if(ch>='a'&&ch<='z')
				{
						c1 ++;
				}
				else if(ch>='A'&&ch<='Z')
				{
						c2++;
				}
				else if(ch>=0 &&ch<=31 ||ch == 127)
				{
						c3++;
				}
				else if(ch>='0'&&ch<='9')
				{
						c4++;
				}
				else
				{
						c5++;
				}
		}
		printf("c1=%d,c2=%d,c3=%d,c4=%d,c5=%d\n",c1,c2,c3,c4,c5);
		return 0;
}


*/

/*

7,输出所有可见字符的asccii码（十进制、八进制、十六进制、对应字符）
#include <stdio.h>

int main()
{
		char a = 32;
		printf("十进制\t八进制\t十六进制\t字符\n");
		while(a<=126)
		{
				printf("%d\t%#o\t%#X\t\t%c\n",a,a,a,a);
				a++;
		}
		return 0;
}

*/

/*

8,输出1-1000之间所有的水仙花数
水仙花数：个位的3次幂+十位的3次幂+百位的3次幂正好等于该数本身
   */
#include <stdio.h>

int main()
{
		int i=100;
		int g,s,b;
		while(i<1000)
		{
				g = i%10;
				s = i/10%10;
				b = i/100;
				if(g*g*g+s*s*s+b*b*b == i)
				{
						printf("%d\t",i);
				}
				i++;
		}
		printf("\n");
		return 0;
}
