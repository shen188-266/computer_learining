#include <stdio.h>
int maxf(const int *nt, int n);
int main(void){
int t;
int wejd[5]={2,3,1,4,5};
t=maxf(wejd,5);
printf("%d",t);
return 0;
}
int maxf(const int *nt, int n){
int max=nt[0];
for(int t=0;t<n;t++)
{
  if(max<nt[t])
  max=nt[t];
}
  return max;
  }
