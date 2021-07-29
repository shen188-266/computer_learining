#include <iostream>
using namespace std;
int main(){
    double dap=100.00001;
    double cle=100.00000;
    int count=0;
    while (cle<dap)
        {
            dap+=10.0;
            cle+=0.05*cle;
            count++;
        }
    cout << count << "year after, "<<cle<<"   "<<dap;
    return 0;
    }
