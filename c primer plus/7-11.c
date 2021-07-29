#include <stdio.h>
#define yangli 2.05
#define tiancai 1.15
#define carrot 1.09
int main(void){
char category;
float price=0.0f,weight,aweight=0.0,all_fee,discount,tran_postage;
printf("please input the category(a to c,q to quit)\n");
while(scanf("%c",&category))
{if(category=='\n')
  continue;
    if(category>='a'&&category<='c'||category=='q'){
    if(category!='q')
    {printf("input how much weight\n");
           scanf("%f",&weight);
           aweight+=weight;}
switch(category)
{
 case 'a':price+=yangli*weight;
           break;
 case 'b':price+=tiancai*weight;
           break;
 case 'c':price+=carrot*weight;
           break;
 case 'q':break;
}}
else
    {printf("input again\n");
    continue;}
if(category=='q')
break;
printf("please input another category(a to c,q to quit)\n");}
if((int)price==100)
price*=0.95,discount=5;
else
discount=0;
if(aweight<=5)
tran_postage=6.5;
else if(aweight<=20&&aweight>5)
tran_postage=14.0f;
else if(aweight>20)
tran_postage=14.0+0.5*(aweight-20.0);
all_fee=price+tran_postage;
printf("price=%5.2f,aweight=%5.2f,all_fee=%5.2f,discount=%5.2f,tran_postage=%5.2f\n",price,aweight,all_fee,discount,tran_postage);
return 0;}


