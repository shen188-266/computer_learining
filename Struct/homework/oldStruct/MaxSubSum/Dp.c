#include <stdio.h>
int MaxSubSum(const int A[],int n);
int main(void){
    int A[7]={1,-5,3,-2,4,6,-3};
    printf("%d",MaxSubSum(A,7));
    return 0;
}
int MaxSubSum(const int A[],int n)
{
    int maxs=0,temp=0;
    for(int i=0;i<n;i++)
    {
        temp+=A[i];
        if(temp>maxs)
            maxs=temp;
        if(temp<0)
            temp=0;
    }
    return maxs;
}
