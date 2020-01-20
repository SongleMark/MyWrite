#include <stdio.h>

int Strlen(const char *str) {
	int length = 0;
	while('\0' != str[length]) {
		length ++;
	}

	return length;
}

void ReverseString(char *str) {
	int len = Strlen(str);
	char temp;
	int i = 0;
	int j = len - 1;
	while(i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;

		i ++;
		j --;
	}
}

int main(int argc, char *argv[]) {
	char src[32];
	printf("please input src string:");
	scanf("%s", src);
	getchar();

	printf("before reverse ...\nsrc = %s\n", src);
	ReverseString(src);
	printf("after reverse ...\nsrc = %s\n", src);

	return 0;
}
