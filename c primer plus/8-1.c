#include <stdio.h>
int main(void)
{
  int a=0;
  char ch;
  while((ch=getchar())!=EOF)
  a++;
  printf("%d",a);
  return 0;
}
