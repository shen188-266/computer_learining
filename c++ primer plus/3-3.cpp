#include <iostream>
int main(){
    using namespace std;
    const int q=365;
    const int w=24;
    const int e=60;
    int a,b,c,d,t;
    long sec;
    cout << "enter the number of seconds: ";
    cin >> sec;
    d=sec%e;
    t=sec/e;
    c=t%e;
    t/=e;
    b=t%w;
    a=t/w;



    cout << sec << " seconds = " << a << "days, " << b << "hours, " << c << "minutes, " << d << " seconds";
    return 0;}
