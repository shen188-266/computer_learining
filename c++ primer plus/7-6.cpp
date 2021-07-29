#include <iostream>
using namespace std;
int fillit(double *ar,int n);
void show(double *ar,int n);
void reverseit(double *ar,int n);
int main(){
      double ar[10];
      int n=fillit(ar,10);
      cout <<n<<endl;
      show(ar,n);
      reverseit(ar,n);
      show(ar,n);
      reverseit(ar,n);
      reverseit(ar+1,n-2);
      show(ar,n);
      return 0;
}
int fillit(double *ar,int n){
cout <<"1  enter a double numeric: ";
cin>>ar[0];
int i=1;
while(i<10&&cin)
    {
        cout <<i+1<<"enter a double numeric: ";
        cin>>ar[i];

        i++;
    }
    if(!cin)
    {
        i--;
    }
    return i;
}
void show(double *ar,int n){
for(int i=0;i<n;i++)
{
    cout <<ar[i]<<"  ";
}
cout.put('\n');
}
void reverseit(double *ar,int n){
for(int i=0;i<n-1;i++,n--)
    {
        double temp;
        temp=ar[i];
        ar[i]=ar[n-1];
        ar[n-1]=temp;
    }
}
