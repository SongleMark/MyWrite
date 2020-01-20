#include <stdio.h>
#include <string.h>

void ReverseString(char *str) {
	int i = 0;
	int len = strlen(str);
	char temp;
	for(int j = len - 1; i < j; i ++, j --) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

char *TransformIntToString(int number, char *str) {
	int i = 0;
	//char *str;
	while(number) {
		str[i] = number%10 + '\0';
		number = number/10;
		printf("str[%d] = %c\n", i, str[i]);
		i ++;
	}
	str[i] = '\0';
	//ReverseString(str);

	//return str;
}

int main(int argc, char *argv[]) {
	char str[12];
	printf("please input a string:");
	scanf("%s", str);
	getchar();

	ReverseString(str);
	printf("after reverse ...\nstring = %s\n", str);

	int number = 0;
	char ch[32];
	printf("please input a number:");
	scanf("%d", &number);
	getchar();
	TransformIntToString(number, ch);
	printf("string = %s, number = %d\n", ch, number);
	printf("after transform ...\nstring = %s\n", ch);

	return 0;
}
