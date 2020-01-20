/*

1，定义一个数组，存储10个学生的成绩，分别使用初始化、赋值、动态输入获取数据，
   输出每个学生的成绩，并输出平均数


2,定义一个数组，存储5中商品的价格，数据初始化，输出每种商品的价格

*/
/*

3,定义一个数组，存储10个整型数据，输出该组数的最大值
max=a[0]


#include <stdio.h>
int main()
{
		int a[10]={12,0,-1,99,55,6,1,2,-100,200};
		int max=a[0],max_index=0,i;
		for(i=1;i<10;i++)
		{
				if(a[i]>max)
				{
						max=a[i];
						max_index= i;
				}
		}
		printf("max:%d,max_index=%d\n",max,max_index);

		return 0;
}

*/

/*

4,定义一个数组，存储6个不同整型的数据，输出最小数的下标


5,输入年月日，输出该月改日是该年的第几天
   比如：1月1日  是 第一天
   */

#include <stdio.h>


int main()
{
		int year,month,day;
		int sum = 0,i;
		int days[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
		printf("请输入日期(yy/mm/dd)：");
		scanf("%d/%d/%d",&year,&month,&day);

		if(year%4==0&&year%100!=0|| year%400==0)
		{
				days[2]=29;
		}
		else
		{
				days[2]=28;
		}

		for(i=0;i<month;i++)
		{
				sum += days[i];
		}
		sum += day;

		printf("%d月%d日是%d年的第%d天\n",month,day,year,sum);
		return 0;

}





