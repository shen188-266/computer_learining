#include <stdio.h>
int main(void)
{
  char ch;
  int a=0;
  while((ch=getchar())!='#')
  { if(ch=='e')
    {ch=getchar();
    if(ch=='i')
     a++;}
  }
  printf("%d",a);
  return 0;
}

