#include <stdio.h>
int main(void)
{
  char ch,oh;
  int a=0;
  while((ch=getchar())!='#')
  { if(ch=='.')
    {ch='!';
      a++;
      putchar(ch);
      }
  else if(ch=='!')
    {
      oh='!';
      a++;
      printf("%c%c",ch,oh);
    }
  else
    putchar(ch);
  }
  printf("change number %d",a);
  return 0;
}

