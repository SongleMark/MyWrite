#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void Swapvariable(int *temp_a, int *temp_b);
void Swap(void *temp_a, void *temp_b, int size);

int main()
{
    int a = 10;
    int *p = NULL;
    p = &a;
    printf("a = %d, *p = %d\n", a, *p);

    int **pp = NULL;
    pp = &p;
    printf("p = %p, *pp = %p, **pp = %d\n", p, *pp, **pp);

    int c = 10;
    int d = 20;
    printf("c = %d, d = %d\n", c, d);
    Swapvariable(&c, &d);
    printf("c = %d, d = %d\n", c, d);

    int size = sizeof(int);
    printf("size = %d\n", size);
    Swap(&c, &d, size);
    printf("c = %d, d = %d\n", c, d);

    return 0;
}

void Swapvariable(int *temp_a, int *temp_b)
{
    int temp;
    temp = *temp_a;
    *temp_a = *temp_b;
    *temp_b = temp;
}

void Swap(void *temp_a, void *temp_b, int size)
{
    void *temp = malloc(size);
    memcpy(temp, temp_a, size);
    memcpy(temp_a, temp_b, size);
    memcpy(temp_b, temp, size);

    free(temp);
}