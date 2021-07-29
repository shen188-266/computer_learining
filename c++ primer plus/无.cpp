
#include<iostream>

using namespace std;
int xsh(int i)
{
    int a=1,sum=0;
    while(i/10) a++;
    int sh[a];
    for(int m=0;m<a;m++)
    {
        sh[m]=i%10;
        i/=10;
    }
    for(int m=0;m<a;m++)
    sum+=sh[m]*sh[m]*sh[m];

    return sum;
}
int main()
{
    int a,b,count=0;

    cin>>a>>b;
    for(int i=a;i<=b;i++)
     if(i==xsh(i))
     {count++;
       cout<<i<<' ';}

    if(count==0) cout<<"no";





  return 0;
}
/********** End **********/

