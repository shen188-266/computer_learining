#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81
char * s_gets(char * st,int n);
int main(void)
{
    FILE *fp;
    char s1[SIZE];
    char ch;
    printf("input the file you want to watch,quit to stop.\n");
    s_gets(s1,SIZE);
    while(strcmp(s1,"quit"))
    {
       if((fp=fopen(s1,"r"))==NULL)
    {
        fprintf(stderr,"can't open %s\n",s1);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fp,NULL,_IOFBF,4096)!=0)
    {
        fprintf(stderr,"can't built input buffer.\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
    }
    putchar('\n');
    if(fclose(fp)!=0)
    {
        fprintf(stderr,"can't close files.\n");
        exit(EXIT_FAILURE);
    }
    printf("input the file you want to watch,quit to stop.");
    s_gets(s1,SIZE);
    }

    return 0;
}
char * s_gets(char * st,int n){
char * re;
char * find;
re=fgets(st,SIZE,stdin);
if(re)
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
            continue;
    }
    return re;
}
