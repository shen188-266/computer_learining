#include <stdio.h>
void fanhui(double * a,double * b);
int main(){
double a, b;
scanf("%lf%lf",&a,&b);
fanhui(&a,&b);
printf("%lf %lf",a,b);
return 0;
}
void fanhui(double * a,double * b){
double c;
c=(*a>=*b)?*a:*b;
*a=c;
*b=c;}
