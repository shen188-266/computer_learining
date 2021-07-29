#include <stdio.h>
void daoxu(double * shuzu, int n);
int main(void){
double shuz[]={3.0,4.3,53.3,2.3,3.4,53.2,654,4.3};
daoxu(shuz,8);
for(int t=0;t<8;t++)
printf("%lf ",shuz[t]);
return 0;
}
void daoxu(double * shuzu, int n){
int t,m=n-1;
double temp;
for(t=0;t<m;t++,m--)
{   temp=shuzu[t];
    shuzu[t]=shuzu[m];
    shuzu[m]=temp;}
}
