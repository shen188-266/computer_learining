//双队列
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

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


typedef struct dqueue
{
    Element elements[MAXSIZE];
    int fri;
    int la;
}*DQueue;
int isEmpty(DQueue diqueue)
{
    return diqueue->fri==diqueue->la;
}
int isFull(DQueue diqueue)
{
    return (diqueue->la+1)%MAXSIZE==diqueue->fri%MAXSIZE;
}
int lengthOfDQueue(DQueue diqueue)
{
    return diqueue->la - diqueue->fri;
}
//choice==0则从fri加，否则从后加
int enDQueue(DQueue diqueue,Element e,int choice)
{
    if(!isFull(diqueue))
    {
       if(choice==0)
    {
        diqueue->elements[diqueue->fri]=e;

        diqueue->fri--;
        if(diqueue->fri < 0)
        {
            diqueue->fri=MAXSIZE-1;
        }

        return 1;
    }
       else if(choice==1)
    {
        diqueue->la++;
        if(diqueue->la > MAXSIZE-1)
        {
            diqueue->la=0;
        }
        diqueue->elements[diqueue->la]=e;
        return 1;
    }
    }

    return 0;
}
//choice==0则从fri delete，否则从后delete
Element deDQueue(DQueue diqueue,int choice)
{
    if(!isEmpty(diqueue))
    {
        if(choice==0)
    {
        diqueue->fri++;
        if(diqueue->fri >= MAXSIZE)
            diqueue->fri=0;
        return diqueue->elements[diqueue->fri];
    }
    if(choice==1)
    {
        diqueue->la--;
        if(diqueue->la < 0)
        {
            diqueue->la=MAXSIZE-1;
            return diqueue->elements[0];
        }

        return diqueue->elements[diqueue->la+1];
    }
    }
}
DQueue createDQueue()
{
    DQueue diqueues=(DQueue)malloc(sizeof(struct dqueue));
    if(diqueues==NULL)
       exit(4);

      diqueues->fri=0;
      diqueues->la=0;
    return diqueues;
}

int main(void)
{
    DQueue diqueues1=createDQueue();
    char st[MAXSIZE];
    int j=s_gets(st,MAXSIZE);
    /**不超过MAXSIZE
    */
    char *p=st;
    for(int i=0;i<j;i++)
        {
            enDQueue(diqueues1,*p,0);
            p++;
        }
        for(int i=0;i<j;i++)
            printf("%c",deDQueue(diqueues1,1));
            return 0;

}

