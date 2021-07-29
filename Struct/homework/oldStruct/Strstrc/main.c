//KMP¸nextval

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_nextval(char * st,int * nextval);
char * Strstrc(char * st1,char * str2,int n);

int main()
{
    char *st="ababaaaba";
    char *so="aaa";
    puts(Strstrc(st,so,0));


    return 0;
}
void get_nextval(char * st,int * nextval)
{
    int j=-1;
    int i=0;
    int n=strlen(st);
    nextval[0]=-1;
    while(i<n)
    {
        if(j==-1||st[i]==st[j])
        {
            i++;
            j++;
            if(st[i]!=st[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];
        }
        else
        {
            j=nextval[j];
        }
    }

}
char * Strstrc(char * st1,char * st2,int n)
{

    int i=n;
    int j=0;
    int nextval[255];
    get_nextval(st2,nextval);
    while(j==-1||(st1[i]!='\0'&&st2[j]!='\0'))
    {
        if(j==-1||st1[i]==st2[j])
        {
            i++;
            j++;
        }
        else
            j=nextval[j];
    }
    if(st2[j]=='\0')
        return st1+i-strlen(st2);
    else
        return 0;
}
