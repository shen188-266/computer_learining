#include <iostream>
#include <cstring>
using namespace std;
void menu();
int main(){
     const int size = 20;
     struct bope {
        char full[size];
        char title[size];
        char bop[size];
        int preference;};
        bope humen[3] ={
        {"sjdfk sjdk","jjsk","bj",1},
        {"asldf sdj","fkk","sl",2},
        {"sdh sdsjhj","sdls","as",0}};
    menu();
    cout <<"enter a choice: ";
    char ch;
    cin>>ch;
    while(ch!='q')
    {
        while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'&&ch!='q')
        {
            cout << "please enter a letter among a,b,c,d,q\n";
            cin>>ch;
        }
        switch(ch)
        {
            case 'a':for (int i=0;i<3;i++)
            {
                cout << humen[i].full<<endl;
            }break;
            case 'b':for (int i=0;i<3;i++)
            {
                cout << humen[i].title<<endl;
            }break;
            case 'c':for (int i=0;i<3;i++)
            {
                cout << humen[i].bop<<endl;
            }break;
            case 'd': for (int i=0;i<3;i++)
                         {
                switch (humen[i].preference)
                {case 0:cout << humen[i].full<<endl;
                break;
                case 1:cout << humen[i].title<<endl;
                break;
                case 2:cout << humen[i].bop<<endl;
                break;
                }

              }
         }
         cin>>ch;
    }
    return 0;}

void menu(){
    cout << "benevolent order of programmers report\n";
    cout <<"a.display by name      b.display by title"<<endl
          <<"c.display by bopname   d.display by preference\n"
          <<"q.quit";

    }
