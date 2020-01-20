#include <stdio.h>

/*

数组指针：保存数组的起始地址

数据类型 (*指针变量)[元素个数]

   */
int main()
{
		double a[10]={1,2,3,4,5,6,7,8,9,10};
        double (*p)[10]=NULL;
		p = &a;
        int i;
        for(i=0;i<10;i++)
		{
//				printf("%lf\t",*(*p+i));
                printf("%lf\t",*(p[0]+i));
		}
		printf("\n");
		return 0;
}
