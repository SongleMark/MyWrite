#include <stdio.h>
/*
1,结构体成员按照自己的字节数对齐
2,最后总的字节数是最大字节数的整数倍


   */


struct s1
{
		char a;
		short int b;
		long double c;
		char d;
		int e;
		int  f
};


struct s2
{
		char a;
		double c;
		short int b;
};



int main()
{
		printf("sizeof(long double)=%lu\n",sizeof(long double));
		printf("sizeof(struct s1)=%lu\n",sizeof(struct s1));
		printf("sizeof(struct s2)=%lu\n",sizeof(struct s2));

		struct s1  s;
        printf("&s.a = %p\n",&s.a);
		printf("&s.b = %p\n",&s.b);
		printf("&s.c = %p\n",&s.c);

		return 0;
}
