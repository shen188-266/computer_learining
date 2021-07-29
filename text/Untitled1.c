#include <stdio.h>

void fun(char **q,char *p)
{
   *q="3";
   p="0";
}
int main(void)
{
   char *p="1";
   char **q;
   *q="2";
   printf("%s,%s",p,*q);
   fun(q,p);
   printf("\n%s,%s",p,*q);
   return 0;
}
