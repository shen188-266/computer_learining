#include <iostream>
#include <cstring>
using namespace std;
struct candybar {
    string band;
    double weight;
    int calorie;};
int main(){
     using namespace std;
     candybar *snack = new candybar[3];

     snack[0] = {"mocha munch" ,2.3,350};
     snack[1]={"jskdfjk",3.3,201};
     snack[2]={"aksdkfak",2.3,201};
     cout << snack[0].band << "    " << snack[0].weight << "    " << snack[0].calorie;
     cout << endl;
     cout << snack[1].band << "    " << snack[1].weight << "    " << snack[1].calorie;
     cout << endl;
     cout << snack[2].band << "    " << snack[2].weight << "    " << snack[2].calorie;
     cout << endl;
     return 0;
     }
