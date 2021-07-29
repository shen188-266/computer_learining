#include <iostream>
#include <array>
int main(){
    using namespace std;
     array<int,12> sales;
     int i=0;
     while (i<12)
        {
            cout<< "enter a number of "<<i+1<<": ";
            cin >> sales[i];
            i++;
        }
    int sum=0;
     for (int j=0;j<12;j++)
     {
         sum+=sales[j];
     }
     cout <<"all is : "<<sum;
     return 0;
     }

