#include <iostream>
using namespace std;
long double prob(int n,int a,int b);
int main(){
cout <<"enter how much ball_1 in total: ";
int n,a,b;
cin>>n;
cout <<"how much should you choose: ";
cin>>a;
cout <<"how much ball_2 in total: ";
cin>>b;
cout <<"the probability is one in "<<prob(n,a,b)<<endl;
return 0;}
long double prob(int n,int a,int b){
long double total=1;
while(a>0)
    {
        total=total*n/a;
        n--;
        a--;
    }
    total*=b;
    return total;
}
