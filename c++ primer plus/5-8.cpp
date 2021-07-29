#include <iostream>
#include <vector>
#include <cstring>
int main(){
    using namespace std;
    char ai[20][20];;
    cout <<"enter words (to stop, type the word done)\n";
    int i=0,count=0;
    char st[20];
    while(i<20&&cin>>st&&strcmp("done",st)!=0)
        {

            strcpy(ai[i],st);
            count++;
            i++;
        }
        cout <<"you entered a total of " <<count <<"words.";
        return 0;

    }
