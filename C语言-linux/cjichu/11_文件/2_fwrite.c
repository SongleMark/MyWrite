#include <stdio.h>
//成功  0
//失败  -1
int   write_data(int a[],int n) 
{
		//1,打开文件
		FILE *fp=NULL;
		int ret;
		fp = fopen("a.txt","w+");
		if(fp == NULL)
		{
				printf("打开失败！\n");
				return -1;
		}

		//2,操作文件
		ret = fwrite(a,sizeof(int),n,fp);
		if(ret<n)
		{
				printf("写入出错！\n");
				fclose(fp);
				return -1;
		}
		fclose(fp);
		return 0;
}

int  main()
{
		int a[5]={1,2,3,4,5};
        write_data(a,5);
		return 0;
}
