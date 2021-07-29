#include<stdio.h>
void x2_bianchang2(int a, int b, double ar[a][b]);
void print_bainchang2(int a,int b, double ar[a][b]);
int main(void){
double ao[][5]={{5.3,23.4,23.2,23.52,1.2},{2.345,2.3,52.35,23,5},{23.42,3.523,55.2,35.53,3.5}};
double tar[3][5];
print_bainchang2(3,5,ao);
x2_bianchang2(3,5,ao);
print_bainchang2(3,5,ao);
return 0;
}
void x2_bianchang2(int a, int b, double ar[a][b]){
int i,j;
for(i=0;i<a;i++)
    for(j=0;j<b;j++)
      ar[i][j]=2*ar[i][j];}
void print_bainchang2(int a,int b, double ar[a][b]){
int i,j;
for(i=0;i<a;i++)
    {for(j=0;j<b;j++)
      printf("%lf ",ar[i][j]);
      printf("\n");}}
