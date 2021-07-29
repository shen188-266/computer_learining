#include <iostream>
int main(){
    using namespace std;
   long long shijie;
   long long meiguo;
   cout << "enter the world's population: ";
   cin >> shijie;
   cout << "enter the population of the us: ";
   cin >> meiguo;
   cout << "the population of the US is " << 100.0*meiguo/shijie << "%% of the world population.\n";
   return 0;}
