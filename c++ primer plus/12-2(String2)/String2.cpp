#include <cstring>
#include <cctype>
#include "String2.h"

using std::cin;
using std::cout;

int String::num_strings=0;

int String::HowMany(){
return num_strings;}
String::String(const char * s){
len=std::strlen(s);
str=new char[len+1];
strcpy(str,s);
num_strings++;}

String::String(){
len=4;
str=new char[1];
str[0]='\0';
num_strings++;}

String::String (const String & st){
num_strings++;
len=st.len;
str=new char [len+1];
strcpy(str,st.str);}

String::~String(){
--num_strings;
delete [] str;}

String & String::operator=(const String & st){
if(this==&st)
    return *this;
    delete [] str;
    len=st.len;
    str=new char [len+1];
    std::strcpy(str,st.str);
    return *this;
}
String & String::operator=(const char * s){
delete [] str;
len=std::strlen(s);
str=new char[len+1];
std::strcpy(str,s);
return *this;}

char & String::operator[](int i){
return str[i];}
const char & String::operator[](int i ) const{
return str[i];}

bool operator<(const String &st1,const String &st2){
return (strcmp(st1.str,st2.str)==0);}
bool operator>(const String &st1,const String &st2){
return st2<st1;}

bool operator==(const String & st1,const String &st2){
return (strcmp(st1.str,st2.str)==0);}

ostream & operator<<(ostream &os,const String & st){
os<<st.str;
return os;}

istream & operator>>(istream & is,String & st){
char temp[String::CINLIM];
is.get(temp,String::CINLIM);
if(is)
    st=temp;
while (is && is.get()!='\n')
    continue;
return is;
}
String operator+(const String &st1,const String &st2){
String stx;
stx.str=new char[st1.len+st2.len+1];
strcpy(stx.str,st1.str);
strcat(stx.str,st2.str);
stx.len=st1.len+st2.len;
return stx;}

String String::Stringlower(){
String stl;
stl=new char[len+1];
strcpy(stl.str,str);
int i=0;
while(stl.str[i])
{
    if(isalpha(stl.str[i]))
        stl.str[i]=tolower(stl.str[i]);
    i++;
}
stl.len=len;
return stl;
}
String String::Stringupper(){
String stl;
stl=new char[len+1];
strcpy(stl.str,str);
int i=0;
while(stl.str[i])
{
    if(isalpha(stl.str[i]))
        stl.str[i]=toupper(stl.str[i]);
    i++;
}
stl.len=len;
return stl;
}
int String::Stringtimes(char c){
int number;
char *stt=str;
while(*stt)
    if(*stt++==c)
        number++;
return number;
}
