#include <iostream>
using namespace std;
int count1=1;
void print(const char *st);
void print(const char *st,int n);
int main(){
     print("a;kalnvaonawjlns oij[ajdpfbprg\n");
     print("avalvjajlajal\n",2);
     print("jajsdvad\n",1);
     print("afhsudfhber gaerg a erguauegh auhguaag pgap\n",1);
     return 0 ;

}
void print(const char *st){
cout <<st;}
void print(const char *st,int n){
if(n<=0)
   {

    count1++;
    return;}
else{
    for(int i=0;i<count1;i++)
    {
        cout<<st;
    }
}count1++;

}
