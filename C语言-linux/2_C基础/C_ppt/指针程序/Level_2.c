#include <stdio.h>
main()
{
   char a[4][100];
   char (*p)[100];
   int i, number,search;
   p=a;   
   for(i=0;i<4; i++)
      {
       printf("please input  number(1~4) and  name:\n");
       scanf("%d", &number);
       scanf("%s", *(p+number-1));
      }
    while(1)
       {
        printf("please input search number:\n"); 
        scanf("%d", &search);
           if(search==0)
               break;
        printf("%s\n", *(p+search-1));
       }
        
}





