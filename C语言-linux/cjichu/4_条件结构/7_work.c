/*
   1,假设某饭店一周食谱如下：
   周一：佛跳枪
   周二：五谷
   周三：红烧肉
   周四：糖醋排骨
   周五：烤鸭
   周六：鸡排
   周日：牛排
   设计程序，当顾客输入周几（1--7）时，出现对应的特色菜
 */

/*
   2,输入月份，输出对应的季节
   1,2,3=====》春季
   4,5,6=====》夏季
   7,8,9=====》秋季
   10,11,12===》冬季
#include <stdio.h>

int main()
{
int month;
printf("请输入月份：");
scanf("%d",&month);

switch(month)
{
case 1:
case 2:
case 3:
printf("春\n");
break;
case 4:
case 5:
case 6:
printf("夏\n");
break;
case 7:
case 8:
case 9:
printf("秋\n");
break;
case 10:
case 11:
case 12:
printf("冬\n");
break;
default:
printf("输入有误！\n");
break;
}
return 0;
}

 */
/*


   3,输入年份和月份，输出该年该月对应的天数
   1 3 5 7 8 10  12  ===>31
   4  6 9 11   ==>30

   2

#include <stdio.h>

int main()
{
int year,month;
printf("请输入年份和月份:");
scanf("%d%d",&year,&month);

switch(month)
{
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
printf("31天\n");
break;

case 4:
case 6:
case 9:
case 11:
printf("30天\n");
break;
case 2:
if(year%4==0&&year%100!=0 || year%400==0)
{
printf("29天\n");
}
else
{
printf("28天\n");
}
break;
default:
printf("输入有误！\n");
break;
}
return 0;
}


 */


/*
   4,设计一个程序，实现简单的+ - × / %运算
   1+2  ======>  1+2=3
#include <stdio.h>


int main()
{
int num1,num2;
char ch;
printf("请输入一个式子：");
scanf("%d %c %d",&num1,&ch,&num2);

switch(ch)
{
case '+':
printf("%d + %d = %d\n",num1,num2,num1+num2);
break;
case '-':
printf("%d - %d = %d\n",num1,num2,num1-num2);
break;
case '*':
printf("%d * %d = %d\n",num1,num2,num1*num2);
break;
case '/':
printf("%d / %d = %.2lf\n",num1,num2,(double)num1/num2);
break;
case '%':
printf("%d %% %d = %d\n",num1,num2,num1%num2);
break;
default:
printf("输入有误!\n");
break;
}
return 0;
}

 */

/*
   5,设计一个学生管理系统（增、删、改、查、退出）
   设计菜单
 */


#include <stdio.h>

int main()
{
		int sel,flag=1;
		do
		{
				printf("\t\t学生管理系统\n");
				printf("\t1,添加学生信息\n");
				printf("\t2,删除学生信息\n");
				printf("\t3,修改学生信息\n");
				printf("\t4,查看学生信息\n");
				printf("\t0,退出\n");
				printf("\t请输入你的选择：");
				scanf("%d",&sel);
				switch(sel)
				{
						case 1:
								printf("添加学生成功！\n");
								break;
						case 2:
								printf("删除学生成功！\n");
								break;
						case 3:
								printf("修改学生成功！\n");
								break;
						case 4:
								printf("查看学生成功！\n");
								break;
						case 0:
								flag = 0;
								printf("退出成功！\n");
								break; 
						default:
								printf("选择有误！\n");
								break;
				}
		}while(flag);
		return 0;
}
