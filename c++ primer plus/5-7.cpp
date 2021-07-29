#include <iostream>
using namespace std;
struct car {
     string company;
     int year;
     };
int main(){
    cout <<"how much cars do you have?\n";
    int n;
    cin>>n;
    cin.get();
    car *pa=new car[n];
    for (int i=0;i<n;i++)
        {
            cout << "car "<<i+1<<":\n";
            cout << "please enter the make: ";
            getline(cin,pa[i].company);
            cout << "please enter the year made: ";
            cin>>pa[i].year;
            cin.get();
        }
    cout <<"here is your collection.\n";
         for (int i=0;i<n;i++)
         {
             cout <<pa[i].year<<'\t'<<pa[i].company<<endl;
         }
         return 0;
    }
