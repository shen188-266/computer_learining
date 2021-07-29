#include <stdio.h>
#define tiaohe(X,Y) 2/((1/(X))+(1/(Y)))
int main(void)
{
   float a=2,b=3;
   printf("%f",tiaohe(a,b));
   return 0;
}
