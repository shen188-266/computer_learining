#include<stdio.h>
void copy_arr(double *,const double *, int);
int main(void){
double ao[][5]={{5.3,23.4,23.2,23.52,1.2},{2.345,2.3,52.35,23,5},{23.42,3.523,55.2,35.53}};
double tar[3][5];
copy_arr(tar[0],ao[0],5);
copy_arr(tar[1],ao[1],5);
copy_arr(tar[2],ao[2],4);
for(int i=0;i<3;i++)
{
    for(int j=0;j<5;j++)
        printf("%lf ",tar[i][j]);
    printf("\n");
}
return 0;
}
void copy_arr(double *dd, const double *mm, int t){
int i;

for(i=0;i<t;i++)
dd[i]=mm[i];


}
