#include <stdio.h>
#include <stdlib.h>

int Strlen(const char *str) {
	int length = 0;
	while('\0' != str[length]) {
		length ++;
	}

	return length;
}

void ReverseString(char *str) {
	int i = 0;
	int length = Strlen(str);
	int j = length - 1;
	char temp;
	for( ; i < j ; i ++, j --) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

int main(int argc, char *argv[]) {
	char str[32];
	printf("请输入一串字符:");
	scanf("%s", str);
	ReverseString(str);
	printf("反转后为: %s\n", str);
	return 0;
}
