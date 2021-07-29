#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include <ctype.h>
struct month {
   char monthname[11];
   char abrev[4];
   int days;
   int num;};
char * s_gets(char * st,int n);
void getsmo(struct month *sd,char *st,int n);
void ToLower(char *st);
int main(void)
{
    struct month months[12]={
    {"january","jan",31,1},
    {"febrary","fab",28,2},
    {"march","mar",31,3},
    {"april","apr",30,4},
    {"may","may",31,5},
    {"june","jun",30,6},
    {"july","jul",31,7},
    {"august","aug",31,8},
    {"september","sep",30,9},
    {"october","oct",31,10},
    {"november","nov",30,11},
    {"december","dec",31,12},
};
      int i,total;
      char st[11];
      printf("input the monthname and i will output the days from jan 1st to this month.\n");
      getsmo(months,st,11);
      for(i=0,total=0;i<12;i++)
      {
          if(strcmp(st,months[i].monthname)==0)
            break;
          total=total+months[i].days;
      }
      printf("the days from jan 1st to this month is %d.\n",total);
      return 0;
}
char * s_gets(char * st,int n){
char * re;
re=fgets(st,11,stdin);
if(re)
    {
        while(*st!='\0'&&*st!='\n')
            st++;
        if(*st=='\n')
            *st='\0';
        else
            while(getchar()!='\n')
            continue;
    }
    return re;
}
void ToLower(char *st){

while(*st!='\0')
    {
        *st=tolower(*st);
        st++;
    }
}
void getsmo(struct month sd[],char *st,int n){
    bool zh=true;
    while(zh)
    {
        s_gets(st,n);
        ToLower(st);
        for(int i=0;i<12;i++)
        {
            if(strcmp(st,sd[i].monthname)==0)
                zh=false;
        }
        if(zh)
            printf("i can't recongnize, please input again.\n");
    }

}
