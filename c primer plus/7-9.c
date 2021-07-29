#include <stdio.h>
int main(void)
{ int a,b;
  printf("input a optimistic integer(>1)\n");
  scanf("%d",&a);
  for(;a>1;a--)
   {for(b=2;b<a;b++)
    if(a%b==0)
    break;
   if(a==b)
   printf("%3d",a);}
  return 0;
}

