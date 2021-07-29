#include <iostream>
#include <cstring>


class Cow {
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm,const char * ho,double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void showCow() const;
    };

int main(){
     Cow jiangge("jiangge","study",50);
     Cow haoming(jiangge);
     Cow taojian;
     taojian=jiangge;
     jiangge.showCow();
     haoming.showCow();
     taojian.showCow();
     return 0;
}

Cow::Cow(){

    strcpy(name,"i am god!");
    hobby=nullptr;
    weight=0.0;}
Cow::Cow(const char * nm,const char * ho,double wt){
    strncpy(name,nm,20);
    int a=std::strlen(ho);
    hobby=new char[a+1];
    strcpy(hobby,ho);
    weight=wt;
}
Cow::~Cow(){
delete [] hobby;}
Cow::Cow(const Cow & c){
int a=std::strlen(c.hobby);
hobby=new char[a+1];
strcpy(hobby,c.hobby);
strcpy(name,"copy");
weight=40.0;}
Cow & Cow::operator=(const Cow & c){
if(this==&c)
    return *this;
delete [] hobby;
strcpy(name,c.name);
int a=std::strlen(c.hobby);
hobby=new char[a+1];
strcpy(hobby,c.hobby);
weight=c.weight;
}
void Cow::showCow() const{
std::cout<<"the name is: "<<name<<std::endl;
std::cout<<"the hobby is: "<<hobby<<std::endl;
std::cout<<"the weight is: "<<weight<<std::endl;
}
