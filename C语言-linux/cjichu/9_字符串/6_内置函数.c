#include <stdio.h>
#include <string.h>

#if   0
//strlen()
int main()
{
//		char a[128]="hello";

		char  a[]="hello";
		printf("strlen(a):%lu\n",strlen(a+2));//计算字符串的大小  不包含'\0'   5
		printf("sizeof(a):%lu\n",sizeof(a));// 计算数组的大小   128  
		return 0;
}
#endif

#if   0
//strcpy
int main()
{
		char src[128],dest[128]="sxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

		printf("请输入源字符串:");
		scanf("%s",src);//hello

        strcpy(dest,src+2);//将'\0'一起拷贝过去


		printf("src:%s\ndest:%s\n",src,dest);
		return 0;
}
#endif



#if   0
//strcat   
int main()
{
		char src[128]=" world",dest[128]="hello";


		strcat(dest,src);//  ‘\0’一起追加过来

		printf("src:%s\n,dest:%s\n",src,dest);
		return 0;
}
#endif




#if   0
int main()
{
		char s1[128],s2[128];
        int ret;

		printf("请输入两个字符串:\n");
		gets(s1);
		gets(s2);

        ret = strcmp(s1,s2);

		if(ret==0)
		{
				printf("s1 == s2,re=%d\n",ret);
		}
		else if(ret<0)
		{
				printf("s1 <s2,ret=%d\n",ret);
		}
		else if(ret>0)
		{
				printf("s1>s2,ret =%d\n",ret);
		}
		return 0;
}

#endif



#if   0
strcmp(s1,s2)

int main()
{
		//  xiaoqi     123456
		char name[128],pass[128];
        printf("请输入帐号：");
		scanf("%s",name);
		getchar();
		printf("请输入密码：");
		scanf("%s",pass);
		getchar();

		if(0==strcmp(name,"xiaoqi")  &&  0==strcmp(pass,"123456")) 
		{
				printf("登录成功！\n");
		}
		else
		{
				printf("帐号密码不匹配\n");
		}
		return 0;
}

#endif


int main()
{
		int a[5]={1,2,3,4,5};
		int b[5]={0},i;

		memcpy(b,a,sizeof(a));

		memset(b,0,sizeof(b));

		for(i=0;i<5;i++)
		{
				printf("%d ",b[i]);
		}
		printf("\n");
		return 0;
}
