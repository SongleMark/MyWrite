#include  <stdio.h>
main()
{
   int  a[3][4],  *p;
   int  i,  j,  max,  row_colum;
     max=a[0][0];
     p=&a[0][0];
     printf("please 3x4 nuber:\n"); 
    for(i=0;i<12;i++)
       scanf("%d", p+i);
  
    for(i=0;i<12;i++)
       {
       if(max<*(p+i))
           {
           max=*(p+i);
           row_colum=i;
           }
       }
    printf("max=%d, row=%d,colum=%d\n", max, row_colum/4,  row_colum%4);
}
