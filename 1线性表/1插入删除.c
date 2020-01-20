/*************************************************************
 * 文件名: 1插入删除.c
 * 作者  : 当年小马哥
 * 时间  : 2019-8-29
 *************************************************************/
#include <stdio.h>

#define MAXLEN 10 

enum
{
	FALSE, //错误操作
	TRUE   //正确操作
};

typedef int EmpType;

typedef struct 
{
	EmpType length;
	EmpType data[MAXLEN];
}Data;

EmpType InsertToArray(Data *array, EmpType i, EmpType x);
EmpType DeleteFromArray(Data *array, EmpType i);
void ShowArray(Data array);

int main()
{
	Data a;
	EmpType index = 0;
	EmpType variable = 0;
	//a.data[5] = {1, 2, 3, 4, 5};  //数组一旦已经定义则不可在用{}赋值, {}赋值操作只能在定义时进行
	a.data[0] = 1;
	a.data[1] = 2;
	a.data[2] = 3;
	a.data[3] = 4;
	a.data[4] = 5;

	a.length = 5;
	
	printf("请输入插入的位置: ");
	scanf("%d", &index);
	getchar();
	printf("请输入要插入的数据: ");
	scanf("%d", &variable);
	getchar();

	printf("插入之前: \n");
	ShowArray(a);

	EmpType result = InsertToArray(&a, index, variable);
	if(FALSE == result)
	{
		printf("插入位置错误!!!\n");
		return -1;
	}

	printf("插入之后: \n");
	ShowArray(a);

	printf("请输入删除的位置: ");
	scanf("%d", &index);
	getchar();

	result = DeleteFromArray(&a, index);
	if(FALSE == result)
	{
		printf("删除位置错误!!!\n");
		return -1;
	}

	printf("删除后: \n");
	ShowArray(a);

	
	return 0;
}


/*插入操作
 *array 为需要操作的数组以及其长度的结构体指针
 *i----插入的位置
 *x----插入的数据
 */
EmpType InsertToArray(Data *array, EmpType i, EmpType x)
{
	if(i >= MAXLEN || i < 0)
	{
		return FALSE;
	}
	else if( i >= array->length && i < MAXLEN) 
	{
		array->data[array->length] = x;
		array->length ++;
		return TRUE;
	}

	for(int j = array->length ; j >= i-1 ; j --)
	{
		array->data[j] = array->data[j-1];
	}
	array->data[i-1] = x;
	array->length ++;

	return TRUE;
}

/*删除操作
 *array---操作的对象
 *i-------要删除的位置
 */
EmpType DeleteFromArray(Data *array, EmpType i)
{
	if(i > array->length || i < 0)
	{
		return FALSE;
	}
	else if(array->length == i)
	{
		array->data[array->length-1] = 0;
		array->length --;
		return TRUE;
	}

	for(int j = i-1 ; j < array->length ; j ++)
	{
		array->data[j] = array->data[j + 1];
	}
	array->length --;

	return TRUE;
}

//打印对应的数组
void ShowArray(Data array)
{
	for(int i = 0 ; i < array.length ; i ++)
	{
		printf("array[%d] = %d, ", i, array.data[i]);
	}
	printf("\n");
}


