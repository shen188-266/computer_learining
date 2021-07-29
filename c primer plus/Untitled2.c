#include <stdio.h>
int main(void)
{
   int sh[3][4]={{1,2,3,4},{5,6,7,8},{9.10,11,12}};
   printf("%p\n",&sh);
   printf("%p\n",sh);

   printf("%p\n",&sh[0]);
   printf("%p\n",*sh);
   printf("%p\n",sh[0]);
   printf("%p\n",&sh[0][0]);
   printf("%d",**sh);
   return 0;
}
