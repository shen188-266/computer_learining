#include <iostream>
#include <cstring>
using namespace std;
struct piza {
    string company;
    float diameter;
    float weight;};
int main(){
    piza *pa= new piza;
    pa->company= "ksjdlfkj sjkdjf";
    cout << "how much size you want? ";

    cin >> pa->diameter;
    cout << "how much weight? ";

    cin >> pa->weight;
    cout << pa->company << '\t' << pa->diameter << '\t' << pa->weight;
    return  0;
}

