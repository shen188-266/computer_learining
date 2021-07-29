#include <iostream>
#include <new>

struct chaff {
       char dross[20];
       int slag;};
chaff * fills();
void showchaff(chaff * pa);

char buf[1024];
int main(){
using namespace std;
chaff *ps;
do {
ps=fills();
showchaff(ps);}while(cin.get()!='q');
return 0;
}


chaff * fills(){
using namespace std;
       cout <<"first\nenter the dross: ";

       chaff *pa=new (buf) chaff[2];
       cin.getline(pa[0].dross,20);
       cout<<"enter the slag: ";
       cin>>pa[0].slag;
       cin.get();

       cout <<"second\nenter the dross: ";
       cin.getline(pa[1].dross,20);
       cout<<"enter the slag: ";
       cin>>pa[1].slag;
       cin.get();



       return pa;

}
void showchaff(chaff * pa){
    using namespace std;
       cout <<"\nfirst\nthe dross is: "<<pa[0].dross;
       cout<<"\nthe slag is: "<<pa[0].slag;

       cout <<"\nsecond\nthe dross is: "<<pa[1].dross;
       cout<<"the slag is: "<<pa[1].slag;

             cout<<"\nenter q to quit,other to continue: ";

       //delete [] pa;

}
