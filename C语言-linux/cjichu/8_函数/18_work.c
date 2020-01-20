/*

   1,设计函数，将所有成绩不及格的学生成绩加5分，并计算最终的平均值
     double function1(double a[],int n);
	 void  function2(double a[],int n,double *pave)

   2,设计函数，将低于平均成绩的成绩存放另一个数组，并返回低于平均成绩的人数
     int function2(double a[],int n,double b[]);
	 void  function2(double a[],int n,double b[],int *pcount);

   3,设计函数，统计任意字符序列的有效字符个数

   4,设计函数，求任意整型一维数组的最大值，最大值下标，最小值，最小值所在下标
    void  function4(int a[],int n,int *pmax,int *pmin,int *pmax_index,it *pmin_index)

   6,设计函数，将一个字符插入一组字符最大字符的后面
    void  function5(char a[],int n,char vaule)
 ps:
 函数定义 ------> test.c
 函数声明 ------> test.h

 测试文件  ----->main.c
*/

#include <stdio.h>
void  function1(double a[],int n,double *pave)
{
		int i;
		double sum=0;
		for(i=0;i<n;i++)
		{
				if(a[i]<60)
				{
						a[i]+=5;
				}
				sum +=  a[i];
		}
		*pave = (sum/n);
        return ;
}
	 

void  function2(double a[],int n,double b[],int *pcount)
{
		int i,j=0;
		double ave=0;
		for(i=0;i<n;i++)
		{
               ave += a[i];
		}
		ave  = ave/n;

		for(i=0;i<n;i++)
		{
				if(a[i]<ave)
				{
						b[j++]=a[i];
				}
		}

        *pcount = j;
		return;
}




void  function4(int a[],int n,int *pmax,int *pmin,int *pmax_index,int *pmin_index)
{
		int i,min=a[0],max=a[0],min_index=0,max_index=0;
		for(i=0;i<n;i++)
		{
				if(a[i]>max)
				{
						max = a[i];
						max_index = i;
				}
				if(a[i]<min)
				{
						min = a[i];
						min_index = i;
				}
		}
		*pmax = max;
		*pmin = min;
		*pmax_index = max_index;
		*pmin_index = min_index;
}
    

int function5(char a[],int n,char value)
{
	 int i;
     char max=a[0],max_index=0;
	 for(i=0;i<n;i++)
	 {
			 if(a[i]>max)
			 {
					 max = a[i];
					 max_index =i;
			 }
	 }

	 for(i=n-1;i>max_index;i--)
	 {
			 a[i+1]=a[i];
	 }


	 a[max_index+1]=value;
	 return n+1;
}


#if   0
int main()
{
		char a[128]={'a','z','x','w'};
		int ret=function5(a,4,'u');

		int  i;
		for(i=0;i<ret;i++)
		{
				printf("%c",a[i]);
		}
		printf("\n");
		return 0;

}
#endif



