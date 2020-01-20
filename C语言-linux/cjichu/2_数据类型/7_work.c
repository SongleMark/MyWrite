/*

1,请输入圆柱体的半径和高，输出圆柱体的体积

#include<stdio.h>

int main()
{
		float r,h,v;
		printf("请输入 数据：");
		scanf("%f%f",&r,&h);
		v = 3.14*r*r*h;
		printf("v = %.2f\n",v);

		return 0;
}

*/


/*
2,输入一个ascii码，输出该ascii码对应的下一个字符
#include <stdio.h>


int main()
{
//		char ch;
        int ch;
		printf("请输入一个asscii：");
		scanf("%d",&ch);
		printf("%c\n",ch+1);
		return 0;
}


*/
/*

3,请分别输入每个苹果和芒果的单价，输出2个苹果和3个芒果的总价


4,请输入一个学生的基本信息：学号、性别、年龄、成绩，并输出



   */




#include <stdio.h>


int main()
{
		int num,age;
		char sex;
		double score;

//		printf("请输入数据：");
//		scanf("%d,%c,%d,%lf",&num,&sex,&age,&score);
//		printf("%d\t%c\t%d\t%.2lf\n",num,sex,age,score);

        printf("请输入学号：");
		scanf("%d",&num);
//		getchar();
        setbuf(stdin,NULL);
		printf("请输入性别：");
		scanf("%c",&sex);
		getchar();
		printf("请输入年龄：");
		scanf("%d",&age);
		getchar();
		printf("请输入成绩：");
		scanf("%lf",&score);
		getchar();
		printf("%d\t%c\t%d\t%.2lf\n",num,sex,age,score);

		return 0;
}
