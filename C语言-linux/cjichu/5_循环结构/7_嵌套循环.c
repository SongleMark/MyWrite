#include <stdio.h>
//嵌套循环：  外层循环一次，内层循环一个周期
//  break:

int main()
{
		int i,j;
		for(i=1;i<=3;i++)
		{
				j=1;
				while(j<=5)
				{
#if  0
						//嵌套循环中，break只能跳出其所在的一层循环
						if(j== 3)
						{
								break;
						}
#endif
						if(j%2 == 0)
						{
								j++;
								continue;
						}
						printf("i=%d,j=%d\n",i,j);
						j ++;
				}
#if  0
				for(j=1;j<=5;j++)
				{
						printf("i=%d,j=%d\n",i,j);
				}
#endif
		}
		return 0;
}
