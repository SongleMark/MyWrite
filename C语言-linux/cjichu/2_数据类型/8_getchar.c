#include <stdio.h>

/*
int main()
{
		char ch;
		ch=getchar();
		//printf("ch = %c\n",ch);
		putchar(ch);
		putchar('\n');
		return 0;
}
*/

/*

stdin:标准输入
stdout:标准输出
stderr:标准出错

清空缓冲区：
1,   getchar()

2,   setbuf(stdin,NULL)


   */
int main()
{
		char c1,c2,c3;

		c1 =  getchar();
		getchar();
		putchar(c1);
		c2 =  getchar();
		getchar();
		putchar(c2);
		c3 =  getchar();
		getchar();
		putchar(c3);
	    printf("c1=%c,c2=%c,c3=%c\n",c1,c2,c3)	;
		return 0;
}
