#include <iostream>
using namespace std;
double tiaohe(double a,double b);
int main(){
    double a,b;
      while(cin>>a>>b&&a!=0&&b!=0){
        cout <<tiaohe(a,b)<<endl;
      }
      return 0;
}
double tiaohe(double a,double b){
return 2.0*a*b/(a+b);}
