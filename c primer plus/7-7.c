#include <stdio.h>
#define shui1 0.15
#define shui2 0.20
#define shui3 0.25
int main(void)
{
  float a,b,c,d;
  printf("input your work hours(>=0)");
  scanf("%f",&a);
  if(a<=40)
  b=10.00*a;
  else
  b=10.00f*40+(a-40)*1.5f*10.00f;
  if(b<=300)
  c=shui1*b,d=b-c;
  else if(b>300&&b<=450)
  c=shui1*300+shui2*(b-300),d=b-c;
  else
  c=shui1*300+shui2*150+shui3*(b-450),d=b-c;

  printf("sum%8f tax%8f salary%8f",b,c,d);
  return 0;
}

