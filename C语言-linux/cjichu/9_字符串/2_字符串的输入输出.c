#include <stdio.h>

#if   0
int main()
{
		char name[32];

		printf("请输入姓名：");
		scanf("%s",name);

		printf("name:%s\n",name);
		return 0;
}
#endif


int main()
{
		char name[32];
		printf("请输入一个字符串:");
		gets(name);//  读取回车键，并转换成'\0'
        puts(name);//将 ‘\0’转换成'\n'输出
		//printf("name:%s",name);
		return 0;
}
