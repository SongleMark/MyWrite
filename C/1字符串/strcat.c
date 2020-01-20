#include <stdio.h>
#include <string.h>

int Strlen(const char *str) {
	int i = 0;
	while('\0' != str[i]) {
		i ++;
	}
	
	return i;
}

void Strcat(char *dest, const char *src) {
	int len_dest = Strlen(dest);
	int i = 0;

	int j = len_dest;
	while('\0' != src[i]) {
		dest[j] = src[i];
		i ++;
		j ++;
	}
	dest[j] = '\0';
}

void Strncat(char *dest, const char *src, size_t n) {
	int len_src = Strlen(src);
	if(n >= len_src) {
		Strcat(dest, src);
		return ;
	}

	int i = 0;
	int j = Strlen(dest);
	while(('\0' != src[i]) && (i < n)) {
		dest[j] = src[i];
		j ++;
		i ++;
	}
	dest[j] = '\0';

}

int main(int argc, char *argv[]) {
	char dest[32];
	char src[32];

	printf("请输入原字符串:  ");
	scanf("%s", src);
	printf("请输入目标字符串:");
	scanf("%s", dest);

	//strcat
	Strcat(dest, src);
	printf("after strcat:\n");
	printf("src = %s, dest = %s\n", src, dest);

	//strncat
	size_t n;
	printf("请输入拼接的位数:");
	scanf("%lu", &n);
	Strncat(dest, src, n);
	printf("after strncat:\n");
	printf("src = %s, dest = %s\n", src, dest);


	return 0;
}
