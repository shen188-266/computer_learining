#include <stdio.h>
int main(void)
{
  char ch;
  int space=0,h=0,allelse=0;
  while((ch=getchar())!='#')
  { if(ch==' ')
      space++;
    else if(ch=='\n')
    h++;
    else
    allelse++;

  }
  printf(" number of space is %d,huanhang is %d, else is %d\n",space,h,allelse);
  return 0;
}
