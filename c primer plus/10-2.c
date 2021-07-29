//使用3种方法拷贝source，哪儿错了？
#include <stdio.h>
void copy_arr(double *,const double *, int);
void copy_ptr(double *,const double *, int);
void copy_ptrs(double *, double *, double *);
int main(void)
{    int i;
    double source[5]={1.1,2.2,3.3,4.4,5.5};
double target1[5];
double target2[5];
double target3[5];
copy_arr(target1,source,5);
for(i=0;i<5;i++)
    printf("%lf!",target1[i]);
    putchar('\n');
copy_ptr(target2,source,5);
for(i=0;i<5;i++)
    printf("%lf@",target2[i]);
    putchar('\n');
copy_ptrs(target3,source,source+5);
for(i=0;i<5;i++)
    printf("%lf#",target3[i]);
    putchar('\n');
return 0;
}
void copy_arr(double *dd, const double *mm, int t){
int i;

for(i=0;i<t;i++)
dd[i]=mm[i];


}
void copy_ptr(double *dd,const double *mm, int t){
    int i;
//要不要加，加与不加有何区别？上面的void copy_arr(double *dd, const double *mm, int t)也是
for(i=0;i<t;i++)
*dd++=mm[i];

}
void copy_ptrs(double *dd, double *mm, double *mmd){
int t=0;
while(&mm[t]<mmd)
*dd++=mm[t++];

}
