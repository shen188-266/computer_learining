#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* getNext(const char st[])
{
    int n=strlen(st);
    int* Next=(int *)malloc(sizeof(int)*(n-1));
    Next[0]=-1;
    Next[1]=0;
    int i=0,j=1;               //i指向前缀尾，j指向后缀尾
    while(j<n-1)
    {
        if(i==-1 || st[i]==st[j])
        {
            i++;
            j++;
            if(st[i]!=st[j])
                Next[j]=i;
            else
                Next[j]=Next[i];
        }
        else
            i=Next[i];
    }
    return Next;
}
//默认n为0
int Index_KMP(char* s1,const char* s2,int n)
{
    int i=n;
    int length=strlen(s2);
    int* Next=getNext(s2);
    char* st=s1;
    int j=0;
    printf("the next is: ");
    for(int c=0;c<length;c++)
        printf("%d ",Next[c]);
    while(st[i]!='\0' && j<length)
    {
        if(j==-1 || st[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j=Next[j];
        }
    }
    free(Next);
    if(j==length)
        return i-length;
    else
        return 0;
}

int main(void)
{
    char* s1="abaacdsg";
    const char* s2="aaaad";
    printf("\n%d",Index_KMP(s1,s2,0));
    return 0;
}
