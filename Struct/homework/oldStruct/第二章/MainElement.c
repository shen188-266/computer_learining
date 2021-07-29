#include <stdio.h>

int MainElement(const int A[],int n);

int main(void)
{
    int A[6]={1,4,2,4,4,4};
    int b=MainElement(A,6);
    return 0;
}

int MainElement(const int A[],int n)
{
    int counts=0;
    int a=n%2;
    const int m=(a)?n/2+1;n/2;
    for(int i=0;i<n;i=i+2)
    {
        if(A[i]==A[i+1])
        {
            B[counts]=A[i];
            counts++;
        }
    }
    if(a)
    {
        B[counts]=A[n-1];
            counts++;
    }
    if(counts==0)
        return -1;
    else if(counts==1)
        return B[0];
    else
    return MainElement(B,counts);
}
