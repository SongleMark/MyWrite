#include <stdio.h>

void GetSize(char array[100]);

int main()
{
	int x[100];

	int a = sizeof(x);
	int b = sizeof(x[100]);
	int c = sizeof(&x[0]);
	int d = sizeof(&x);

	printf("sizeof(x) = %d\n", a); //400 --- 4*100
	printf("sizeof(x[100]) = %d\n", b);//4 --- sizeof(int)
	printf("sizeof(&x[0]) = %d\n", c);//8 --- 64位指针大小
	printf("sizeof(&x) = %d\n", d);//8 --- 64位指针大小

	char *array;
	GetSize(array);
	return 0;
}

void GetSize(char array[100])
{
	int a = sizeof(array);
	int b = sizeof(array[100]);
	int c = sizeof(&array[0]);
	int d = sizeof(&array);

	printf("sizeof(array) = %d\n", a);// --- 8
	printf("sizeof(array[100]) = %d\n", b);// --- 1
	printf("sizeof(&array[0]) = %d\n", c);// --- 8
	printf("sizeof(&array) = %d\n", d);// --- 8
}
