#include <stdio.h>

int Strlen(const char *src) {
	int len = 0;
	while('\0' != src[len]) {
		len  ++;
	}

	return len;
}

void Strcpy(char *dest, const char *src) {
	int i = 0;
	while('\0' != src[i]) {
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
}

int main(int argc, char *argv[]) {
	char src[32];
	char dest[32];
	printf("please input src string:");
	scanf("%s", src);
	getchar();
	printf("please input dest string:");
	scanf("%s", dest);
	getchar();

	printf("src = %s, dest = %s\n", src, dest);
	Strcpy(dest, src);
	printf("after strcpy src = %s, dest = %s\n", src, dest);
	
	return 0;
}
