#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
double sum(double *shz,int n,...);
int main(void)
{
   double *shz;

   shz=(double *)malloc(sizeof(double));

   *shz=0.0;

   printf("%lf\n",sum(shz,3,2.2,5.1,2.4));

   printf("%lf",*shz);
   free(shz);
   return 0;
}
double sum(double *shz,int n,...){
  va_list ap;
  va_start(ap,n);
  for(int i=0;i<n;i++)
  *shz+=va_arg(ap,double);
  return *shz;}
