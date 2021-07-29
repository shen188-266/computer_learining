#include <stdio.h>

int Gcd(int a,int b);
int gcds(int a,int b);
int main(void)
{
    printf("%d",Gcd(12,8));
    return 0;
}

int Gcd(int a,int b)
{
    if(a>b)
        return gcds(a,b);
    else
        return gcds(b,a);
}

int gcds(int a,int b)
{
    int temp;
    while(b>0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
