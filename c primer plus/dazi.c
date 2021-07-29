#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define LEF 10
#define SIZE 64
char * s_gets(char * st,int n);
int main(void){
char fj[LEF][SIZE],sk[SIZE];
int i,j;

int errora;

printf("input as it.\n");
srand((unsigned int)time(0));
for(int i=0;i<LEF;i++)
    {for(int j=0;j<SIZE;j++)
    {
        fj[i][j]=rand()%26+97;
    }
    fj[i][SIZE-1]='\0';}


clock_t a=clock();
for(i=0;i<LEF;i++)
    {
        puts(fj[i]);
        s_gets(sk,SIZE);
        j=0;
        while(fj[i][j]==sk[j]&&fj[i][j++]!='\0')
         ;
        if(j!=SIZE)
        {
            errora=j;
            printf("error.\n");
            printf("%d\n",j+1);
            puts(&fj[i][errora]);
            i--;
        }

    }
clock_t b=clock();
    double total;
    total=((double)b-(double)a)/CLOCKS_PER_SEC;

    printf("Congratulations, you did it!\n");
    printf("you use %lf seconds, and your typing speed is %lfwords/min.\n",total,SIZE*LEF/(total/60));

    if((int)(SIZE*LEF/(total/60))<=60)
        printf("your typing speed is so slow.\n");
    else
    printf("nice! you are so cool.\n");
    getchar();



    return 0;}
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
