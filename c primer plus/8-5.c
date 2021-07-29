#include <stdio.h>
char isyn(char a);
int main(void)
{ int guess=50;
  int s=100,x=1;
  char ch;
  printf("pick an integer from 1 to 100. Iwill try to guess ");
  printf("it.\nRespond with a y if my guess is right and with");
  printf("\nan n if it is wrong.\n");
  printf("uh...is your number %d?",guess);
  scanf("%d",&ch);
  while(isyn(ch)!='y')
  { printf("if my guess is bigger than yours(y or n)\n");
        if(isyn(ch)=='y')
         s=guess,guess=(s+x)/2;
         else
         x=guess,guess=(s+x)/2;
    printf("uh...is your number %d?",guess);
  }
    printf("yeah! I know I can dou it. your integer is %d\n",guess);
  return 0;
}
char isyn(char a)
{ a=getchar();
   while(a!='y'&&a!='n')
   {while(getchar()!='\n')
    continue;
    printf("I just can recognize y or n.\ninput again.\n");
    a=getchar();}
    getchar();
    return a;
}
