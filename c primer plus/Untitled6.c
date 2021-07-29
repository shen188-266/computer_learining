#include <stdio.h>
#include "alls.h"
int main(void)
{  int a,b=1,c=17;//b-geshu,c-kaishiwei(-1)
   int n=0;
   for(a=0;a<b;a++)
   {
      n+=chengfang_i(2,c--);
   }
   printf("%d",n);
}
