#include <iostream>
using namespace std;
long long jiecheng(long long n);
int main(){
       long long a;
       cout <<"enter an integer to compute jiecheng: ";
       cin>>a;
       cout<<jiecheng(a);
       return 0;}
long long jiecheng(long long n){
if(n>0)
    n*=jiecheng(n-1);
else
    n=1;
    return n;
}
