#include <iostream>
#include <cstring>
using namespace std;
struct piza {
    string company;
    float diameter;
    float weight;};
int main(){
    piza mypiza {
    "william wingate",
    };
    cout << "how much size you want? ";

    cin >> mypiza.diameter;
    cout << "how much weight? ";

    cin >> mypiza.weight;
    cout << mypiza.company << '\t' << mypiza.diameter << '\t' << mypiza.weight;
    return  0;
}

