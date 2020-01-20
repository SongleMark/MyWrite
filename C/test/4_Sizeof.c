#include <stdio.h>

int main(int argc, char *argv[]) {
	int array[100];

	printf("sizeof(array) = %ld\n", sizeof(array));          /// 400 4 * 100
	printf("sizeof(array[100]) = %ld\n", sizeof(array[100]));/// 4   int 类型
	printf("sizeof(&array[0]) = %ld\n", sizeof(&array[0]));  /// 8   64位指针大小
	printf("sizeof(&array) = %ld\n", sizeof(&array));        /// 8   64未指针大小
}
