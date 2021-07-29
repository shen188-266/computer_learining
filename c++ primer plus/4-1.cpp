#include <iostream>
int main(){
    using namespace std;
    cout << "what is your first name? ";
    char first[20];
    cin.getline(first,20);
    cout << "what is your last name? ";
    char last[20];
    cin.getline(last,20);
    char grade;
    cout << "what letter grade di you deserve? ";
    cin >> grade;
    int age;
    cout << "what is your age? ";
    cin >> age;
    cout << "name: " << first << ", " << last;
    cout << endl;
    cout << "grade: " << char(grade+1);
    cout << endl;
    cout << "age: " << age;
    return 0;}
