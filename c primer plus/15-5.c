#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MASK 0x80000000
int rotate(unsigned int value,int n);
char * show_at2(int i);
int main(void)
{
    unsigned int a,n;
    printf("input a integar and after space input another integar\n"
           "i will << it while the left to right\n");
    scanf("%u %u",&a,&n);
    show_at2(a);
    show_at2(rotate(a,n));
    return 0;
}
char * show_at2(int i){
    static char ntst[sizeof(int)*CHAR_BIT+1];
    for(int j=sizeof(int)*CHAR_BIT;j>0;j--)
    {
        ntst[j-1]=(i&01)+'0';
        i>>=1;
    }
    ntst[sizeof(int)*CHAR_BIT]='\0';
    puts(ntst);
    return ntst;
}
int rotate(unsigned int value,int n){

int i=0;

for(;i<n;i++)
{
    if((MASK&value)==MASK)
    {
          value<<=1;
          value++;
    }
    else
        value<<=1;

}

    return value;
}
