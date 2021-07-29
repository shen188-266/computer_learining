#include <iostream>
#include <cstring>
int main(){
    using namespace std;
    char first[20];
    cout << "enter your first name: ";
    cin.getline(first,20);
    string last;
    cout << "enter your last name: ";
    cin >> last;
    cout << "here's the information in a single string: " << last << ", " << first;
    return 0;}
