#include <iostream>
int main(){
    using namespace std;
    cout <<"enter number od rows: ";
    int a;
    cin >> a;
    for (int i=0;i<a;i++)
        {
            for(int j=a-1-i;j>0;j--)
            {
                cout.put('.');
            }
            for(int n=0;n<=i;n++)
            {
                cout.put('*');
            }
            cout<<endl;
        }
        return 0;
    }
