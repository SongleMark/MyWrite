#include <stdio.h>

int BinarySearch(int array[], int value, int size);
int BinarySearchInRecursive(int array[], int value, int low, int height);

int main(int argc, char *argv[])
{
	int key;
	int value;
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for(int i = 0; i < 10; i ++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	printf("please input the search value: ");
	scanf("%d", &value);
	key = BinarySearch(array, value, 10);
	if(-1 == key)
	{
		printf("输入错误!!!\n");
		return -1;
	}
	printf("查找到的下标为: %d\n", key);

	printf("递归查找*******************\n");
	if(-1 == (key = BinarySearchInRecursive(array, value, 0, 9)))
	{
		printf("输入错误!!!\n");
		return -1;
	}
	printf("查找到的下标为: %d\n", key);
	return 0;
}

/**************************************************
 * 非递归方法
 * 返回值为查找到的数组下标
 * array[]为数组，value为要查找的数值，size为数组大小
 **************************************************/
int BinarySearch(int array[], int value, int size)
{   
	int height = size - 1;
	int low = 0;
	int mid;

	while(low <= height)
	{   
		mid = low + (height - low)/2;
		if(value == array[mid])
		{
			return mid;
		}
		else if(value > array[mid])
		{
			low = mid + 1;
		}
		else
		{
			height = mid - 1;
		}
	}
		  
	return -1;
}

/******************************************************
 *递归法
 *返回值为查找到的数组下标
 *array[]为要查找的数组，value为要查找的数值，low为数组最小下标，height为数组最大下标
 ******************************************************/
int BinarySearchInRecursive(int array[], int value, int low, int height)
{
	if(low > height)
	{
		return -1;
	}

	int mid = low + (height - low)/2;
	if(value == array[mid])
	{
		return mid;
	}
	else if(value > array[mid])
	{
		BinarySearchInRecursive(array, value, mid + 1, height);
	}
	else
	{
		BinarySearchInRecursive(array, value, low, mid -1);
	}
}
