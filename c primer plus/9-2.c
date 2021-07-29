#include <stdio.h>
void chline(char ch,int i,int j);
int main(){
int i,j;
char ch;
scanf("%c%d%d",&ch,&i,&j);
chline(ch,i,j);
return 0;}
void chline(char ch,int i,int j){
for(int a=0;a<j;a++)
{for(int b=0;b<i;b++)
printf("%c",ch);
putchar('\n');}}
