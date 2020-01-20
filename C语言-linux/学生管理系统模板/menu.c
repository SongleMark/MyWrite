#include "public.h"
#include "menu.h"
#include "student.h"

void menu(int len)
{
	printf("1 用户注册\n");
	printf("2 用户登录\n");
	printf("3 用户退出\n");
	
	int iNum;
	printf("Please input your choice:\n");
	scanf("%d",&iNum);
	switch(iNum)
	{
		//注册
		case 1:
   	 		len = fun_stuRegister(len);
			writeFile(len);
			display(len);
			break;
		//登录
		case 2:
			stuLogin();
			break;
		//退出
		case 3:
			exit(0);
			break;
		default:
			printf("Input Error\n");
			break;
	}
}

int fun_stuRegister(int len)
{
	if(len == 0)
	{
		array[len].id = 10001;
	
	}
	else
	{
		array[len].id = array[len-1].id+1;

	}

	printf("Please input your name:\n");
	scanf("%s",&array[len].caName);
	printf("Please input your passwd:\n");
	scanf("%s",&array[len].caPwd);
	array[len].fChinese = 0;
	array[len].fMath = 0;
	array[len].fEnglish = 0;
	len++;
	return len;
}

void writeFile(int len)
{
	//以只写方式打开文件
	FILE *fp = fopen("student.txt","w");
	if(fp = NULL)
	{
		printf("open failed\n");
		return;

	}
	fwrite(array,sizeof(struct student),len,fp);
	fclse(fp);
	return ;
}

int readFile()
{
	FILE *fp = fopen("student.txt","r");
	if(fp == NULL)
	{
		return 0;
	}
	int len = 0;
	while(fread(&array[len],sizeof(struct student),
		1,fp)>0)//读取文件成功
	{
		len++;

	}
	fclose(fp);
	return len;

}

void display(int len)
{
	for(int i=0; i<len; i++)
	{
		printf("%d\t%s\t%.2f\t%.2f\t%.2f\t",
			array[i].iId,array[i].caName,
			array[i].fChinese,array[i].fMath,
			array[i].fEnglish);

	}


}
