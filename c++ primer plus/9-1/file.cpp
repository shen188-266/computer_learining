#include "myh"
#include <iostream>
#include <cstring>
void setgolf(golf & g,const char * name, int hc){
     strncpy(g.fullname,name,Len);
     g.handicap=hc;
}
int setgolf(golf & g){
std::cout<<"enter the name: ";
std::cin.getline(g.fullname,Len);
std::cout<<"enter the handicap: ";
std::cin>>g.handicap;
if(strlen(g.fullname)!=0)
    return 1;
    else return 0;
}
void handicap(golf & g,int hc){
g.handicap=hc;}
void showgolf(const golf & g){
std::cout<<"the name is "<<g.fullname<<" ,and the handicap is "<<g.handicap<<std::endl;}
