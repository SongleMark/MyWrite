#include <stdio.h>
#if  0
//清空缓冲区
int  main()
{
		int num;
		char ch;
		printf("请输入一个整数：");
		scanf("%d",&num);
//		while(getchar()!='\n');
        setbuf(stdin,NULL);
		printf("请输入一个字符：");
		scanf("%c",&ch);
		while(getchar()!='\n');
        printf("num=%d,ch=%c\n",num,ch);
		
		return 0;
}
#endif

#if   0
int main()
{
		int num,re;
		printf("请输入一个整数：");
		while(0==scanf("%d",&num))
		{
		      while(getchar()!='\n');
			  printf("输入数据有误，请重新输入：");
			
		}
//		printf("re = %d\n",re);

		printf("num = %d\n",num);
		return 0;
}
#endif


int main()
{
		int re=printf("hello world");
		printf("re=%d\n",re);
		return 0;
}

