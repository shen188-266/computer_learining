#include <iostream>
using namespace std;
void fill(int ar[],int );
void show(const int ar[],int );
double average(const int ar[],int);
int main(){
         int ar[10];
         fill(ar,10);
         show(ar,10);
         cout <<average(ar,10);
         return 0;
}
void fill(int ar[],int n){
cout <<"NO.1 enter the grade(IF YOU WANT TO BREAK ENTER Q): ";
int i=0;
for(;i<n&&cin>>ar[i];i++)
    {
        if(i<9)
        cout <<"NO."<<i+2<<" enter the grade(IF YOU WANT TO BREAK ENTER Q): ";
    }
for(;i<10;i++)
    {
        ar[i]=0;
    }
}
void show(const int ar[],int n){
cout <<"the grade is : ";
int i=0;
for (;i<n&&ar[i]!=0;i++)
    cout <<ar[i]<<'\t';
    cout <<"\nthe total "<<i<<" people's average is: ";
    return;
}
double average(const int ar[],int n){
    int total=0;
    int i=0;
for(;i<n&&ar[i]!=0;i++)
    total+=ar[i];
if(i==n)
    return total/10.0;
else
    return total/double(i);
}
