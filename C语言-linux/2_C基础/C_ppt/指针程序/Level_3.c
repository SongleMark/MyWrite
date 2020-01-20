#include <stdio.h>
main()
{
   int  i, j, a[6]={2,4,6,8,10,12}, *p[3];
    for(i=0;i<3;i++)
      p[i]=&a[2*i];
    for(i=0;i<3;i++)
       {
         for(j=0;j<2;j++)
          printf("%4d,",p[i][j]);
         printf("\n");
       }

    for(i=0;i<2;i++)
       {
         for(j=0;j<3;j++)
          printf("%4d,",p[j][i]);
         printf("\n");
       }
}
