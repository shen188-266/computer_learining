#include <stdio.h>

int PowB(int a,int b);

int main(void)
{
    printf("%d",PowB(2,3));
    return 0;
}

int PowB(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;

    if(b%2)
    {
        return PowB(a*a,b/2)*a;
    }
    else
        return PowB(a*a,b/2);
}
