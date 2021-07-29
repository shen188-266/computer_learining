#include <iostream>

#include <cstring>
int main(){
    using namespace std;
    string ai[20];
    cout <<"enter words (to stop, type the word done)\n";
    int i=0,count=0;
    string st;
    while(i<20&&cin>>st&&"done"!=st)
        {

            ai[i]=st;
            count++;
            i++;
        }
        cout <<"you entered a total of " <<count <<"words.";
        return 0;

    }
