#include <stdio.h>
#include <string.h>
/*
1,分别重写  strlen()   strcpy()  strcat()   strcmp()

#include <stdio.h>
#include <string.h>


int my_strlen(char *a)
{
		int i=0;
		while(a[i]!='\0')
		{
				i++;
		}
		return i;
}


void  my_strcpy(char *dest,char *src)
{
		int i=0;
		while(src[i]!='\0')
		{
				dest[i]=src[i];
				i++;
		}
		dest[i]='\0';
}


void   my_strcat(char *dest,char* src)
{
		int i=0,j=0;
		while(dest[i]!='\0')
		{
				i++;
		}


		while(src[j]!='\0')
		{
				dest[i++]=src[j++];
		}


		dest[i]='\0';
}

int my_strcmp(char *s1,char *s2);

int  main()
{
		char src[128]="hello",dest[128]="shanghai";
//		printf("%d\n",my_strlen(src));
//        my_strcpy(src,dest);
//        my_strcat(dest,src);
        int ret= my_strcmp(src,dest);
		printf("src:%s\ndest:%s\n",src,dest);
		return 0;
}

//  s1>s2   1
//  s1 == s2 0
// s1<s2  -1

int my_strcmp(char *s1,char *s2)
{
		int i=0;
		while(s1[i]!='\0' || s2[i]!='\0')
		{
              if(s1[i]>s2[i])
			  {
					  return 1;
			  }
			  else if(s1[i]<s2[i])
			  {
					  return -1;
			  }

			  i ++;

		}
		return 0;
}

*/


/*

3,设计函数，将字符串反转
*/
void  function3(char *a)
{
		int len,i=0,j;
		len = strlen(a);
        char temp;
		for(i=0,j=len-1;i<j;i++,j--)
		{
             temp = a[i];
			 a[i] = a[j];
			 a[j] = temp;
		}
}



/*

4,设计函数，将一个字符串按从小到大的顺序排序

void  function4(char *a)
{
		int len = strlen(a);
		int i,j;
		char temp;
		for(i=0;i<len-1;i++)
		{
				for(j=0;j<len-1-i;j++)
				{
						if(a[j]>a[j+1])
						{
								temp = a[j];
								a[j] = a[j+1];
								a[j+1] = temp;
						}
				}
		}
}
*/

/*
5,设计函数，去除字符串中的所有空格


void  function5(char *a)
{
		int i=0,j;
		while(a[i]!='\0')
		{
				if(a[i]== ' ')
				{
                      for(j=i;j<strlen(a);j++)
					  {
							  a[j]=a[j+1];
					  } 
					  continue;
				}
				i++;
		}
}

*/

/*


6,将一个整型的数字转换成字符串
123 ====>"123"

void  function6(int num,char a[])
{
	   int i=0;
       while(num)	
	   {
			  a[i++] = num%10+'0';
			  num /= 10;
	   }	   
	   a[i] = '\0';
	   function3(a);
}


int main()
{
		int num = 12345;
		char a[128];
//		function6(num,a);
        sprintf(a,"hello%d",num);
		printf("a:%s\n",a);
}


*/
/*
7,设计函数，将一个字符串插入到另一个字符串最大字符后面
agfhzi       fasdg=======>agfhzfasdgi

   */
void   function7(char *dest,char *src )
{
		int max_index=0,max=dest[0];
	    int i=0,j;
		int len = strlen(src);
		while(dest[i]!='\0')
		{
				if(dest[i]>max)
				{
						max = dest[i];
						max_index = i;
				}
				i++;
		}

		for(j=strlen(dest);j>max_index;j--)
		{

				dest[j+len]=dest[j];
		}


		strncpy(dest+max_index+1,src,strlen(src));
}


int main()
{
		char src[128]="xiaoqi";
		char dest[128]="dsazfd";
		function7(dest,src);

		printf("src:%s,dest:%s\n",src,dest);
		return 0;
}



