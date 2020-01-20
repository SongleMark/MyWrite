#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Strlen(const char *str) {
	int i = 0;
	while('\0' != str[i]) {
		i ++;
	}

	return i;
}

int Strcmp(const char *s1, const char *s2) {
	int i = 0;

	while(('\0' != s1[i]) || ('\0' != s2[i])) {
		if(s1[i] > s2[i]) {
			return 1;
		}
		else if(s1[i] < s2[i]) {
			return -1;
		}
		i ++;
	}

	return 0;
}

int Strncmp(const char *s1, const char *s2, size_t n) {
	int i = 0;
	while(i < n) {
		if(s1[i] > s2[i]) {
			return 1;
		}
		else if(s1[i] < s2[i]) {
			return -1;
		}

		i ++;
	}

	return 0;
}

int main(int argc, char *argv[]) {
	char s1[32];
	char s2[32];
	
	printf("请输入s1:");
	scanf("%s", s1);
	printf("请输入s2:");
	scanf("%s", s2);

	//strcmp
	if(0 == Strcmp(s1, s2)) {
		printf("二者相等\n");
	}
	else if(1 == Strcmp(s1, s2)) {
		printf("s1大于s2\n");
	}
	else {
		printf("s1小于s2\n");
	}

	//strncmp
	size_t n;
	printf("请输入比较的位数:");
	scanf("%lu", &n);
	if(0 == Strncmp(s1, s2, n)) {
		printf("比较%lu位时, 二者相等\n", n);
	}
	else if(1 == Strncmp(s1, s2, n)) {
		printf("比较%lu位时, s1大于s2\n", n);
	}
	else {
		printf("比较%lu位时, s1小于s2\n", n);
	}
	
	return 0;
}
