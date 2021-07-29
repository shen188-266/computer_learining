#include <stdio.h>
double zupjj(const double * ar,int n);
double all_average(double ar[][5],int n);
double max(double ar[][5],int n);
int main(void){
    int i=0;
double ar[3][5],zupj[3];
printf("please input 3 group number and every group should have 5 numbers.\n");
do{
printf("please input the %d group(contain 5 numbers)\n",i+1);
 for(int j=0;j<5;j++)
     scanf("%lf",&ar[i][j]);
   }while(++i<3);
for(int t=0;t<3;t++)
   zupj[t]=zupjj(ar[t],5);
printf("the average of first group is %lf,second is %lf,third is %lf\n",zupj[0],zupj[1],zupj[2]);
printf("the average of all numbers is %lf\n",all_average(ar,3));
printf("the max is %lf\n",max(ar,3));
return 0;
}
double zupjj(const double * ar,int n){
double a=0;
for(int i=0;i<n;i++)
   a+=ar[i];
return a/n;}
double all_average(double ar[][5],int n){
int i=0;
double a=0;
for (;i<n;i++)
   for(int j=0;j<5;j++)
      a+=ar[i][j];
return a/(5*n);}
double max(double ar[][5],int n){
int i=0;
double ma=ar[0][0];
for (;i<n;i++)
   for(int j=0;j<5;j++)
      if(ma<ar[i][j])
         ma=ar[i][j];
return ma;}
