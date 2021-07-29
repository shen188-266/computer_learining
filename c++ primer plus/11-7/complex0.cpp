#include <iostream>
#include "complex0.h"
using std::cout;
complex::complex(){
  cout<<"using default\n";
  shi=0;
  xu=0;}
complex::complex(double a,double b){
    shi=a;
    xu=b;}
complex complex::operator+(const complex & co){
       complex ab;
       ab.shi=shi+co.shi;
       ab.xu=xu+co.xu;
       return ab;}
complex complex::operator-(const complex & co){
        complex ab(shi-co.shi,xu-co.xu);
      return ab;
    }
complex complex::operator*(const complex & co){
        complex ab;
       ab.shi=shi*co.shi-xu*co.xu;
       ab.xu=shi*co.xu+xu*co.shi;
       return ab;}
complex operator*(const double a,const complex & co){
    complex ab(a*co.shi,a*co.xu);
    return ab;}
complex complex::operator~(){
    complex ab(shi,-xu);
    return ab;
    }
std::ostream & operator<<(std::ostream & sj,const complex & co){
    sj<<"("<<co.shi<<","<<co.xu<<"i)";
    return sj;}
std::istream & operator>>(std::istream & sj, complex & co){
     sj>>co.shi>>co.xu;
     return sj;}
