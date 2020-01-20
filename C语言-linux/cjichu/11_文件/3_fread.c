#include <stdio.h>
#include <string.h>
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
		//3,关闭文件
		fclose(fp);
		return 0;
}

//失败  ：-1
//成功  ：读取的 数据个数
int read_data(int a[],int n)
{
	  FILE *fp=NULL;
	  fp = fopen("a.txt","r+");
      int temp,i = 0,ret;
	  if(fp==NULL)
	  {
			  printf("打开文件失败！\n");
			  return -1;
	  }

	  while(1)
	  {
			  ret=fread(&temp,sizeof(int),1,fp);
			  if(ret == 0)
					  break;
			  a[i++] = temp;
	  }

	  fclose(fp);
	  return i;
}


int  main()
{
		int a[100];
        memset(a,0,sizeof(a));
        int ret=read_data(a,100);

		if(ret <0)
		{
				printf("读取出错！\n");
				return -1;
		}
		int  i;
		for(i=0;i<ret;i++)
		{
				printf("%d\t",a[i]);
		}
		printf("\n");
		return 0;
}
