#ifndef CH94_H_INCLUDED
#define CH94_H_INCLUDED

namespace SALES
{
    const int QUARTERS=4;
    struct Sales{
    double sales[QUARTERS];
    double average;
    double max1;
    double min1;};

    void setSales(Sales & s, double ar[], int n);
    void setSales(Sales & s);
    void showSales(const Sales & s);
}

#endif // CH94_H_INCLUDED
