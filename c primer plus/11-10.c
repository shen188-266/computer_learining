#include <stdio.h>
#include <string.h>
#define SIZE 81
void fanhu(char * fst,char * st);
char * s_gets(char * st,int n);
int main(void)
{char s1[SIZE],s2[SIZE];
char *ss;
printf("enter a string and i will delete the space in it.\n"
         "if you want to quit, enter\"enter\" at the line.\n");
ss=s_gets(s1,SIZE);
while(ss!=NULL&&s1[0]!='\0'){
 fanhu(s2,s1);
 puts(s2);
 printf("enter a string and i will inverse it.\n"
         "if you want to quit, enter\"enter\" at the line.\n");
ss=s_gets(s1,SIZE);
}
printf("bye!\n");
return 0;}
char * s_gets(char * st,int n){
char * re;
re=fgets(st,n,stdin);
if(re)
{while (*st!='\0'&&*st!='\n')
   st++;
 if(*st=='\n')
   *st='\0';
else
  while (getchar()!='\n')
      continue;
}
return re;}
void fanhu(char * fst,char * st){
char temp[SIZE];
int i=0,count=0,t=0;
strcpy(temp,st);
while(t<SIZE)
{while(temp[t]==' ')
   {count++;
    t++;}
    t++;
    temp[i]=temp[i+count];
    i++;}
 strcpy(fst,temp);
}

