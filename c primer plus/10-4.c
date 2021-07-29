#include <stdio.h>
int xiab(double * shuz, int n);
int main(void){
  double oj[]={1.1,29.3,23.2,393.2};
  printf("%d",xiab(oj,4));
  return 0;}
int xiab(double * shuz,int n){
int t,max,b;
for(t=0,max=shuz[0],b=0;t<n;t++)
if(max<shuz[t])
 {max=shuz[t];
 b=t; }
 return b;}
