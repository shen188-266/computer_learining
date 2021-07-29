#include<stdio.h>
void add_copy(int *diyi,int * dier,int *tar,int n);
int main(void){
int diyi[]={2,4,5,8};
int dier[]={1,0,4,6};
int tar[5];
add_copy(diyi,dier,tar,5);
for(int i=0;i<4;i++)
  printf("%d ",tar[i]);
return 0;}
void add_copy(int *diyi,int * dier,int *tar,int n){
for(int i=0;i<n;i++)
    tar[i]=diyi[i]+dier[i];
}
