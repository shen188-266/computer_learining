#include <stdio.h>
#include <string.h>
#include <ctype.h>
int myatol(char * st);
char * s_gets(char *st,int n);
int shuzi(int t);
int cifang_zheng(int a,int b);
int main(void)
{char st[81];
s_gets(st,81);
shuzi(myatol(st));
return 0;}
int myatol(char * st){
int i=0,t=strlen(st),num=0;
while(isdigit(st[i]))
   i++;
if(i!=t)
 return 0;
else
 i=0;
 while(t>0)
 {num+=(int)(st[i]-'0')*cifang_zheng(10,--t);
 i++;}
 return num;}
 int shuzi(int t){
 printf("%d",t);
 return 0;}
char * s_gets(char *st,int n){
int i=0;
char * re;
char er;
re=fgets(st,81,stdin);
if(re)
{while(st[i]!='\0'&&st[i]!='\n')
  i++;
if(st[i]=='\n')
   st[i]='\0';
else
  while(getchar()!='\n')
    continue;}
return re;}
int cifang_zheng(int a,int b){
int i=0,c=1;
if(b>0)
while(i++<b)
    {
        c*=a;
    }
else if(b==0)
    c=1;
return c;
}
