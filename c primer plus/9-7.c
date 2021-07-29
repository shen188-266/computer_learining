#include<stdio.h>
#include<ctype.h>
int fanhui(char);
int main(){
int a;
char b;
printf("input a char.\n");
scanf("%c",&b);
getchar();
a=fanhui(b);
printf("%d",a);
return 0;
}
int fanhui(char a){
char ch;
while((ch=getchar())!=EOF)
{if(isalpha(ch))
{printf("%c is an alpha. And ",ch);
ch=toupper(ch);
printf("the location is %d\n",ch-64);}
else
printf("%c is not an alpha.\n",ch);}
if(isalpha(a))
{a=toupper(a);
return a-64;}
else return -1;}
