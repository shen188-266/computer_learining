#include <stdio.h>
#include "alls.h"
struct {
  unsigned int zitiID    :8;
  unsigned int           :1;
  unsigned int zitisize  :7;//16
  unsigned int duiqi     :2;
  unsigned int           :1;
  bool         jiacu      :1;//20
  unsigned int           :1;
  bool         xieti      :1;
  unsigned int           :1;
  bool         underline  :1;//24
  }ziti;
char * align[3]={"left","middle","right"};
char * set[2]={"off","open"};

int menu(void);

int main(void)
{
    char a;
    int b;
    bool c;
    while(menu())
    {
        scanf("%c",&a);
        if(a=='q')
            break;
        switch (a)
        {
            case 'f':printf("enter the font of word you want to get(0-255):");
                     scanf("%d",&b);
                     getchar();
                     ziti.zitiID=b;
                     break;
            case 's':printf("enter the size of word you want to get(0-127):");
                     scanf("%d",&b);
                     getchar();
                     ziti.zitisize=b;
                     break;
            case 'a':puts("0)left  1)middle  2)right");
                     printf("enter the alignment of word you want to get(0-2):");
                     scanf("%d",&b);
                     getchar();
                     ziti.duiqi=b;
                     break;
            case 'b':puts("0)off  1)open");
                     printf("enter the bold of word you want to(0-1):");
                     scanf("%u",&c);
                     getchar();
                     ziti.jiacu=c;
                     break;
            case 'i':puts("0)off  1)open");
                     printf("enter the italic of word you want to(0-1):");
                     scanf("%u",&c);
                     getchar();
                     ziti.xieti=c;
                     break;
            case 'u':puts("0)off  1)open");
                     printf("enter the underline of word you want to(0-1):");
                     scanf("%u",&c);
                     getchar();
                     ziti.underline=c;
                     break;
        }
    }
    printf("bye!\n");
    return 0;
}

int menu(void){
printf("  ID  SIZE  ALIGNMENT    B    I    U\n"
       "%4d  %4d  %9s  %3s  %3s  %3s\n\n",ziti.zitiID,ziti.zitisize,align[ziti.duiqi],set[ziti.jiacu],set[ziti.xieti],set[ziti.underline]);
puts("f)change font    s)change size    a)change alignment");
puts("b)toggle bold    i)toggle italic  u)toggle underline");
puts("q)quit");
return 1;
}
