#include <iostream>
int main(){
    using namespace std;
    int a;
    int b;
    cout << "enter two integer, and i will give you the um of all the integer between them.";
    cin>>a>>b;
    int sum=0;
    while (a<=b)
        {
            sum=sum+a;
            a++;
        }
    cout << "the total is " << sum << endl;
    return 0;
    }
