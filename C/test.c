#include <stdio.h>

int main(int argc, char *argv[]) {
	int x = 5;
	int y = 6;
	printf("x = %d, y = %d\n", x, y);
	int temp = x ^ y;
	x = temp ^ x;
	y = temp ^ y;
	printf("x = %d, y = %d\n", x, y);

	return 0;
}
