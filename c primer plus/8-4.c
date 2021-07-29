#include<stdio.h>
#include<ctype.h>
int main(void)
{  int a,c;
     a=0;
     c=0;
     char ch;
     int oo;
while((ch=getchar())!=EOF)
      { if(ch==' ')
      continue;
         else if(!ispunct(ch))
            {c++;
            a++;
        while((oo=getchar())!=' ')
            {c++;
            if(oo==EOF)
                goto prp;}
        }
        }
        prp: printf("%d  %d\n",a,c);
        return 0;
}
