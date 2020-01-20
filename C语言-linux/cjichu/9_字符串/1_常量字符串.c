#include <stdio.h>

#if   0
int  main()
{
		char *p="hello xiaoqi";
        *p = 'H';
		printf("%s\n",p);
		return 0;
}
#endif


int main()
{
		char a[128]="hello";
        char b[] = "abcd";
        char zg[] ="中国";//  一个汉字3字节
		printf("a:%s\n",a);
		printf("b:%s\n",b);
        printf("sizeof(a)=%lu,sizeof(b)=%lu\n",sizeof(a),sizeof(b));
		printf("sizeof(zg)=%lu\n",sizeof(zg));
		return 0;
}
