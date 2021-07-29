#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void srsz(int * shuzu,int size,int n);
int main(void){
int shuzu[10]={1,2,3,4,5,7,19,22,31,14};
srsz(shuzu,10,3);
return 0;}
void srsz(int * shuzu,int size,int n){
    if(size<n)
        exit(1);
srand((unsigned int)time(0));
int temp[n];
for(int i=0;i<n;i++)
{temp[i]=rand()%10;

    for(int j=i;j>0;j--)
    {
        if(temp[i]==temp[j-1])
            i--;
    }
 }
for(int i=0;i<n;i++)
{
    printf("%5d",shuzu[temp[i]]);
    if(i%5==4)
        putchar('\n');
}}
