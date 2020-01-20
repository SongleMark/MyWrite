#include <stdio.h>

//求字符串长度
int Strlen(const char *str) {
	int length = 0;
	while('\0' != str[length]) {
		length ++;
	}

	return length;
}

//反转
void ReverseString(char *str) {
	int i = 0;
	int j = Strlen(str) - 1;
	char temp;
	for( ; i < j ; i ++, j --) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

//整形转char *类型 -- 123--->"123"
void IntToString(int num, char *str) {
	int i = 0;
	while(0 != num) {
		str[i] = num%10 + '0';
		num /= 10;
		i ++;
	}//此时得到的字符串为数字的反向组合
	str[i] = '\0';
	ReverseString(str);//将得到的字符串反转
}

int main(int argc, char *argv[]) {
	int num;
	char str[32];
	printf("请输入一串数字:");
	scanf("%d", &num);
	
	IntToString(num, str);
	printf("after use IntToString(), str = %s\n", str);

	return 0;
}
