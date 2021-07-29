#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>
#include <iostream>
using std::string;
class Person {
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
public:
    Person(){lname ="";fname[0]='\0';}
    Person(const string & ln, const char * fn="heyyou");
    ~Person(){std::cout<<"bye!";}
    void Show() const;
    void FormalShow() const;
};

#endif // PERSON_H_INCLUDED
