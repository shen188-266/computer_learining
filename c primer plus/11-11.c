#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 10
void menu(char *st[],int n);
void print(char *st[],int n);
void aprint(char *st[],int n);
void lprint(char *st[],int n);
void flprint(char *st[],int n);
char * s_gets(char *st,int n);
int strlen_1(char * str);
int main(void)
{
char st[LIM][SIZE];
int i=0;
char * poi[LIM];
printf("please enter 10 string.\n");
printf("please enter the %d string.\n",i+1);
while(i<10&&s_gets(st[i],SIZE)!=NULL)
{   poi[i]=st[i];
    i++;
    if(i<10)
    printf("please enter the %d string.\n",i+1);
}
menu(poi,LIM);
puts("bye.\n");
return 0;
}
void menu(char *st[],int n){
char os='w';
while (os!='q')
{
printf("please choose what to do.\n");
printf("a.printf the original strings.                                  b.print the strings in order of ASCII.\n");
printf("c.printf the strings in order of length increasingly.           d.print the strings in order of length increasingly of first string.\n");
printf("q.quit.\n");
os=getchar();
while(getchar()!='\n')
  continue;
switch(os)
{
case 'a': print(st,LIM);
        break;
case 'b': aprint(st,LIM);
         break;
case 'c': lprint(st,LIM);
          break;
case 'd': flprint(st,LIM);
          break;
}
}                }
void print(char *st[LIM],int n){
int i=0;
while(i<10)
puts(st[i++]);}
void aprint(char *st[LIM],int n){
int i,j;
char * temp;
for(i=0;i<9;i++)
   for(j=i+1;j<10;j++)
     {if(strcmp(st[i],st[j])>0)
        {temp=st[i];
         st[i]=st[j];
         st[j]=temp;}}
for(i=0;i<10;i++)
  puts(st[i]);}
void lprint(char *st[LIM],int n){
int i,j;
char * temp;
for(i=0;i<10;i++)
   for(j=i+1;j<10;j++)
     {if((int)(strlen(st[i])-strlen(st[j]))>0)
        {temp=st[i];
         st[i]=st[j];
         st[j]=temp;}}
for(i=0;i<10;i++)
  puts(st[i]);}
void flprint(char *st[LIM],int n){
int i,j;
char * temp;
for(i=0;i<9;i++)
   for(j=i+1;j<10;j++)
     {if(strlen_1(st[i])-strlen_1(st[j])>0)
        {temp=st[i];
         st[i]=st[j];
         st[j]=temp;}}
for(i=0;i<10;i++)
  puts(st[i]);}
char * s_gets(char *st,int n){
int i=0;
char * re;
char er;
re=fgets(st,SIZE,stdin);
if(re)
{while(st[i]!='\0'&&st[i]!='\n')
  i++;
if(st[i]=='\n')
   st[i]='\0';
else
  while(getchar()!='\n')
    continue;}
return re;}
int strlen_1(char * str){
int i=0,count=0;
while(*str==' '&&count++<81)
 str++;
while(*str!=' '&&count++<81&&*str!='\0')
{i++;
str++;}
return i;}
