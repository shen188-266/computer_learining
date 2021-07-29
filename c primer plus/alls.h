#ifndef ALLS_H_
#define ALLS_H_
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>


inline static char * s_gets(char * st,int n){
char * re;
re=fgets(st,n,stdin);
if(re)
{while(*st!='\0'&&*st!='\n')
     st++;
if(*st=='\n')
    *st ='\0';
else
while(getchar()!='\n')
    continue;}
return re;}



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


inline static int chengfang_i(int n,int m){
int num=1;
if(n==0)
{if(m!=0)
  return 0;
else
  {fprintf(stderr,"error.\n");
  exit(EXIT_FAILURE);}}
else
{if(m>0)
 {while(m-->0)
     num*=n;
 return num;}
 else if(m==0)
 return 1;
 else
 {while(m++<0)
    num/=n;
 return num;}}
}

#endif
