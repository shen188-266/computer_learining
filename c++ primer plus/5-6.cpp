#include <iostream>
using namespace std;
int main(){
      int sale[3][12];
      int i,j;
      char* year[3]={"first","second","third"};
      for (i=0;i<3;i++)
        {
            cout << "enter the sale of the "<<year[i]<<" year."<<endl;
            for (j=0;j<12;j++)
            {
                cout << "     enter the sale of "<<j+1<<" month: ";
                cin>>sale[i][j];
            }
        }
        int sum=0;
    for(i=0;i<3;i++)
    {
        for (j=0;j<12;j++)
        {
            sum+=sale[i][j];
        }
    }
    cout <<"\n sum= "<< sum;
    return 0;
      }
