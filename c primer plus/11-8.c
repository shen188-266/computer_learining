#include <stdio.h>
#include <string.h>
#define SIZE 81
char * string_in(char * s1,char * s2);
char * s_gets(char *st,int n);
int main(void){
char s1[SIZE],s2[SIZE];
char s3[5];
char * sod;
do{
printf("please enter the string 1 and the strng 2, i will check if the string 2 is included in string1.\n");
printf("please enter string 1; ");
s_gets(s1,81);
printf("please enter string 2: ");
s_gets(s2,81);
sod = string_in(s1,s2);
if(sod!=NULL)
printf("the string 1 includes string 2.\n");
else
printf("the string 2 is not included in string 1.\n");
printf("if you want to quit, please enter \"quit\"\n"
     "otherwise,enter any thing to continue.\n");
s_gets(s3,5);
if(strcmp(s3,"quit")==0)
   break;
}while(1);
return 0;}
char * s_gets(char *st,int n){
char * re,* fj;
re=fgets(st,n,stdin);
if(re)
 { fj=strchr(st,'\n');
    if(fj)
      *fj='\0';
    else
    while (getchar()!='\n')
    continue;
return re;}
else
return NULL;
}
char * string_in(char * s1,char * s2){
int i,t;

for(i=0,t=0;i<(int)strlen(s1)-(int)strlen(s2)+1;i++)
   {if(strncmp(s1+i,s2,(int)strlen(s2))==0)
      {t=1;
      break;}}
    if(t==0)
      return NULL;
    else
    return s1+i;}
