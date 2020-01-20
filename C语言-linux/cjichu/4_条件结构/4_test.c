#include <stdio.h>


/*

   1,C语言规定，每个 else 部分总属于前面最近的那个缺少对应的 else 部分的 if 语句


   2,提倡使用大括号括起来以避免看起来有二义性。

 */
int main()
{
		int x=0,y=0,z=0;
		if (x > 0)
		{
				if (y > 1) 
						z = 1;
		}
		else /*这个 else 部分属于哪个 if？*/
				z = 2; 

		printf("z = %d\n",z);
		return 0;
}
