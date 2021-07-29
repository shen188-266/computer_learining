#include <iostream>
using namespace std;
struct candy {
   char* company;
   double height;
   int calorie;};
void fills(candy & aa,char* st,double fj,int as);
int main(){
    candy jiji;
      fills(jiji,"millennuyb nnun",2.85,350);
      cout <<jiji.company<<'\t'<<jiji.height<<'\t'<<jiji.calorie;
      return 0;
}
void fills(candy & aa,char* st,double fj,int as){
    aa.company=st;
    aa.height=fj;
    aa.calorie=as;
}
