#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	int temp;
	int max;

	printf("请输入两个数:");
	scanf("%d,%d", &a, &b);
	if(a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	
	max = a * b;
	c = a%b;
	while(0 != c) {
		a = b;
		b = c;
		c = a%b;
	}
	printf("最大公约数是%d\n", b);
	printf("最小公倍数是%d\n", max/b);

	return 0;
}

