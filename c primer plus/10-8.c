#include <stdio.h>
void copy_arr(double *,const double *, int);
int main(void){
double source[5]={1.1,2.2,3.3,4.4,5.5};
double target1[3];
copy_arr(target1,&source[2],3);
for(int i=0;i<3;i++)
    printf("%lf ",target1[i]);
    putchar('\n');
return 0;
}
void copy_arr(double *dd, const double *mm, int t){
int i;

for(i=0;i<t;i++)
dd[i]=mm[i];
}
