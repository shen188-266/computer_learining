#include <iostream>
#include <cstring>

using namespace std;

class Port {
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char * br="none",const char * st="none", int b=0);
    Port(const Port & p);
    virtual ~Port() {delete [] brand;}
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount() const {return bottles;}
    virtual void Show() const;
    friend ostream & operator<<(ostream & os,const Port & p);
};

class VintagePort : public Port {
private:
    char * nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char * br,const char * st,int b,const char * nn,int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() {delete [] nickname;}
    VintagePort & operator=(const VintagePort & vp);
    void Show() const ;
    friend ostream & operator<<(ostream & os,const VintagePort & vp);
};

bool modeT();
int pzheng();

static int mod;

int main()
{
    Port * wod[10]={0};
    char temp1[20];
    char temp2[20];
    int bottle;
    cout<<"0:port    1:vintageport\n"
    <<"enter the mode(q to quit): ";
    for(int i=0;i<10&&modeT();i++)
    {
        cout<<"enter the brand: ";
        cin.get(temp1,20).get();
        cout<<"enter the style: ";
        cin.get(temp2,20).get();
        cout <<"enter the bottles: ";
        bottle=pzheng();
        if(mod==0)
        {
            wod[i]=new Port(temp1,temp2,bottle);
        }
        if(mod==1)
        {
            cout<<"enter the nickname: ";
            char temp[20];
            cin.get(temp,20).get();
            cout<<"enter the year: ";
            int y;
            y=pzheng();
            wod[i]=new VintagePort(temp1,temp2,bottle,temp,y);
        }
        cout<<"0:port    1:vintageport\n"<<"enter the mode(q to quit): ";
    }

    cout<<"use show:\n";
    for(int i=0;i<10&&wod[i];i++)
    {
        cout<<i+1<<": ";
        wod[i]->Show();
    }

    cout<<"\n\nuse cout<<:\n";
    for(int i=0;i<10&&wod[i];i++)
    {
        cout<<i+1<<": ";
        cout<<*wod[i];
    }

    for (int i=0;i<10;i++)
    {
        delete [] wod[i];
    }

    return 0;
}

bool modeT()
{
    while(cin>>mod)
    {
        if(mod==1||mod==0)
            break;
    }
    if(cin)
        {
            cin.get();
            return 1;}
    else
        return 0;
}
int pzheng()
{
    int a;
    cin>>a;
    int c=1;
    while(c)
    {
        if(!cin)
        {
            cin.clear();
            while(cin.get()!='\n'&&cin)
                continue;
        }
        while(a<0&&cin)
        {
            cout<<"enter again!"<<endl;
            cin>>a;
        }
        if(a>=0)
            c=0;
    }
    cin.get();
    return a;
}

Port::Port(const char * br,const char * st, int b)
{
    brand=new char[strlen(br)+1];
    strcpy(brand,br);
    strncpy(style,st,20);
    bottles=b;
}
Port::Port(const Port & p)
{
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strncpy(style,p.style,20);
    bottles=p.bottles;
}
Port & Port::operator=(const Port & p)
{
    if(this==&p)
       return *this;
    delete [] brand;
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strncpy(style,p.style,20);
    bottles=p.bottles;
    return *this;
}
Port & Port::operator+=(int b)
{
    bottles+=b;
    return *this;
}
Port & Port::operator-=(int b)
{
    bottles-=b;
    return *this;
}
void Port::Show() const
{
    cout<<"Brand: "<<brand<<endl;
    cout<<"Kind: "<<style<<endl;
    cout<<"Bottles: "<<bottles<<endl;
}
ostream & operator<<(ostream & os,const Port & p)
{
    os<<p.brand<<", "<<p.style<<", "<<p.bottles<<endl;
    return os;
}
VintagePort::VintagePort()
{
    nickname=0;
    year=0;
}
VintagePort::VintagePort(const char * br,const char * st,int b,const char * nn,int y)
:Port(br,st,b)
{
    nickname=new char[strlen(nn)+1];
    strcpy(nickname,nn);
    year=y;
}
VintagePort::VintagePort(const VintagePort & vp):Port(vp)
{
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this==&vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
    return *this;
}
void VintagePort::Show() const
{
    Port::Show();
    cout<<"nickname: "<<nickname<<endl;
    cout<<"year: "<<year<<endl;
}
ostream & operator<<(ostream & os,const VintagePort & vp)
{
    os<<(Port)vp;
    os<<"-"<<vp.nickname<<", "<<vp.year<<endl;
    return os;
}
