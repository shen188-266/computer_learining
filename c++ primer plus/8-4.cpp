#include <iostream>
using namespace std;
#include <cstring>
struct stringy {
     char * str;
     int ct;};
void show(const stringy& ad,int n=1);
void show(const char*st,int n=1);
void set(stringy& ad,char* st);
int main(){
      stringy beany;
      char testing[]="reality isn't what it used to be.";

      set(beany,testing);
      show(beany);
      show(beany,2);
      testing[0]='D';
      testing[1]='u';
      show(testing);
      show(testing,3);
      show("done!");
      delete [] beany.str;
      return 0;
}
void show(const stringy& ad,int n){
    for(int i=0;i<n;i++)
    {
        cout<<ad.str<<endl;
    }
}
void show(const char*st,int n){
for(int i=0;i<n;i++)
    {
        cout<<st<<endl;
    }
}
void set(stringy& ad,char* st){
char * sh=new char[sizeof(st)+1];
strcpy(sh,st);
ad.str=sh;
ad.ct=10;}
