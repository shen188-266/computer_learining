#include "person.h"
#include <iostream>
#include <cstring>
Person::Person(const string & ln, const char * fn){
    lname=ln;
    strncpy(fname,fn,LIMIT);
}
void Person::Show() const{
    using std::cout;
    using std::endl;
    cout<<"the lname is: "<<lname<<", the fname is: "<<fname<<endl;

}
void Person::FormalShow() const{
    using std::cout;
    using std::endl;
    cout<<"the fname is: "<<fname<<", the lname is: "<<lname<<endl;
}
