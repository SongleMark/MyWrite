#include <stdio.h>


int main()
{
		FILE *fp=NULL;
		//fp=fopen("a.txt","r+");
		//fp=fopen("a.txt","w+");
	    fp=fopen("a.txt","a");
	     
		if(fp == NULL)
		{
				printf("打开文件失败！\n");
				return -1;
		}
		printf("文件打开成功!\n");


		return 0;
}
