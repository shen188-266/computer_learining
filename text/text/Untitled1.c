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


typedef double Element;
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
Element seekStack(Stack stacks)
{
    if(stacks->length>0)
    {

        return stacks->elements[stacks->length -1];
    }
    return -123456;
}


typedef char Element1;
typedef struct stack1
{
    Element1 elements[MAXSIZE];
    int length;
}*Stack1;
Stack1 createStack1()
{
    Stack1 stacks1=(Stack1)malloc(sizeof(struct stack1));
    if(stacks1==NULL)
        exit(1);

    stacks1->length=0;
    return stacks1;
}
Element1 pop1(Stack1 stacks1)
{
    if(stacks1->length>0)
    {
        stacks1->length--;
        return stacks1->elements[stacks1->length];
    }
    return 3;
}
int push1(Stack1 stacks1,Element1 e)
{
    if(stacks1->length>=MAXSIZE)
        exit(2);

    stacks1->elements[stacks1->length]=e;
    stacks1->length++;
    return 1;
}
Element1 seekStack1(Stack1 stacks1)
{
    if(stacks1->length>0)
    {

        return stacks1->elements[stacks1->length -1];
    }
    return 2;
}

//!为负数
double getNumberd(char *st,char **q)
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
        p++;
        char ch=*p;
        if(isdigit(ch))
        {
            counts=counts+(ch-'0')*chengfang_d(10,-i);
        }
        else
            break;
    }
    }


    if(p!=st)
        {
            while(*p==' ')
                p++;
            if(*p=='!')
                {
                    p++;
                    counts=0-counts;
                }

            *q=p;
            return counts;
        }

        *q=p;
        return -1010102;
}
int convertSymbol(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '!':return 3;
    }
    return 0;
}
int compareSymbol(char c1,char c2)
{
    if(c1=='(' || c2=='(')
                return -1;
    int a=convertSymbol(c1);
    int b=convertSymbol(c2);
    return a-b;

}
int main(void)
{
    Stack1 stacks1=createStack1();
    double a=0,b=0;
    char ost[MAXSIZE];
    //中缀转后缀
    int n=s_gets(ost,MAXSIZE);
    char st[MAXSIZE];
    int i=0,j=0;
    while(i<n)
    {
        if(isdigit(ost[i]))
        {
            while(isdigit(ost[i]))
          {
            st[j++]=ost[i];
            i++;
          }
        st[j++]=' ';
        continue;
        }
        else if(ost[i]==' ')
            ;
        else if(ost[i]=='(')
            push1(stacks1,'(');
        else if(ost[i]==')')
        {
            int popch=pop1(stacks1);
            while(popch!='(')
            {
                st[j++]=popch;
                popch=pop1(stacks1);
            }
        }
        else if(seekStack1(stacks1)==2 || compareSymbol(seekStack1(stacks1),ost[i])<0)
        {
            push1(stacks1,ost[i]);
        }
        else if(compareSymbol(seekStack1(stacks1),ost[i])>=0)
        {
            char popch1=seekStack1(stacks1);

            while(popch1!=2 && compareSymbol(popch1,ost[i])>=0)
            {
                st[j++]=pop1(stacks1);
                popch1=seekStack1(stacks1);
            }
            push1(stacks1,ost[i]);
        }


        i++;
    }
    while(stacks1->length>0)
    {
        st[j++]=pop1(stacks1);
    }
    st[j]='\0';
   printf("%s",st);



    //后缀计算
   char *ini=st;
     Stack stacks=createStack();
    char **p=(char **)malloc(sizeof(char));
    double numbers=getNumberd(ini,p);
    while(*p<&st[j])
    {
        if(numbers!=-1010102)
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
            push(stacks,b-a);
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
            push(stacks,b/a);
            (*p)++;
        }
        ini=*p;
        numbers=getNumberd(ini,p);

    }

        printf("\nthe calculation is: %.5lf  ",pop(stacks));


   return 0;
}
