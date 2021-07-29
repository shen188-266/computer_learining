#include <stdio.h>
int main(void)
{
  int ch,a=0,b=0,s1=0,s2=0;
  printf("input some integer(0 to quit)\n");
  scanf("%d",&ch);
  while(ch!=0)
  { if(ch%2==0)
     {a++;
     s1=s1+ch;}
    else
     {b++;
     s2=s2+ch;}
     scanf("%d",&ch);
  }
  s1/=a;
  s2/=b;
  printf("偶数个数%d,average%d,奇数个数%d,average%d",a,s1,b,s2);
  return 0;

}
