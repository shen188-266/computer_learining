#include <stdio.h>
#include "alls.h"
void transform(double yuan[],double target[],int n,double (*pa)(double a));
double add1(double a);
int main(void)
{double yuan[3]={2.22,3.13,123.12},target[3];
transform(yuan,target,3,add1);
printf("%lf %lf %lf",target[0],target[1],target[2]);
return 0;
}
double add1(double a){
return a+10.00;}
void transform(double yuan[],double target[],int n,double (*pa)(double a)){
for(int i=0;i<n;i++)
    {
        target[i]=(*pa)(yuan[i]);
    }
}
