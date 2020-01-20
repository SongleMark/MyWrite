#include <stdio.h>

/*
expre?expre1:expre2

等价于：
if(expre)
{
expre1;
}
else
{
expre2;
}


   */
int main()
{
		int a=1,b=2;
		a<b?printf("a<b\n"):printf("a>b\n");
		return 0;
}
