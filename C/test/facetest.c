#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Getmemory() {
	char p[] = "hello, world!!!";

	return p;
}

int main(int argc, char *argv[]) {
	char *str = (char *)malloc(100);
	strcpy(str, "hello");
	//free(str);
	if(NULL != str) {
		strcpy(str, "world");
		printf("str = %s\n", str);
	}

	char *ch = NULL;
	ch = Getmemory();
	printf("ch = %s\n", ch);

	return 0;
}

