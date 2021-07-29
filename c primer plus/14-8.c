#include <stdio.h>
#include <stdbool.h>
#include "alls.h"
#define SIZE 12
struct plane {
   int num;
   bool reserve;
   char firstname[20];
   char lastname[20];
   };

void menu(void);
void showen(struct plane * sj);
void showel(struct plane * sj);
void showas(struct plane * sj);
void assignac(struct plane * sj);
void deletec(struct plane * sj);

int main(void)
{
    char ch;
    struct plane jiant[SIZE]={
    {1,true,"sasfjoafj","afnajsf"},{2,false},{3,true,"avsjfwes","fjenf"},{4,false},{5,false},{6,false},{7,false},{8,false},{9,false},{10,false},{11,false},{12,false}};
    do {
        menu();
        ch=getchar();
        while(getchar()!='\n')
            continue;
        switch (ch)
        {
            case 'a': showen(jiant);
                    break;
            case 'b': showel(jiant);
                    break;
            case 'c': showas(jiant);
                    break;
            case 'd': assignac(jiant);
                    break;
            case 'e': deletec(jiant);
                    break;
            case 'f': break;
        }
    }while(ch!='f');
    return 0;
}

void menu(void){
printf("TO choose a function, enter its letter label:\n");
printf("a)Show number of empty seats\n"
       "b)Show list of empty seats\n"
       "c)Show alphabetical list of seats\n"
       "d)Assign a customer to a seat assignment\n"
       "e)Delete a sear assignment"
       "Quit");
printf("enter a alpha to choose.\n");}

void showen(struct plane * sj){
int i;
for (i=0;i<SIZE;i++)
    {
        if(!sj->reserve)
            printf("the NO.%d is empty.\n",sj->num);
        sj++;
    }
}
void showel(struct plane * sj){
int i;
for (i=0;i<SIZE;i++)
    {
        if(sj->reserve)
            printf("the %s %s is empty.\n",sj->firstname,sj->lastname);
        sj++;
    }
}
void showas(struct plane * sj){
int i,j;
struct plane temp;
struct plane kj[SIZE];
for (i=0;i<SIZE;i++)
{
    kj[i]=sj[i];

}
for (i=0;i<SIZE-1;i++)
    for(j=i+1;j<SIZE;j++)
{
    if(kj[i].firstname!=NULL&&kj[j].firstname!=NULL&&strcmp(kj[i].firstname,kj[j].firstname)>0)
    {
        temp=kj[i];
        kj[i]=kj[j];
        kj[j]=temp;

    }
}

for (i=0;i<SIZE;i++)
    {
       if(kj[i].reserve)
            printf("the %s %s is not empty.\n",kj[i].firstname,kj[i].lastname);
    }
}
void assignac(struct plane * sj){
puts("enter a number of seats");
int n;
scanf("%d",&n);
while(getchar()!='\n')
            continue;
if(n>=1&&n<=12&&!sj[n-1].reserve)
{
    sj[n-1].reserve=true;
    puts("enter your fistname.");
    s_gets(sj[n-1].firstname,20);
    puts("enter your lastname.");
    s_gets(sj[n-1].lastname,20);
}
}
void deletec(struct plane * sj){
    puts("enter a number of seats to molify");
int n;
scanf("%d",&n);
while(getchar()!='\n')
            continue;
if(n>=1&&n<=12)
{
    sj[n-1].reserve=true;
    puts("enter your fistname.");
    s_gets(sj[n-1].firstname,20);
    puts("enter your lastname.");
    s_gets(sj[n-1].lastname,20);
}
}
