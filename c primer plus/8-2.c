#include<stdio.h>
int main()
{ char a;
  while((a=getchar())!=EOF)
  if(a=='\n')
  printf("char \\n,ASCII%4d\n",a);
  else if(a=='\t')
  printf("char \\t,ASCII%4d\n",a);
  else
  printf("char%2c,ASCII%4d\n",a,a);
  return 0;
}
