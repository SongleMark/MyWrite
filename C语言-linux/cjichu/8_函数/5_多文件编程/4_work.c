/*
1,   unsigned int my_pow(unsigned int x,unsigned int y);
*/
#include <stdio.h>

unsigned int my_pow(unsigned int x,unsigned  int y);

unsigned int my_pow(unsigned int x,unsigned  int y)
{
		int i,s=1;
		for(i=1;i<=y;i++)
		{
				s *= x;
		}
		return s;
}

int main()
{
		int x,y,ret=1;
		printf("请输入数据：");
		scanf("%d%d",&x,&y);
		ret=my_pow(x,y);
		printf("ret=%d\n",ret);
		return 0;
}


/*
2,  设计函数，求一个整型和一个浮点型数的平均值

3,  设计函数，求两个整型数的最小数

4, 计算面积系统

   (1),设计菜单
   (2),设计长方形  三角形   圆的函数
   (3),组合成一个系统



   */
