#include <iostream>
#include "person.h"

int main()
{
    using std::cout;
    using std::endl;
    Person one;
    Person two("Smythecraft");
    Person three={"Dimwiddy","Sam"};
    one.Show();
    cout<<endl;
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();
    return 0;
}
