#include <iostream>
using namespace std;
const int SLEN=30;
struct student {
      char fullname[SLEN];
      char hobby[SLEN];
      int ooplevel;};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[],int n);
int main(){
       cout <<"enter class size: ";
       int class_size;
       cin>>class_size;
       while (cin.get()!='\n')
            continue;
       student * ptr_stu=new student[class_size];
       int entered=getinfo(ptr_stu,class_size);
       for (int i=0;i<entered;i++)
       {
           display1(ptr_stu[i]);
           display2(&ptr_stu[i]);
       }
       cout.put('\n');
        cout.put('\n');
       display3(ptr_stu,entered);
       delete [] ptr_stu;
       cout << "done\n";
       return 0;
}
int getinfo(student pa[], int n){
    int i;
for (i=0;i<n;i++)
    {
        cout <<i+1<<endl<<"enter the fullname: ";
        cin.getline(pa[i].fullname,SLEN);
        cout <<"enter the hobby: ";
        cin.getline(pa[i].hobby,SLEN);
        cout<< "enter the ooplebel: ";
        cin>>pa[i].ooplevel;
        cin.get();

    }
    return i;
}
void display1(student st){
cout <<"the fullname is: "<<st.fullname<<endl;
cout <<"the hobby is: "<<st.hobby<<endl;
cout <<"the ooplebel is: "<<st.ooplevel<<endl;}
void display2(const student *ps){
cout <<"the fullname is: "<<ps->fullname<<endl;
cout <<"the hobby is: "<<ps->hobby<<endl;
cout <<"the ooplebel is: "<<ps->ooplevel<<endl;}
void display3(const student pa[],int n){
       int i;
for (i=0;i<n;i++)
    {
        cout <<i<<endl<<"the fullname is: "<<pa[i].fullname<<endl;

        cout <<"the hobby is: "<<pa[i].hobby<<endl;

        cout<< "the ooplebel is: "<<pa[i].ooplevel<<endl;


    }
}
