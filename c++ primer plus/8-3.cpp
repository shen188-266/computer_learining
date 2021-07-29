#include <iostream>
#include <cstring>

using namespace std;
void TOupper(string &st);
int main(){
    cout <<"enter a string: ";
    string ad;
    while(getline(cin,ad)&&ad!="q")
    {
        TOupper(ad);
        cout<<ad<<endl;
        cout<<"enter a string: ";
    }
    return 0;
}
void TOupper(string &st){
    int i=0;
while(st[i])
    {
        st[i]=toupper(st[i]);
        i++;
    }
}
