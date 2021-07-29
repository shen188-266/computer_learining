#include <stdio.h>
char * stringf(char * st,char c);
int main(void){
char * st;
const char * ops="wjehfwjefhj ekjfiejwo";
st=stringf(ops,'e');
puts(st);
return 0;}
char * stringf(char * st,char ch){
char *dh;
dh=st;
while(*dh!=ch&&*dh!='\0')
dh++;
if(*dh=='\0')
return NULL;
else
return dh;}
