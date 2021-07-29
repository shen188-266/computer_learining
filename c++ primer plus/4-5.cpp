#include <iostream>
#include <cstring>
using namespace std;
struct candybar {
    string band;
    double weight;
    int calorie;};
int main(){
     using namespace std;
     candybar snack={
     "mocha munch" ,
     2.3,
     350};
     cout << snack.band << snack.weight << snack.calorie;
     return 0;
     }
