#include <stdio.h>
#define shui1 0.15
#define shui2 0.20
#define shui3 0.25
int main(void)
{ int oo;
  float a,b,c,d,f;
  huiqu: printf("input another number\n");
  printf("input your salary level(5 to quit)\n");
  while(scanf("%d",&oo))
  {switch(oo)
  { case 1:f=8.75;
    break;
    case 2:f=9.33;
    break;
    case 3:f=10.00;
    break;
    case 4:f=11.20;
    break;
    case 5: goto zou;
    break;
    default:goto huiqu;
  }
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

  printf("sum%8f tax%8f salary%8f\n",b,c,d);}
  zou: printf("over\n");
  return 0;
}

