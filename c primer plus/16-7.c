#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show(const double ar[],int n);
double * new_d(int n, ...);
int main(void)
{
   double * p1;
   double * p2;

p1=new_d(5,1.2,2.3,3.4,4.5,5.6);
p2=new_d(4,200.0,30.0,8.08,-1890.0);
show(p1,5);
show(p2,4);
free(p1);
free(p2);
return 0;
}
void show(const double ar[],int n){
for(int i=0;i<n;i++)
    {
        printf("%10.3lf",ar[i]);
    }
    putchar('\n');
}
double * new_d(int n, ...){
    va_list ap;
    va_start(ap,n);

double *pp;
pp=(double *)malloc(n*sizeof(double));
  for(int i=0;i<n;i++)
  {
      pp[i]=va_arg(ap,double);
  }
  va_end(ap);
return pp;}
