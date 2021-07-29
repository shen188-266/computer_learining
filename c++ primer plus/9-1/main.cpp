#include <iostream>
#include "myh"
using namespace std;

int main()
{
    golf a[2];
    setgolf(a[0],"jjcfn",12);
    setgolf(a[1]);
    showgolf(a[0]);
    showgolf(a[1]);

    handicap(a[0],8);
    showgolf(a[0]);
    showgolf(a[1]);
    return 0;
}
