#include <stdio.h>
#define shui1 0.15
#define shui2 0.20
#define shui3 0.25
int main(void)
{ char oo='b';
  float a,b,c,d,f;
  huiqu: if(oo=='a')
      printf("input another number\n");
  printf("input your salary level(abcd)(q to quit)\n");
  while(scanf("%c",&oo),getchar())
  {switch(oo)
  { case 'a':f=8.75;
    break;
    case 'b':f=9.33;
    break;
    case 'c':f=10.00;
    break;
    case 'd':f=11.20;
    break;
    case 'q': goto zou;
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

