#include <stdio.h>
#include <ctype.h>
int main(int argc,char *argv[])
{
int t=0,a=0,b=0,c=0,d=0,count=0;
char st;
while((st=getchar())!=EOF)
{if(isspace(st))
   {t=0;
   continue;}
else
  { if(isupper(st))
      a++;
    else if(islower(st))
       b++;
    else if(ispunct(st))
       c++;
    else if(isdigit(st))
       d++;
if(t==0)
  count++;
        t=1;
  }
  if(t==0)
    printf("idiot.\n");//检测continue是不是能到此。
}
printf("upper%4d lower%4d punct%4d digit%4d word%4d\n",a,b,c,d,count);
return 0;}
