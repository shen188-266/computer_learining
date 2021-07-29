#include <stdio.h>
#include <string.h>
char * mystrncpy(char * s1,char * s2,int n);
int main(void){
char * op,* ik3="eo 93=w 4t.uwio e";
char klw[20];
op=mystrncpy(klw,ik3,6);
for(int i=0;i<6;i++)
    putchar(klw[i]);
putchar('\n');
return 0;}
char * mystrncpy(char * s1,char * s2,int n){
for (int i=0;i<n;i++)
    s1[i]=s2[i];
return s1;}

