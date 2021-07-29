#include <stdio.h>
#include<ctype.h>
#include "Untitled1.h"
int main(void){
char ch;
float a,b;
while ((ch=caidan())!='q')
{printf("Enter first number:");
a=isn();
switch(ch)
{case 'a': b=towisn();
           printf("%.1f+%.1f=%.1f\n",a,b,a+b);
           break;
 case 's': b=towisn();
           printf("%.1f-%.1f=%.1f\n",a,b,a-b);
           break;
 case 'm': b=towisn();
           printf("%.1f*%.1f=%.1f\n",a,b,a*b);
           break;
 case 'd': b=towisno0();
           printf("%.1f/%.2f=%.1f\n",a,b,a/b);
           break;
}}
        printf("bye.\n");
        return 0;}
