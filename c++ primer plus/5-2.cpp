#include <iostream>
#include <array>
using namespace std;
int main(){
    array<long long,16> ai;
    ai[0]=1,ai[1]=1;
    for (int i=2;i<16;i++)
        {
            ai[i]=i*ai[i-1];
        }
    for (int i=0;i<16;i++)
    {
        cout <<i<<"!= " <<ai[i]<<endl;
    }
    return 0;
    }
