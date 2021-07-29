#include <stdio.h>
double tiaohe(double,double);
int main(){
double a,b;
scanf("%lf%lf",&a,&b);
a=tiaohe(a,b);
printf("%f",a);
return 0;
}
double tiaohe(double a,double b){
a=1/a;
b=1/b;
a=2/(a+b);
return a;}
