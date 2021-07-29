#include <stdio.h>
#include "alls.h"

char * align[3]={"left","middle","right"};
char * set[2]={"off","open"};
static unsigned int setting=0x812345;
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

                     setting &=  ~255;
                     setting+=b;
                     break;
            case 's':printf("enter the size of word you want to get(0-127):");
                     scanf("%d",&b);
                     getchar();
                     setting &=  ~32512;
                     setting+=b*chengfang_i(2,8);
                     break;
            case 'a':puts("0)left  1)middle  2)right");
                     printf("enter the alignment of word you want to get(0-2):");
                     scanf("%d",&b);
                     getchar();
                     setting &=  ~98304;
                     setting+=b*chengfang_i(2,15);

                     break;
            case 'b':puts("0)off  1)open");
                     printf("enter the bold of word you want to(0-1):");
                     scanf("%u",&c);
                     getchar();
                     setting &=  ~131072;
                     setting+=c*chengfang_i(2,17);

                     break;
            case 'i':puts("0)off  1)open");
                     printf("enter the italic of word you want to(0-1):");
                     scanf("%u",&c);
                     getchar();
                     setting &=  ~262144;
                     setting+=c*chengfang_i(2,18);

                     break;
            case 'u':puts("0)off  1)open");
                     printf("enter the underline of word you want to(0-1):");
                     scanf("%u",&c);
                     getchar();
                     setting &=  ~524288;
                     setting+=c*chengfang_i(2,19);

                     break;
        }
    }
    printf("bye!\n");
    return 0;
}

int menu(void){
printf("  ID  SIZE  ALIGNMENT    B    I    U\n"
       "%4d  %4d  %9s  %3s  %3s  %3s\n\n",setting&255,(setting>>8)&127,align[(setting>>15)&3],set[(setting>>17)&1],set[(setting>>18)&1],set[(setting>>19)&1]);
puts("f)change font    s)change size    a)change alignment");
puts("b)toggle bold    i)toggle italic  u)toggle underline");
puts("q)quit");
return 1;
}
