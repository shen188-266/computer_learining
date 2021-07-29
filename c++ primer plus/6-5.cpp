#include <iostream>
int main(){
      int a;
      using namespace std;
      cout << "enter your salary: ";

      float tax=0;
      while (cin >>a&&a>=0)
      {
          if(a<=5000)
            tax=0;
          else if (a>5000&&a<=15000){
            tax=0.1*(a-5000);
          }
          else if (a>15000&&a<=35000){
            tax=1000+0.15*(a-15000);
          }
          else if (a>35000){
            tax=1000+3000+0.2*(a-35000);
          }
          cout << "you need to give: "<<tax<<endl;

             cout << "enter your salary: ";
      }
      return 0;
}
