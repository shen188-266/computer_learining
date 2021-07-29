#include <iostream>
#include <cstring>
using namespace std;
int main(){
      struct juan {
      string member;
      double money;};
      int n;
      cout <<"enter how many people: ";
      cin >> n;
      cin.get();
      juan *pa=new juan[n];
      for(int i=0;i<n;i++)
      {
          cout <<i+1<<"enter the name: ";
          getline(cin,pa[i].member);
          cout <<"enter the money: ";
          cin>>pa[i].money;
          cin.get();
      }
      cout<<"grand patrons\n";
      for(int i=0;i<n;i++)
      {
          if(pa[i].money>10000)
            cout <<pa[i].money<<'\t'<<pa[i].member<<endl;
      }
      cout<<"patrons\n";
      for(int i=0;i<n;i++)
      {

          if(pa[i].money<10000)
            cout <<pa[i].money<<'\t'<<pa[i].member<<endl;
      }
      return 0;
}
