#include <stdio.h>
#include <string.h>

int Strlen(const char *src) {
	int len = 0;
	while('\0' != src[len]) {
		len ++;
	}

	return len;
}

void Strcat(char *dest, const char *src) {
	int len = 0;
	int i = 0;
	len = Strlen(dest);
	int j = len;
	while('\0' != src[i]) {
		dest[j] = src[i];
		j ++;
		i ++;
	}
	dest[j] = '\0';

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
	Strcat(dest, src);
	printf("after strcat src = %s, dest = %s\n", src, dest);
	return 0;
}
