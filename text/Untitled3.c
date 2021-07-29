#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 100
inline static double chengfang_d(double n,int m){
double num=1;
if(n==0)
{if(m!=0)
  return 0.0;
else
  {fprintf(stderr,"error.\n");
  exit(EXIT_FAILURE);}}
else
{if(m>0)
 {while(m-->0)
     num*=n;
 return num;}
 else if(m==0)
 return 1.0;
 else
 {while(m++<0)
    num/=n;
 return num;}}
}
inline static int s_gets(char * st,int n){
char * re;
re=fgets(st,n,stdin);
int i=0;
if(re)
{while(*st!='\0' && *st!='\n')
{
    st++;
    i++;
}
if(*st=='\n')
    *st ='\0';
else
while(getchar()!='\n')
    continue;}
return i;}


typedef int Element;
typedef struct stack
{
    Element elements[MAXSIZE];
    int length;
}*Stack;
Stack createStack()
{
    Stack stacks=(Stack)malloc(sizeof(struct stack));
    if(stacks==NULL)
        exit(1);

    stacks->length=0;
    return stacks;
}
Element pop(Stack stacks)
{
    if(stacks->length>0)
    {
        stacks->length--;
        return stacks->elements[stacks->length];
    }
    return -12345;
}
int push(Stack stacks,Element e)
{
    if(stacks->length>=MAXSIZE)
        exit(2);

    stacks->elements[stacks->length]=e;
    stacks->length++;
    return 1;
}
//无法得到复数
double getNumberd(const char *st,char **q)
{
    char *p=st;
    double counts=0;

    while(1)
    {
        char ch=*p;
        if(isdigit(ch))
        {
            counts=counts*10+(ch-'0');
            p++;
        }
        else
            break;
    }
    if(*p=='.')
    {
        int i=1;
        while(1)
    {
        char ch=*p;
        if(isdigit(ch))
        {
            counts=counts+(ch-'0')*chengfang_d(10.0,-i);
            p++;
        }
        else
            break;
    }
    }
    *q=p;

    if(p!=st)
    return counts;
    else
        return -1;
}

int main(void)
{
    Stack stacks=createStack();
    int a=0,b=0;
    char st[MAXSIZE];
    int n=s_gets(st,MAXSIZE);
    char **p;
    double numbers=getNumberd(st,p);
    while(*p!=&st[n])
    {
        if(numbers!=-1)
            push(stacks,numbers);
        else if(**p==' ')
            (*p)++;
        else if(**p=='+')
        {
            a=pop(stacks);
            b=pop(stacks);
            push(stacks,a+b);
            (*p)++;
        }
        else if(**p=='-')
        {
            a=pop(stacks);
            b=pop(stacks);
            push(stacks,a-b);
            (*p)++;
        }
        else if(**p=='*')
        {
            a=pop(stacks);
            b=pop(stacks);
            push(stacks,a*b);
            (*p)++;
        }
        else if(**p=='/')
        {
            a=pop(stacks);
            b=pop(stacks);
            push(stacks,a/b);
            (*p)++;
        }
        numbers=getNumberd(st,p);
    }

        printf("\nthe calculation is: %d  ",pop(stacks));

}
