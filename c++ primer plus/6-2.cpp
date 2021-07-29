#include <iostream>
int main(){
    using namespace std;
    double donation[10],total=0.0;
    int i,count;
    i=count=0;
    while (i<10&&cin>>donation[i])
        {
            total+=donation[i++];
            count++;
        }
    double averege=total/count;
    int lco=0;
    for (int i=0;i<10;i++)
    {
        if(donation[i]>averege)
            lco++;
    }
    cout <<"the average is "<<averege<<endl;
    cout <<"the number of lagarer than average is "<<lco;
    return 0;
    }
