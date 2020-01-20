#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/********************************************************************
 *strcpy(char *dest, const char *src)函数：
 *dest和src需要有空间，即dest和src需要是字符串数组或者动态分配了空间
 ********************************************************************/
void Strcpy(char *dest, const char *src) {	
	int length = 0;
	int i = 0;
	length = strlen(src);
	
	while('\0' != src[i]) {		
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
}

void Strncpy(char *dest, const char *src, size_t n) {
	int length = strlen(src);
	if(n >= length) {
		Strcpy(dest, src);
		return ;
	}
	
	int i = 0;
	while(('\0' != src[i]) && (i < n)) {
		dest[i] = src[i];
		i ++;
	}
	dest[n] = '\0';
}

int main(int argc, char *argv[]) {
//[情况一:(对于字符串数组)]
	char dest1[32];
	char src1[32];
	int n;
	printf("请输入原字符串: ");
	scanf("%s", src1);
	printf("请输入目标字符串:");
	scanf("%s", dest1);

	//strcpy
	Strcpy(dest1, src1);
	printf("after strcpy 情况一: \n");
	printf("dest1 string = %s, src1 string = %s\n", dest1, src1);
	//strncpy
	printf("请输入要赋值的位数:");
	scanf("%d", &n);
	Strncpy(dest1, src1, n);
	printf("after strncpy 情况一: \n");
	printf("dest1 string = %s, src1 string = %s\n", dest1, src1);
//[情况二:(char *指针)]
	char *dest;
	char *src;
	char *temp;

	printf("请输入原字符串: ");
	scanf("%s", temp);
	dest = (char *)malloc(strlen(temp) + 1);
	src = (char *)malloc(strlen(temp) + 1);
	src = temp;
	printf("请输入目标字符串:");
	scanf("%s", dest);

	//strcpy
	Strcpy(dest, src);
	printf("after strcpy 情况一: \n");
	printf("dest string = %s, src string = %s\n", dest, src);

	//strncpy
	printf("请输入要赋值的位数:");
	scanf("%d", &n);
	Strncpy(dest, src, n);
	printf("after strncpy 情况二: \n");
	printf("dest1 string = %s, src1 string = %s\n", dest, src);

	return 0;
}

