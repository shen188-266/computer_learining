#include<stdio.h>
double power(double a,int b);
int main(){
double a,c;
int b;
printf("input a double and an integer, i will output double^integer.(q to quit)\n");
while(scanf("%lf %d",&a,&b)==2)
{c=power(a,b);
    printf("%lf",c);
printf("input a double and an integer, i will output double^integer.q to quit)\n");}
return 0;}
double power(double a,int b){
double c=1.0;
if(a==0)
{if(b==0)
{printf("undefined.\n");
return 1;
}
else
    return 0;
}
else{
if(b==0)
return c;
else if(b>0)
return a*power(a,--b);
else
return a*power(a,++b);
     }
}
