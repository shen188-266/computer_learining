#include <iostream>
#include "String2.h"

using namespace std;

int main()
{
    String s1(" and i am a c++ student.");
    String s2="please enter your name: ";
    String s3;
    cout<<s2;
    cin>>s3;
    s2="My name is "+s3;
    cout <<s2<<".\n";
    s2=s2+s1;
    s2=s2.Stringupper();
    cout<<"the string\n"<<s2<<"\ncontains "<<s2.Stringtimes('A')<<" 'A' characters in it.\n";
    s1="red";
    String rgb[3]={String(s1),String("green"),String("blue")};
    cout <<"enter the name of a primary color for mixing light: ";
    String ans;
    bool success=false;
    while (cin>>ans)
    {
        ans=ans.Stringlower();
        for (int i=0;i<3;i++)
        {
            if(ans==rgb[i])
            {
                cout<<"that's right!\n";
                success=true;
                break;
            }
        }
        if (success)
            break;
        else
            cout<<"try again!\n";
    }
    cout<<"bye\n";

    return 0;
}
