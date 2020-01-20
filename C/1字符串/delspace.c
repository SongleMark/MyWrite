#include <stdio.h>

//求字符串长度
int Strlen(const char *str) {
	int length = 0;
	while('\0' != str[length]) {
		length ++;
	}

	return length;
}

//删除字符串所有空格
void DelSpaceFromString(char *str) {
	int i = 0;
	while('\0' != str[i]) {
		if(' ' == str[i]) {
			for(int j = i ; j < Strlen(str) ; j ++) {
				str[j] = str[j + 1];
			}
			continue;
		}
		i ++;
	}
}

int main(int argc, char *argv[]) {
	char str[32];
	printf("请输入一个带有空格的字符串:");
	fgets(str, 32, stdin);

	DelSpaceFromString(str);
	printf("调用删除空格函数后为:%s\n", str);

	return 0;
}
