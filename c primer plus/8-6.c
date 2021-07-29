#include <stdio.h>
char get_first(void);
int main(void){
 char a;
 a=get_first();
 printf("%c",a);
 return 0;}
char get_first(void)
{int ch;
while((ch=getchar())==' ')
continue;
while(getchar()!='\n')
continue;
return ch;}
