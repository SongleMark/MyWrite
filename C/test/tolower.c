#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char a = 'A';
	printf("after tolower a = %c\n", tolower(a));

	char b[] = "AbCdEfG";
	printf("b = %s\n", b);

	int i = 0;
	while('\0' != b[i]) {
		b[i] = tolower(b[i]);
		i ++;
	}

	printf("after tolower b = %s\n", b);

	return 0;
}
