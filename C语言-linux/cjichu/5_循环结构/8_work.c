/*
for:
3，从键盘输入一个整数n，求  1+1/2+1/3+....1/n的和
#include <stdio.h>


int main()
{
		int i=1,n;
		double sum = 0;
        printf("请输入一个整数：");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
		le(getchar(	sum +=(double)1/i;
		}
		printf("sum=%.2lf\n",sum);
		return 0;
}

*/


/*

4,从键盘输入一个整数n,求 1+1/（1+2）+ 1/（1+2+3）+...1/(1+2+3+...n)之和

#include <stdio.h>

int main()
{
		int i=1,n,sum1=0;
		double sum2 = 0;
		printf("请输入数据：");
		scanf("%d",&n);

		for(i=1;i<=n;i++)
		{
				sum1 += i;
				sum2 += 1.0/sum1;
		}
		printf("sum2=%.2lf\n",sum2);
		return 0;
}

*/
/*

5,输出1-100之间既能被3整除又能被5整除的所有整数


6,从键盘循环输入10个整数，统计1-10之间的个数，20-30之间的个数，30-40之间的个数，大于40的个数


7，假设m,n分别为整数，求m的n次方
*/

/*

嵌套循环：
1,从键盘输入任意个整数，0结束，输出该组数的平均数，如果输入y/Y继续求下一组整数的平均数，
如果输入n/N 程序结束

#include <stdio.h>

int main()
{
		int num,count=0;
		double sum=0;
		char ch;

		printf("是否进入循环?");
		ch=getchar();

		while(ch == 'y'||ch=='Y')
		{
				sum = 0,count = 0;
				printf("请输入一组数，0结束:");
				while(1)
				{   //  12 23   34   u  0
						scanf("%d",&num);
						while(getchar()!='\n');
						if(num == 0)
								break;
						sum += num;
						count ++;
				}
				printf("改组数的平均值：%.2lf\n",sum/count);

				printf("是否继续?");
				ch=getchar();
				while(getchar()!='\n');
		}
		return 0;
}


*/
/*
2,假设口袋有20元人民币，由1角、5角、1元组成，设计程序输出所有的组合方式
200  0  0 
0    40 0
0     0  20

 x  y   z
 x  +  5*y + 10*z == 200
 

#include<stdio.h>

int main()
{
		int jiao1,jiao5,yuan1,count=0;
		printf("1角\t5角\t1元\n");
		for(yuan1=0;yuan1<=20;yuan1++)
		{
				for(jiao5=0;jiao5<=40;jiao5++)
				{
						for(jiao1=0;jiao1<=200;jiao1++)
						{
								if(jiao1 + 5*jiao5 + 10*yuan1 == 200)
								{
										printf("%d\t%d\t%d\n",jiao1,jiao5,yuan1);
							            count++;
								}
						}
				}
		}
		printf("组合个数：%d\n",count);
		return 0;
}


 */

/*
3,
 *
 **
 ***
 ****
 *****

 1    1
 2    2
 3    3
 i    i
 

#include <stdio.h>

int main()
{
		int i,j;
		for(i=1;i<=5;i++)
		{
				for(j=1;j<=i;j++)
				{
						printf("*");
				}
				printf("\n");
		}
		return 0;
}

 */



/*

4,
 *****       
 ****
 ***
 **
 *
5
1     5
2     4
3     3
4     2
i     6-i


*/




/*
5,        
   *         
  ***       
 *****       
  ***         
   *      

i    j     k
1    2     1
2    1     3
3    0     5
i    3-i   2i-1


1    1      3
2    2      1
i    i      5-2*i
#include <stdio.h>

int main()
{
		int i,j,k;
		for(i=1;i<=3;i++)
		{
				for(j=1;j<=3-i;j++)
				{
						printf(" ");
				}
				for(k=1;k<=2*i-1;k++)
				{
						printf("*");
				}
				printf("\n");
		}


		for(i=1;i<=2;i++)
		{
				for(j=1;j<=i;j++)
				{
						printf(" ");
				}
				for(k=1;k<=5-2*i;k++)
				{
						printf("*");
				}
				printf("\n");
		}
		return 0;
}

*/


/*


 6,                         
 *           
 *.*.       
 *..*..*..
 *...*...*...*...
 *....*....*....*....*....
 *.....*.....*.....*.....*.....*.....

i     j     k
1     1     0
2     2     1
3     3     2
i     i     i-1
 */


#include <stdio.h>

int main()
{
		int i,j,k;
		for(i=1;i<=6;i++)
		{
				for(j=1;j<=i;j++)
				{
						printf("*");
						for(k=1;k<=i-1;k++)
						{
								printf(".");
						}
				}
				printf("\n");
		}
		return 0;
}
