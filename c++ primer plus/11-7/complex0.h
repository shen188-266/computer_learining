#ifndef COMPLEX0_H_INCLUDED
#define COMPLEX0_H_INCLUDED
#include <iostream>
class complex {
private:
    double shi;
    double xu;
public:
    complex();
    complex(double a,double b);
    ~complex(){};
    complex operator+(const complex & co);
    complex operator-(const complex & co);
    complex operator*(const complex & co);
    friend complex operator*(const double a,const complex & co);
    complex operator~();
    friend std::ostream & operator<<(std::ostream & sj,const complex & co);
    friend std::istream & operator>>(std::istream & sj, complex & co);};

#endif // COMPLEX0_H_INCLUDED
