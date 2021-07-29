#include <iostream>
int main(){
  using namespace std;
  double a,b,c;
  double d;
  cout << "enter a latitude in degrees, minutes, and seconfd:\n";
  cout << "first, enter the degrees: ";
  cin >> a;
  cout << "next, enter the minutes of arc: ";
  cin >> b;
  cout << "finally,enter the seconds of arc: ";
  cin >> c;
  d=a+b/60.0+c/360.0;
  cout << a <<" degrees, " << b << " minutes, " << c << "seconds = " << d <<" degrees";
  return 0;}
