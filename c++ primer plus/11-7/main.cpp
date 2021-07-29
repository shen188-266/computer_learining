#include <iostream>
#include "complex0.h"
using namespace std;

int main()
{
    complex a(3.0,4.0);
    complex c;
    cout <<"enter a complex numer (q to quit):\n";
    while (cin>>c)
    {
        cout<<"c is "<<c<<'\n';
        cout <<"complex conjugate is "<<~c<<'\n';
        cout <<"a is "<<a <<'\n';
        cout <<"a + c is "<<a+c<<'\n';
        cout <<"a - c is "<<a-c<<'\n';
        cout <<"a * c is "<<a*c<<'\n';
        cout <<"2 + c is "<<2*c<<'\n';
        cout <<"enter a complex number (q to quit):\n";
    }
    cout <<"done!\n";
    return 0;
}
