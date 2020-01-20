/*
1,从键盘输入5个学生的成绩，排序输出前三名和后三名



2,从键盘输入一行字符序列，按照从小到大的顺序排序，并输出
#include <stdio.h>

int main()
{
		char a[128],ch;
		int i = 0,j,k;
		while((ch=getchar())!='\n')
		{
				a[i++] = ch;
		}

		for(j=0;j<i-1;j++)
		{
				for(k=0;k<i-1-j;k++)
				{
						if(a[k]>a[k+1])
						{
								ch=a[k];
								a[k]=a[k+1];
								a[k+1]=ch;
						}
				}
		}

		for(j=0;j<i;j++)
		{
		    printf("%c",a[j]);
		}
		printf("\n");

		return 0;
}

*/
/*

3,从键盘输入一行字符序列判断是否是回文字符
assa
asdsa

   */

#include <stdio.h>

int  main()
{
		char a[128],ch;
		int i=0;
        int begin,end;
		while((ch=getchar())!='\n')
		{
				a[i++]=ch;
		}

        
		for(begin = 0,end=i-1;begin<end;begin++,end--)
		{
				if(a[begin]!=a[end])
						break;
		}

		
		if(begin<end)
		{
				printf("不是回文字符\n");
		}
		else
		{
				printf("是回文字符\n");
		}

		return 0;
}
