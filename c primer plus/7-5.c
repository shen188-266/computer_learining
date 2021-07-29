#include <stdio.h>
int main(void)
{
  char ch,oh;
  int a=0;
  while((ch=getchar())!='#')
  { switch(ch)
  {case '.':
    {ch='!';
      a++;
      putchar(ch);
      }continue;
  case '!':
    {
      oh='!';
      a++;
      printf("%c%c",ch,oh);
    }continue;
  default:
    putchar(ch);}
  }
  printf("\nchange%d",a);
  return 0;
}

