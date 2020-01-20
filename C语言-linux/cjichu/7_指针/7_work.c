/*
1,定义一个数组存储10个学生的成绩，数据从键盘输入，通过指针遍历数组，给不及格的学生+5分

#include <stdio.h>

int  main()
{
		double a[10];
		double *p = a;

		int i;
		for(i=0;i<10;i++)
		{
				printf("请输入第%d个元素的数据：",i+1);
				scanf("%lf",p+i);
		}


		while(p<a+10)
		{
				if(*p < 60)
				{
						(*p) += 5;
				}
				p ++;
		}

		for(p=&a[0],i=0;i<10;i++)
		{
				printf("%.2lf\t",p[i]);
		}
		printf("\n");
		return 0;
}


*/
/*
2,从键盘输入一行字符序列，判断是否是回文序列，指针实现
#include <stdio.h>

int main()
{
		char a[128],ch;
		int i=0;

		char *begin=NULL,*end=NULL;
		while((ch=getchar())!='\n')
		{
				a[i++]=ch;
		}

		for(begin=&a[0],end=&a[i-1];begin<end;begin++,end--)
		{
				if(*begin != *end)
						break;
		}

		if(begin < end)
		{
				printf("不是回文字符\n");
		}
		else
		{
				printf("是回文字符\n");
		}
		return 0;
}


*/

/*
3,从键盘输入10个学生的成绩，排序输出，指针实现
*/

#include <stdio.h>

int main()
{
		double a[10]={12,9,-100,8,100,2,3,-200,5,0};

		double *p= &a[0];
		int i,j,temp;

		for(i=0;i<9;i++)
		{
				for(j=0;j<9-i;j++)
				{
						if(p[j]>p[j+1])
						{
								temp = p[j];
								p[j]=p[j+1];
								p[j+1]=temp;
						}
				}
		}


		for(i=0;i<10;i++)
		{
				printf("%.2lf\t",p[i]);
		}
		printf("\n");
		return 0;
}


/*
4,从键盘输入一行字符序列，并存储，将该字符序列反转

*/



