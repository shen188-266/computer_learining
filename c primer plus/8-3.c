#include<stdio.h>
#include<ctype.h>
int main()
{ int b=0;
  char a;
  while((a=getchar())!=EOF)
  {a=tolower(a);
  if(a>='a'&&a<='z')
   b++; }
  printf("%d\n",b);
  return 0;
}
