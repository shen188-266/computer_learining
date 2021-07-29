#include <stdio.h>
int main(void)
{
  char ch;
  int a=1;
  while((ch=getchar())!='#')
  { printf("%2c-%03d",ch,ch);
    a++;
    if(a%8==0)
      printf("\n");
  }
  return 0;
}
