/*
   1,从键盘输入一个字符,判断该字符的类型，数字字符，大写字符，小写字符，控制字符，其他字符
    //多重if  +  嵌套if

*/

#include <stdio.h>
#if   0
int main()
{
		char ch;
		printf("请输入一个字符:");
		scanf("%c",&ch);

		if(ch>='0'&&ch<='9')
		{
				printf("数字字符\n");
		}
		else if(ch>='A'&&ch<='Z')
		{
				printf("大写字符\n");
		}
		else if(ch>='a'&&ch<='z')
		{
				printf("小写字符\n");
		}
		else if(ch>=0 &&ch<=31 ||ch==127)
		{
				printf("控制字符\n");
		}
		else
		{
				printf("其他字符\n");
		}
		return 0;
}


int main()
{
		char ch;
		printf("请输入一个字符：");
		scanf("%c",&ch);

		if(ch>='a'&&ch<='z')
		{
				printf("小写字符\n");
		}
		else
		{
				if(ch>='A'&&ch<='Z')
				{
						printf("大写字符\n");
				}
				else
				{
						if(ch>='0'&&ch<='9')
						{
								printf("数字字符\n");
						}
						else
						{
								if(ch>=0 &&ch<=31 ||ch == 127)
								{
										printf("控制字符\n");
								}
								else
								{
										printf("其他字符\n");
								}
						}
				}
		}
		return 0;
}

#endif
/*
   2,某商店商品正在打折促销，根据用户购买的数量给予不同折扣，
   根据用户输入的商品数量和单价,输出用户应付的钱数

   数量           折扣
   <5             不打折
   5-10           1%折扣
   10-15          2%折扣
   15-20          3%折扣
   20-25          4%折扣
#include <stdio.h>

int main()
{
		int num;
		float price,p,rate=0;

		printf("请输入商品数量和单价:");
		scanf("%d%f",&num,&price);

		if(num<0)
		{
				printf("输入数据无效！\n");
				return 0;
		}
		else if(num>=1 && num<5 )
		{
				rate = 1;
				printf("原价：");
		}
		else if(num>=5 && num<10)
		{
				rate = 0.99;
				printf("99折:");
		}
		else if(num>=10 && num<15)
		{
				rate = 0.98;
				printf("98折:");
		}
		else if(num>=15 && num<20)
		{
				rate = 0.97;
				printf("97折:");
		}
        else if(num>=20)
		{
				rate = 0.96;
				printf("96折：");
		}

		p = num*price*rate;
		printf("%.2f\n",p);
		

		return 0;
}

*/
/*

3,输入一个字符，判断是否是元音字符
  a  o   e  i  u
   */


/*
4,输入三个整数，找出三个数中的最大值，并输出所有最大值
a   b    c
12  45   3   ====>b = 45
12  45   45  ====>b = c= 45
12  12   12  ====>a = b =c  12

int main()
{
		int a,b,c;
		printf("请输入三个整数：");
		scanf("%d%d%d",&a,&b,&c);

		if(a>b)
		{
				if(a>c)
				{
						printf("max:a=%d\n",a);
				}
				else if(a<c)
				{
						printf("max:c=%d\n",c);
				}
				else
				{
						printf("max:a=c=%d\n",a);
				}
		}
		else if(a<b)
		{
				if(b<c)
				{
						printf("max:c=%d\n",c);
				}
				else if(b>c)
				{
						printf("max:b%d\n",b);
				}
				else
				{
						printf("max:b=c=%d\n",c);
				}
		}
		else  // a==b
		{
               if(a>c)
			   {
						printf("max:a=b=%d\n",a);
			   }
			   else if(a<c)
			   {
						printf("max:c=%d\n",c);
			   }
			   else
			   {
						printf("max:a=b=c=%d\n",a);
			   }
		}
		return 0;
}


*/
/*

5,输入三个整数，作为三角形的三条边，判断该三角形的类型
   等边三角形、等腰三角形、直角三角形、等腰直角三角形、普通三角形、非三角形
*/

int main()
{
		int a,b,c;
	    int dengbian=0,dengyao=0,zhijiao=0;
		printf("请输入数据：");
		scanf("%d%d%d",&a,&b,&c);

		if(a+b<=c || a+c<=b ||b+c<=a)
		{
				printf("非三角形\n");
				return 0;
		}

		if(a == b && b==c)
		{
				dengbian = 1;
		}

		if(a==b || b==c ||  a==c)
		{
				dengyao = 1;
		}

		if(a*a +b*b == c*c ||  a*a+c*c==b*b ||  b*b+c*c==a*a)
		{
				zhijiao = 1;
		}

		if(dengbian )
		{
				printf("等边三角形\n");
		}
		else if(dengyao && zhijiao)
		{
				printf("等腰直角\n");
		}
		else if(dengyao)
		{
				printf("等腰\n");
		}
		else if(zhijiao)
		{
				printf("直角\n");
		}
		else
		{
				printf("普通！\n");
		}

       
		return 0;
}







