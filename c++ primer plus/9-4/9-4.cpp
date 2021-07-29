#include <cstring>
#include <iostream>
#include "9-4\ch94.h"
namespace SALES
{
    void setSales(Sales & s, double ar[], int n){
    n=(n<4)?n:4;

    memcpy(s.sales,ar,n);
     std::cout<<"the sales is: "<<s.sales[0]<<'\t'<<s.sales[1]<<'\t'<<s.sales[2]<<'\t'<<s.sales[3]<<std::endl;
    double total=0.0;
    double ma,mi;
    ma=mi=s.sales[0];
    for (int i=0;i<n;i++)
    {
        total+=s.sales[i];
        if(ma<s.sales[i])
            ma=s.sales[i];
        if(mi>s.sales[i])
            mi=s.sales[i];

    }
    s.average=total/n;
    s.max1=ma;
    s.min1=mi;
    }
    void setSales(Sales & s){
           std::cout <<"enter 4 double : ";
           std::cin>>s.sales[0]>>s.sales[1]>>s.sales[2]>>s.sales[3];
    double total=0.0;
    double ma,mi;
    ma=mi=s.sales[0];
    for (int i=0;i<4;i++)
    {
        total+=s.sales[i];
        if(ma<s.sales[i])
            ma=s.sales[i];
        if(mi>s.sales[i])
            mi=s.sales[i];

    }
    s.average=total/4;
    s.max1=ma;
    s.min1=mi;

    }
    void showSales(const Sales & s){
    std::cout<<"the sales is: "<<s.sales[0]<<'\t'<<s.sales[1]<<'\t'<<s.sales[2]<<'\t'<<s.sales[3]<<std::endl
    <<"\tthe average is: "<<s.average<<"\tthe max is: "<<s.max1
    <<"\tthe min is: "<<s.min1<<std::endl;
    }
}
