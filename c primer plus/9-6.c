#include<stdio.h>
void fanhui(double *a,double *b,double *c);
int main()
{double a ,b ,c;
scanf("%lf%lf%lf",&a,&b,&c);
fanhui(&a,&b,&c);
printf("%lf %lf %lf",a,b,c);
return 0;}
void fanhui(double *a,double *b,double *c)
{
double min,max,m;
if(*a<=*b)
min=*a,max=*b;
else
min=*b,max=*a;
if(min<=*c)
if(max>=*c)
m=*c;
else
m=max,max=*c;
else
m=min,min=*c;
*a=min;
*b=m;
*c=max;}
