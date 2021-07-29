#include <stdio.h>
double min(double a,double b);
int main(void)
{double a , b, c;
scanf("%lf%lf",&a,&b);
c=min(a,b);
printf("%lf",c);
return 0;}
double min(double a,double b)
{return (a<=b)?a:b;}
