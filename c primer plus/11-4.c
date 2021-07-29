#include<stdio.h>
int n_scanf(char * st,int n);
int main(void){
char * shuzu[10];
n_scanf(shuzu,10);
puts(shuzu);
return 0;}
int n_scanf(char * st,int n){
int s;
s=fgets(st,n,stdin);
if(s){
while(*st!='\0'&&*st!='\n'&&*st!=' ')
st++;
if(*st=='\0')
while(getchar()!='\n')
continue;
else
*st='\0';}

return s;}
