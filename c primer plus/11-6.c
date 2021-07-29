#include <stdio.h>
#include<string.h>
int is_within(char * st,char ch);
int main(void){
int a,b;
char * dm="eorgoie rpgwir ijg43";
a=is_within(dm,'o');
b=is_within(dm,'b');
printf("%d  %d",a,b);
return 0;}
int is_within(char * st,char ch){
if(strchr(st,ch))
return 1;
else
return 0;}
