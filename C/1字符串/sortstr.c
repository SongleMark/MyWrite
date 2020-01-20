#include <stdio.h>

//自定义的求字符串长度函数
int Strlen(const char *str) {
	int length = 0;
	while('\0' != str[length]) {
		length ++;
	}

	return length;
}

//从小到大冒泡排序
void SortString(char *str) {
	int length = Strlen(str);
	char temp;
	for(int i = 0 ; i < length - 1 ; i ++) {
		for(int j = 0 ; j < length - i - 1 ; j ++) {
			if(str[j] > str[j + 1]) {
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}


int main(int argc, char *argv[]) {
	char str[32];
	printf("请输入一个字符串:");
	scanf("%s", str);
	SortString(str);
	printf("从小到大排序后结果:%s\n", str);

	return 0;
}
