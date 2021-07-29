#include <stdio.h>
void to_all_by10(int n, unsigned short t);
int all_to_10(int n,unsigned short t);
int power(int a,unsigned short b);
int main(){
int n,m;
 unsigned short t1,t2;
 printf("enter the integer and N(2-10) for notation to N-another(q to quit).\n");
 while (scanf("%d %hu %hu",&n,&t1,&t2)==3)
 {printf("convert %d from %hu to %hu notation is:",n,t1,t2);
 m=all_to_10(n,t1);
 to_all_by10(m,t2);
 putchar('\n');
 printf("enter the integer and N(2-10) for notation to N-another(q to quit).\n");}
 return 0;
}
void to_all_by10(int n, unsigned short t)
{
    int a;
a=n%t;
if(n>=t)
to_all_by10(n/t,t);
printf("%d",a);}
int all_to_10(int n,unsigned short t){
    int a[8],b=0;
    for(int i=0;n>=1;n=n/10,i++)
    {
        a[i]=n%10;
        b+=a[i]*power(t,i);
    }
    return b;

}
int power(int a,unsigned short b){
int c=1;
if(a==0)
{if(b==0)
{printf("undefined.\n");
return 1;
}
else
    return 0;
}
else{
if(b==0)
return c;
else if(b>0)
return a*power(a,--b);
else
return a*power(a,++b);
     }
}
