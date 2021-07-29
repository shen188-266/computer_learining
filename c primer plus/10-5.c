#include <stdio.h>
double cha(const double * shuz, int n);
int main(void){
  double oj[]={1.1,29.3,23.2,393.2};
  printf("%lf",cha(oj,4));
  return 0;}
double cha(const double * shuz,int n){
int t,b,c;
double max=shuz[0],min=shuz[0];
for(t=0,c=0,b=0;t<n;t++)
{if(max<shuz[t])
 {max=shuz[t];
 b=t; }
 if(min>shuz[t])
 {min=shuz[t];
 c=t;}}
 return shuz[b]-shuz[c];}
