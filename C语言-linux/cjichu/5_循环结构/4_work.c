/*
do_while:
1,  从键盘输入一个整数，输出该整数反转后的整数
1234 ==== >  4321
#include <stdio.h>

int main()
{
		int num,value=0;
		printf("请输入一个整数:");
		scanf("%d",&num);

		while(num)
		{
				value=value*10+num%10;
				num  /= 10;
		}
		printf("value = %d\n",value);
		return 0;
}


 */




/*
2,  修改学生管理系统，每次做完操作回到菜单，当选择输出0退出时，退出整个程序
*/

/*

3,  输出1-100之间所有5的倍数值，使用continue实现

#include <stdio.h>


int main()
{
		int i=1;
		do
		{
				if(i%5 != 0)
				{
						i++;
						continue;
				}
				printf("%d ",i);
				i++;
		}while(i<=100);
		printf("\n");
		return 0;
}

*/

/*
4,  从键盘输入一行字符序列，统计所有有效字符的个数(即回车键之前的所有字符个数)

*/

#include <stdio.h>


int main()
{
		char ch;
		int count = 0;
		printf("请输入一行字符序列：");
		do
		{
				ch = getchar();
				if(ch == '\n')
				{
						break;
				}
				count ++;
		}while(1);

		printf("count = %d\n",count);
		return 0;
}




