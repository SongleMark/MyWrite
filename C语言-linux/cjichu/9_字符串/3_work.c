/*

   1,从键盘输入微信昵称  和密码   并输出



   2,从键盘输入部门名称 和 负责人  并输出

#include <stdio.h>

int main()
{
char aprt[128],name[128];

printf("请输入部门名称：");
scanf("%s",aprt);
setbuf(stdin,NULL);

printf("请输入负责人:");
scanf("%s",name);
while(getchar()!='\n');

printf("部门:%s\n",aprt);
printf("负责人:%s\n",name);
return 0;
}

 */

/*

   3,从键盘输入某学生的基本信息，并输出

   学号
   姓名
   性别
   年龄
   成绩
   家庭住址
 */

#if    0
#include <stdio.h>

int main()
{
		int num,age;
		char name[32],sex[5],addr[64];

		printf("请输入学号：");
		scanf("%d",&num);
		setbuf(stdin,NULL);
		printf("请输入年龄：");
		scanf("%d",&age);
		setbuf(stdin,NULL);
		printf("请输入姓名：");
		scanf("%s",name);
		setbuf(stdin,NULL);
		printf("请输入性别：");
		scanf("%s",sex);
		setbuf(stdin,NULL);
		printf("请输入家庭住址：");
		scanf("%s",addr);
		setbuf(stdin,NULL);




		printf("num:%d,age:%d\n",num,age);
		printf("sex:%s,name:%s,addr:%s\n",sex,name,addr);


		return 0;
}

#endif

/*
   4,从键盘输入一行字符串，设计一个函数，计算字符串的字符个数

#include <stdio.h>

int function4(char *a)
{
int i=0;
while(a[i]!='\0')
{
i++;
}
return  i;
}

int main()
{
char a[3];
printf("请输入一行字符串：");
//gets(a);
fgets(a,3,stdin);
//        int ret=function4(a);
printf("a:%s\n",a);
return 0;
}

 */




/*


   5,设计函数，如下标为奇数的元素有对应的大写则转换成对应的大写，否则原样保存
 */

void  function5(char a[])
{
		int i=0;
		while(a[i]!='\0')
		{
				if(i%2 !=0)
				{
						if(a[i]>='a'&&a[i]<='z')
						{
								a[i]-=32;
						}
				}
				i++;
		}
}





