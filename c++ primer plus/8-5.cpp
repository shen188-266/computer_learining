#include <iostream>
#include <cstring>
template<typename T>
T max5(T* arr);
template<typename T>
T max5(int n,T* arr);
template<>
char * max5(int n,char* arr[]);


int main(){
      using namespace std;
      cout <<"enter 5 integer"<<endl;
      int aas[5];
      cin>>aas[0]
      >>aas[1]>>
      aas[2]
      >>
      aas[3]
      >>aas[4];
      cout <<"the max is "<<max5(aas)<<endl;
       cout <<"enter 5 double"<<endl;
      double aaas[5];
      cin>>aaas[0]>>aaas[1]>>aaas[2]>>aaas[3]>>aaas[4];
      cout <<"the max is "<<max5(aaas)<<endl;
      char* sst[]={"sdfasdfkjasdl",
      "jksdj sdfijfdfdfdfs",
      "sldkjlsjd",
      "vjk dvkj","skjfkvvddffdsfdfsdfsdfssj"};
      cout<<"the longest is "<<max5(5,sst)<<endl;
}
template<typename T>
T max5(T* arr){
    int ma=arr[0];
for(int i=1;i<5;i++)
    {
        if(arr[i]>ma)
            ma=arr[i];
    }
    return ma;
}
template<typename T>
T max5(int n,T* arr){
    int ma=arr[0];
for(int i=1;i<n;i++)
    {
        if(arr[i]>ma)
            ma=arr[i];
    }
    return ma;
}
template<>
char * max5(int n,char* arr[])
{
    int a=strlen(arr[0]);
    char *st=arr[0];
    for(int i=1;i<n;i++)
    {
        if(strlen(arr[i])>a)
        {
            a=strlen(arr[i]);
            st=arr[i];
        }

    }
    return st;
}
