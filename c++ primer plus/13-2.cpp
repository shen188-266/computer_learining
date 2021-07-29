#include <iostream>
#include <cstring>

using namespace std;

class Cd {
private:
    char *performers;
    char *label;
    int selections;
    double playtime;
public:
    Cd(const char *s1,const char *s2,int n,double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd {
private:
    char * masterp;
public:
    Classic();
    Classic(const Classic & d);
    Classic(const char *s1,const char *s2,int n,double x,const char *s3);
    Classic(Cd & d,char *s3);
    virtual ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & d);

};

void Bravo(const Cd & disk);

int main()
{
    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C","Alfred Brendel",2,57.17,"Philips");
    Cd *pcd=&c1;

    cout<<"Using object directly:\n";
    c1.Report();
    pcd->Report();
    pcd=&c2;
    pcd->Report();

    cout <<"Calling a dunction with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout <<"Testing assignment: ";
    Classic copy;
    copy=c2;
    copy.Report();

    return 0;

}

void Bravo(const Cd &disk)
{
    disk.Report();
}

Cd::Cd(){
performers=nullptr;
label=nullptr;
selections=0;
playtime=0;}
Cd::Cd(const char *s1,const char *s2,int n,double x)
{
    int a,b;
    a=std::strlen(s1);
    b=std::strlen(s2);
    performers=new char[a+1];
    label=new char[b+1];
    strcpy(performers,s1);
    strcpy(label,s2);
    selections=n;
    playtime=x;
}
Cd::Cd(const Cd & d)
{
    int a,b;
    a=std::strlen(d.performers);
    b=std::strlen(d.label);
    performers=new char[a+1];
    label=new char[b+1];
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}
Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}
void Cd::Report() const
{
    cout<<"performers is: "<<performers<<endl;
    cout<<"label is: "<<label<<endl;
    cout<<"selections is: "<<selections<<endl;
    cout<<"playtime is: "<<playtime<<endl;
}
Cd & Cd::operator=(const Cd & d)
{
    if(this==&d)
        return *this;
    delete [] performers;
    delete [] label;
    int a,b;
    a=std::strlen(d.performers);
    b=std::strlen(d.label);
    performers=new char[a+1];
    label=new char[b+1];
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
    return *this;
}
Classic::Classic()
{
    masterp=0;
}
Classic::Classic(const Classic & d) :Cd(d)
{
    int c=strlen(d.masterp);
    masterp=new char[c+1];
    strcpy(masterp,d.masterp);
}
Classic::Classic(const char *s1,const char *s2,int n,double x,const char *s3)
:Cd(s1,s2,n,x)
{
    int c=strlen(s3);
    masterp=new char[c+1];
    strcpy(masterp,s3);
}
Classic::Classic(Cd & d,char *s3):Cd(d)
{
    int c=strlen(s3);
    masterp=new char[c+1];
    strcpy(masterp,s3);
}
Classic:: ~Classic()
{
    delete [] masterp;
}
void Classic::Report() const
{
    Cd::Report();
    cout<<"the main work is: "<<masterp<<endl;
}
Classic & Classic::operator=(const Classic & d)
{
    if(this==&d)
        return *this;
    Cd::operator=(d);
    delete [] masterp;
    int c=strlen(d.masterp);
    masterp=new char[c+1];
    strcpy(masterp,d.masterp);
    return *this;
}
