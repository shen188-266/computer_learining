#include <stdio.h>

int PowW(int a,int b);

int main(void)
{
    printf("%d",PowW(2,10));
    return 0;
}

int PowW(int a,int b)
{
    int ans=1,base=a;
    while(b!=0)
    {
        if(b&1)
            ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}
