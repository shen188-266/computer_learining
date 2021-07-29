#include <iostream>
using namespace std;
double add(double a,double b);
double multiply(double a,double b);
double calculate(double a,double b,double (*fu)(double a,double b));
int main(){
       double (*pa[2])(double a,double b);
       pa[0]=add;
       pa[1]=multiply;
       double a,b;
       cout <<"enter two double numeric: ";
       while(cin>>a>>b)
       {
           cout<<"the add is: "<<calculate(a,b,pa[0])<<endl;
           cout <<"the multiply is: "<<calculate(a,b,pa[1])<<endl;
           cout <<"enter two double numeric: ";
       }
       cout <<"bye";
       return 0;
       }
double add(double a,double b){
      return a+b;
}
double multiply(double a,double b){
      return a*b;
}
double calculate(double a,double b,double (*fu)(double a,double b)){
      return fu(a,b);
}
