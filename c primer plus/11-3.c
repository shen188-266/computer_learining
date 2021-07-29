#include<stdio.h>
int n_scanf(char * st);
int main(void){
char * shuzu[10];
n_scanf(shuzu);
puts(shuzu);
return 0;}
int n_scanf(char * st){
int s;
s=scanf("%s",st);
while(getchar()!='\n')
continue;
return s;}
