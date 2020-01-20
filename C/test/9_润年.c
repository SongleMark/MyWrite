#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int year;
	printf("please input year:");
	scanf("%d", &year);
	getchar();

	if((0 == year%400) || (year%4 == 0 && year%100 != 0)) {
		printf("%d年是润年\n", year);
	}
	else {
		printf("%d年不是润年\n", year);
	}

	return 0;
}
