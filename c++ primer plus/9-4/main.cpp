#include <iostream>
#include "ch94.h"

int main()
{
    using namespace std;
    SALES::Sales aa;
    double str[4]={2.2 ,1.4,2.9,2.1};
    SALES::setSales(aa,str,SALES::QUARTERS);
    SALES::showSales(aa);

    SALES::setSales(aa);
    SALES::showSales(aa);

    return 0;
}
