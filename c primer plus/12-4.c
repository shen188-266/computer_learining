#include <stdio.h>
int fanci(void);
int main()
{int i=0,m;
 while (i++<5)
   m=fanci();
printf("%d",m);
return 0;}
int fanci(void){
static count=0;
count++;
return count;}
