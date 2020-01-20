#if 0
算法（Algorithm）：计算机解题的基本思想方法和步骤。算法的描述：是对要解决一个问题或要完成一项任务所采取的方法和步骤的描述，包括需要什么数据（输入什么数据、输出什么结果）、采用什么结构、使用什么语句以及如何安排这些语句等。通常使用自然语言、结构化流程图、伪代码等来描述算法。

　　一、计数、求和、求阶乘等简单算法

　　此类问题都要使用循环，要注意根据问题确定循环变量的初值、终值或结束条件，更要注意用来表示计数、和、阶乘的变量的初值。

　　例：用随机函数产生100个[0，99]范围内的随机整数，统计个位上的数字分别为1，2，3，4，5，6，7，8，9，0的数的个数并打印出来。

　　本题使用数组来处理，用数组a[100]存放产生的确100个随机整数，数组x[10]来存放个位上的数字分别为1，2，3，4，5，6，7，8，9，0的数的个数。即个位是1的个数存放在x[1]中，个位是2的个数存放在x[2]中，……个位是0的个数存放在x[10]。
#endif

void main()
{ int a[101],x[11],i,p;
for(i=0;i<=11;i++)
x[i]=0;
for(i=1;i<=100;i++)
{ a[i]=rand() % 100;
printf("%4d",a[i]);
if(i%10==0)printf("\n");
}
for(i=1;i<=100;i++)
{ p=a[i]%10;
if(p==0) p=10;
x[p]=x[p]+1;
}
for(i=1;i<=10;i++)
{ p=i;
if(i==10) p=0;
printf("%d,%d\n",p,x[i]);
}
printf("\n");
}

#if 0
　　二、求两个整数的最大公约数、最小公倍数

　　分析：求最大公约数的算法思想：(最小公倍数=两个整数之积/最大公约数)
(1) 对于已知两数m，n，使得m>n；
(2) m除以n得余数r；
(3) 若r=0，则n为求得的最大公约数，算法结束；否则执行(4)；
(4) m←n，n←r，再重复执行(2)。
例如: 求 m=14 ,n=6 的最大公约数. m n r
14 6 2
6 2 
#endif
void main()
{ int nm,r,n,m,t;
printf("please input two numbers:\n");
scanf("%d,%d",&m,&n);
nm=n*m;
if (m<n)
{ t=n; n=m; m=t; }
r=m%n;
while (r!=0)
{ m=n; n=r; r=m%n; }
printf("最大公约数:%d\n",n);
printf("最小公倍数:%d\n",nm/n);
}

#if 0
　　三、判断素数

　　只能被1或本身整除的数称为素数 基本思想：把m作为被除数，将2—INT（ ）作为除数，
如果都除不尽，m就是素数，否则就不是。（可用以下程序段实现）
#endif

void main()
{ int m,i,k;
printf("please input a number:\n");
scanf("%d",&m);
k=sqrt(m);
for(i=2;i<k;i++)
if(m%i==0) break;
if(i>=k)
printf("该数是素数");
else
printf("该数不是素数");
}
//将其写成一函数,若为素数返回1，不是则返回0
int prime( m%)
{int i,k;
k=sqrt(m);
for(i=2;i<k;i++)
if(m%i==0) return 0;
return 1;
}
#if 0
　　四、验证哥德巴赫猜想

　　（任意一个大于等于6的偶数都可以分解为两个素数之和）
基本思想：n为大于等于6的任一偶数，可分解为n1和n2两个数，分别检查n1和n2是否为素数，如都是，则为一组解。如n1不是素数，就不必再检查n2是否素数。先从n1=3开始，检验n1和n2（n2=N-n1）是否素数。然后使n1+2 再检验n1、n2是否素数，… 直到n1=n/2为止。

　　利用上面的prime函数，验证哥德巴赫猜想的程序代码如下：
#endif

#include "math.h"
int prime(int m)
{ int i,k;
k=sqrt(m);
for(i=2;i<k;i++)
if(m%i==0) break;
if(i>=k)
return 1;
else
return 0;
}

main()
{ int x,i;
printf("please input a even number(>=6):\n");
scanf("%d",&x);
if (x<6||x%2!=0)
printf("data error!\n");
else
for(i=2;i<=x/2;i++)
if (prime(i)&&prime(x-i))
{
printf("%d+%d\n",i,x-i);
printf("验证成功!");
break;
}
}

#if 0
　　五、排序问题

　　1．选择法排序（升序）

　　基本思想：
1）对有n个数的序列（存放在数组a(n)中），从中选出最小的数，与第1个数交换位置；
2）除第1 个数外，其余n-1个数中选最小的数，与第2个数交换位置；
3）依次类推，选择了n-1次后，这个数列已按升序排列。

程序代码如下：
#endif

void main()
{ int i,j,imin,s,a[10];
printf("\n input 10 numbers:\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(i=0;i<9;i++)
{ imin=i;
for(j=i+1;j<10;j++)
if(a[imin]>a[j]) imin=j;
if(i!=imin)
{s=a[i]; a[i]=a[imin]; a[imin]=s; }
printf("%d\n",a[i]);
}
}
#if 0
　　2．冒泡法排序（升序）

　　基本思想：(将相邻两个数比较，小的调到前头)
1）有n个数（存放在数组a(n)中），第一趟将每相邻两个数比较，小的调到前头，经n-1次两两相邻比较后，最大的数已“沉底”，放在最后一个位置，小数上升“浮起”；
2）第二趟对余下的n-1个数（最大的数已“沉底”）按上法比较，经n-2次两两相邻比较后得次大的数；
3）依次类推，n个数共进行n-1趟比较，在第j趟中要进行n-j次两两比较。
程序段如下
#endif

void main()
{ int a[10];
int i,j,t;
printf("input 10 numbers\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
printf("\n");
for(j=0;j<=8;j++)
for(i=0;i<9-j;i++)
if(a[i]>a[i+1])
{t=a[i];a[i]=a[i+1];a[i+1]=t;}
printf("the sorted numbers:\n");
for(i=0;i<10;i++)
printf("%d\n",a[i]);
}

#if 0
　　3．合并法排序（将两个有序数组A、B合并成另一个有序的数组C，升序）

　　基本思想：
1）先在A、B数组中各取第一个元素进行比较，将小的元素放入C数组；
2）取小的元素所在数组的下一个元素与另一数组中上次比较后较大的元素比较，重复上述比较过程，直到某个数组被先排完；
3）将另一个数组剩余元素抄入C数组，合并排序完成。
程序段如下：
#endif

void main()
{ int a[10],b[10],c[20],i,ia,ib,ic;
printf("please input the first array:\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(i=0;i<10;i++)
scanf("%d",&b[i]);
printf("\n");
ia=0;ib=0;ic=0;
while(ia<10&&ib<10)
{ if(a[ia]<b[ib])
{ c[ic]=a[ia];ia++;}
else
{ c[ic]=b[ib];ib++;}
ic++;
}
while(ia<=9)
{ c[ic]=a[ia];
ia++;ic++;
}
while(ib<=9)
{ c[ic]=b[ib];
b++;ic++;
}
for(i=0;i<20;i++)
printf("%d\n",c[i]);
}

#if 0
　　六、查找问题

　　1．①顺序查找法（在一列数中查找某数x）

　　基本思想：一列数放在数组a[1]---a[n]中，待查找的数放在x 中，把x与a数组中的元素从头到尾一一进行比较查找。用变量p表示a数组元素下标，p初值为1，使x与a[p]比较，如果x不等于a[p]，则使p=p+1，不断重复这个过程；一旦x等于a[p]则退出循环；另外，如果p大于数组长度，循环也应该停止。（这个过程可由下语句实现）
#endif

void main()
{ int a[10],p,x,i;
printf("please input the array:\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
printf("please input the number you want find:\n");
scanf("%d",&x);
printf("\n");
p=0;
while(x!=a[p]&&p<10)
p++;
if(p>=10)
printf("the number is not found!\n");
else
printf("the number is found the no%d!\n",p);
}
#if 0
思考：将上面程序改写一查找函数Find，若找到则返回下标值，找不到返回-1
②基本思想：一列数放在数组a[1]---a[n]中，待查找的关键值为key，把key与a数组中的元素从头到尾一一进行比较查找，若相同，查找成功，若找不到，则查找失败。(查找子过程如下。index：存放找到元素的下标。)
#endif

void main()
{ int a[10],index,x,i;
printf("please input the array:\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
printf("please input the number you want find:\n");
scanf("%d",&x);
printf("\n");
index=-1;
for(i=0;i<10;i++)
if(x==a[i])
{ index=i; break;
}
if(index==-1)
printf("the number is not found!\n");
else
printf("the number is found the no%d!\n",index);
}
#if 0
　　2．折半查找法（只能对有序数列进行查找）

　　基本思想：设n个有序数（从小到大）存放在数组a[1]----a[n]中，要查找的数为x。用变量bot、top、mid 分别表示查找数据范围的底部（数组下界）、顶部（数组的上界）和中间，mid=(top+bot)/2，折半查找的算法如下：
（1）x=a(mid)，则已找到退出循环，否则进行下面的判断；
（2）x<a(mid)，x必定落在bot和mid-1的范围之内，即top=mid-1；
（3）x>a(mid)，x必定落在mid+1和top的范围之内，即bot=mid+1；
（4）在确定了新的查找范围后，重复进行以上比较，直到找到或者bot<=top。
将上面的算法写成如下程序：
#endif

void main()
{
int a[10],mid,bot,top,x,i,find;
printf("please input the array:\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
printf("please input the number you want find:\n");
scanf("%d",&x);
printf("\n");
bot=0;top=9;find=0;
while(bot<top&&find==0)
{ mid=(top+bot)/2;
if(x==a[mid])
{find=1;break;}
else if(x<a[mid])
top=mid-1;
else
bot=mid+1;
}
if (find==1)
printf("the number is found the no%d!\n",mid);
else
printf("the number is not found!\n");
}

#if 0
　　七、插入法

　　把一个数插到有序数列中，插入后数列仍然有序

　　基本思想：n个有序数（从小到大）存放在数组a(1)—a(n)中，要插入的数x。首先确定x插在数组中的位置P；（可由以下语句实现）
#endif

#define N 10
void insert(int a[],int x)
{ int p, i;
p=0;
while(x>a[p]&&p<N)
p++;
for(i=N; i>p; i--)
a[i]=a[i-1];
a[p]=x;
}
main()
{ int a[N+1]={1,3,4,7,8,11,13,18,56,78}, x, i;
for(i=0; i<N; i++) printf("%d,", a[i]);
printf("\nInput x:");
scanf("%d", &x);
insert(a, x);
for(i=0; i<=N; i++) printf("%d,", a[i]);
printf("\n");
}

#if 0
　　八、矩阵（二维数组）运算

（1）矩阵的加、减运算
C(i,j)=a(i,j)+b(i,j) 加法
C(i,j)=a(i,j)-b(i,j) 减法
（2）矩阵相乘
（矩阵A有M*L个元素，矩阵B有L*N个元素，则矩阵C=A*B有M*N个元素）。矩阵C中任一元素 (i=1,2,…,m; j=1,2,…,n)
#endif

#define M 2
#define L 4
#define N 3
void mv(int a[M][L], int b[L][N], int c[M][N])
{ int i, j, k;
for(i=0; i<M; i++)
for(j=0; j<N; j++)
{ c[i][j]=0;
for(k=0; k<L; k++)
c[i][j]+=a[i][k]*b[k][j];
}
}
main()
{ int a[M][L]={{1,2,3,4},{1,1,1,1}};
int b[L][N]={{1,1,1},{1,2,1},{2,2,1},{2,3,1}}, c[M][N];
int i, j;
mv(a,b,c);
for(i=0; i<M; i++)
{ for(j=0; j<N; j++)
printf("%4d", c[i][j]);
printf("\n");
}
}
#if 0
（3）矩阵传置
例:有二维数组a(5,5)，要对它实现转置，可用下面两种方式：
#endif

#define N 3
void ch1(int a[N][N])
{ int i, j, t;
for(i=0; i<N; i++)
for(j=i+1; j<N; j++)
{ t=a[i][j];
a[i][j]=a[j][i];
a[j][i]=t;
}
}
void ch2(int a[N][N])
{ int i, j, t;
for(i=1; i<N; i++)
for(j= 0; j<i; j++)
{ t=a[i][j];
a[i][j]=a[j][i];
a[j][i]=t;
}
}
main()
{ int a[N][N]={{1,2,3},{4,5,6},{7,8,9}}, i, j;
ch1(a); /*或ch2(a);*/
for(i=0; i<N; i++)
{ for(j=0; j<N; j++)
printf("%4d", a[i][j]);
printf("\n");
}
}
#if 0
（4）求二维数组中最小元素及其所在的行和列
基本思路同一维数组，可用下面程序段实现（以二维数组a[3][4]为例）：
‘变量max中存放最大值，row,column存放最大值所在行列号
#endif

#define N 4
#define M 3
void min(int a[M][N])
{ int min, row, column, i, j;
min=a[0][0];
row=0;
column=0;
for(i=0; i<M; i++)
for(j=0; j<N; j++)
if(a[i][j]<min)
{ min=a[i][j];
row=i;
column=j;
}
printf("Min=%d\nAt Row%d,Column%d\n", min, row, column);
}
main()
{ int a[M][N]={{1,23,45,-5},{5,6,-7,6},{0,33,8,15}};
min(a);
}

#if 0
　　九、迭代法

　　算法思想：对于一个问题的求解x，可由给定的一个初值x0，根据某一迭代公式得到一个新的值x1，这个新值x1比初值x0更接近要求的值x；再以新值作为初值，即：x1→x0,重新按原来的方法求x1,重复这一过和直到|x1-x0|<ε(某一给定的精度)。此时可将x1作为问题的解。
例：用迭代法求某个数的平方根。 已知求平方根的迭代公式为：
#endif
#include<math.h>
float fsqrt(float a)
{ float x0, x1;
x1=a/2;
do{
x0=x1;
x1=0.5*(x0+a/x0);
}while(fabs(x1-x0)>0.00001);
return(x1);
}
main()
{ float a;
scanf("%f", &a);
printf("genhao =%f\n", fsqrt(a));
}

#if 0
　　十、数制转换

　　将一个十进制整数m转换成 →r(2－16)进制字符串。

　　方法：将m不断除 r 取余数，直到商为零，以反序得到结果。下面写出一转换函数，参数idec为十进制数，ibase为要转换成数的基（如二进制的基是2，八进制的基是8等），函数输出结果是字符串。
#endif
char *trdec(int idec, int ibase)
{ char strdr[20], t;
int i, idr, p=0;
while(idec!=0)
{ idr=idec % ibase;
if(idr>=10)
strdr[p++]=idr-10+65;
else
strdr[p++]=idr+48;
idec/=ibase;
}
for(i=0; i<p/2; i++)
{ t=strdr[i];
strdr[i]=strdr[p-i-1];
strdr[p-i-1]=t;
}
strdr[p]=’\0’;
return(strdr);
}
main()
{ int x, d;
scanf("%d%d", &x, &d);
printf("%s\n", trdec(x,d));
}

#if 0
　　十一、字符串的一般处理

　　1．简单加密和解密
加密的思想是： 将每个字母C加（或减）一序数K，即用它后的第K个字母代替，变换式公式： c=c+k
例如序数k为5，这时 A→ F， a→f，B→?G… 当加序数后的字母超过Z或z则 c=c+k -26
例如：You are good→ Dtz fwj ltti
解密为加密的逆过程
将每个字母C减（或加）一序数K，即 c=c-k,
例如序数k为5，这时 Z→U，z→u，Y→T… 当加序数后的字母小于A或a则 c=c-k +26
下段程序是加密处理：
#endif

#include<stdio.h>
char *jiami(char stri[])
{ int i=0;
char strp[50],ia;
while(stri[i]!=’\0’)
{ if(stri[i]>=’A’&&stri[i]<=’Z’)
{ ia=stri[i]+5;
if (ia>’Z’) ia-=26;
}
else if(stri[i]>=’a’&&stri[i]<=’z’)
{ ia=stri[i]+5;
if (ia>’z’) ia-=26;
}
else ia=stri[i];
strp[i++]=ia;
}
strp[i]=’\0’;
return(strp);
}
main()
{ char s[50];
gets(s);
printf("%s\n", jiami(s));
}

#if 0
2．统计文本单词的个数
输入一行字符，统计其中有多少个单词，单词之间用格分隔开。
算法思路：
（1）从文本（字符串）的左边开始，取出一个字符；设逻辑量word表示所取字符是否是单词内的字符，初值设为0
（2）若所取字符不是“空格”，“逗号”，“分号”或“感叹号”等单词的分隔符，再判断word是否为1，若word不为1则表是新单词的开始，让单词数num = num +1，让word =1;
（3）若所取字符是“空格”，“逗号”，“分号”或“感叹号”等单词的分隔符， 则表示字符不是单词内字符，让word=0;
(4) 再依次取下一个字符，重得（2）(3)直到文本结束。
下面程序段是字符串string中包含的单词数
#endif
#include "stdio.h"
main()
{char c,string[80];
int i,num=0,word=0;
gets(string);
for(i=0;(c=string[i])!='\0';i++)
if(c==' ') word=0;
else if(word==0)
{ word=1;
num++;}
printf("There are %d word in the line.\n",num);
}

#if 0
　　十二、穷举法
　　
　　穷举法（又称“枚举法”）的基本思想是：一一列举各种可能的情况，并判断哪一种可能是符合要求的解，这是一种“在没有其它办法的情况的方法”，是一种最“笨”的方法，然而对一些无法用解析法求解的问题往往能奏效，通常采用循环来处理穷举问题。
例： 将一张面值为100元的人民币等值换成100张5元、1元和0.5元的零钞，要求每种零钞不少于1张，问有哪几种组合？
#endif
main()
{ int i, j, k;
printf(" 5元 1元 5角\n");
for(i=1; i<=20; i++)
for(j=1; j<=100-i; j++)
{ k=100-i-j;
if(5*i+1*j+0.5*k==100)
printf(" %3d %3d %3d\n", i, j, k);
}
}
#if 0
　　十三、递归算法
　　
　　用自身的结构来描述自身，称递归
　　
　　VB允许在一个Sub子过程和Function过程的定义内部调用自己，即递归Sub子过程和递归Function函数。递归处理一般用栈来实现，每调用一次自身，把当前参数压栈，直到递归结束条件；然后从栈中弹出当前参数，直到栈空。
递归条件：（1）递归结束条件及结束时的值；（2）能用递归形式表示，且递归向终止条件发展。
例：编fac(n)=n! 的递归函数
#endif
int fac(int n)
{ if(n==1)
return(1);
else
return(n*fac(n-1));
}
main()
{ int n;
scanf("%d", &n);
printf("n!=%d\n", fac(n));
}
