/*

1,1-10之间所有整数的平方跟和立方
sqrt(10)   pow(10,3)
*/
/*
2,产生7个1-31之间的随机数，不允许重复
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
		int a[7],i,j;
		srand(time(NULL));

		for(i=0;i<7;i++)
		{
				a[i] = rand()%31+1;
				for(j=0;j<i;j++)
				{
						if(a[i]==a[j])
						{
								i--;
								break;
						}
				}
		}

		for(i=0;i<7;i++)
		{
				printf("%d\t",a[i]);
		}
		printf("\n");
		return 0;
}


*/
/*

4,分别产生 3个 a-z ,3个 A-Z,  3个0-9,并输出
      97-122         65-90      48-57
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
		char a[9],ch;
        int  i,j=0;
		srand(time(NULL));

		for(i=0;i<3;i++)
		{
				ch=rand()%123;
				if(ch>=97 && ch<=122)
				{
						a[j++]=ch;
				}
				else
				{
						i--;
				}
				
		}
		for(i=0;i<3;i++)
		{
				ch=rand()%91;
				if(ch>=65 && ch<=90)
				{
						a[j++]=ch;
				}
				else
				{
						i--;
				}
		}		
		for(i=0;i<3;i++)
		{
				ch=rand()%58;
				if(ch>=48 && ch<=57)
				{
						a[j++]=ch;
				}
				else
				{
						i--;
				}
		}		
		
		
		for(i=0;i<9;i++)
		{
				printf("%c",a[i]);
		}
		printf("\n");
		
		return 0;
}




/*
5,整数的绝对值


6,浮点数的绝对值


   */
