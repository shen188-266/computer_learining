#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
struct member {
  int num;
  char firstname[20];
  char lastname[20];
  int game;
  int bate;
  int walk;
  int rbi;
  double andalv;
  };
int main(void)
{
    struct member player[SIZE];
    FILE * fp;
    int i=0,j;
    int count[SIZE]={0};
    int k=0;
    int chun[SIZE-1]={0};
        if((fp=fopen("ydw.txt","r"))==NULL)
        {
            fprintf(stderr,"error in open the file");
            exit(EXIT_FAILURE);
        }
    for(;i<SIZE;i++)
    {
        fscanf(fp,"%d",&player[i].num);
        //printf("%d ",player[i].num);
        fscanf(fp,"%s %s",player[i].firstname,player[i].lastname) ;
        //printf("%s %s ",player[i].firstname,player[i].lastname);
        fscanf(fp,"%d %d %d %d",&player[i].game,&player[i].bate,&player[i].walk,&player[i].rbi);
        //printf("%d %d %d %d",player[i].game,player[i].bate,player[i].walk,player[i].rbi);
    }
    for(i=0;i<SIZE;i++)
    {
        if(i==0||i!=chun[0]&&i!=chun[1]&&i!=chun[2]&&i!=chun[3]&&i!=chun[4]&&i!=chun[5]&&i!=chun[6]&&i!=chun[7]&&i!=chun[8]&&i!=chun[9])
        {for(j=i+1;j<SIZE;j++)
          {
            if(strcmp(player[i].firstname,player[j].firstname)==0)
                if(strcmp(player[i].lastname,player[j].lastname)==0)
            {
                count[i]++;
                chun[k++]=j;
                player[i].game+=player[j].game;
                player[i].bate+=player[j].bate;
                player[i].walk+=player[j].walk;
            }
          }
        }
    }//dispose the repeat date
    for(i=0;i<SIZE;i++)
    {
        player[i].andalv=(double)player[i].bate/(double)player[i].game;

    }

    k=0;

    for(i=0;i<SIZE;i++)
    {
         if(i==0||i!=chun[0]&&i!=chun[1]&&i!=chun[2]&&i!=chun[3]&&i!=chun[4]&&i!=chun[5]&&i!=chun[6]&&i!=chun[7]&&i!=chun[8]&&i!=chun[9])
        {
            printf("the %s %s'number is %d",player[i].firstname,player[i].lastname,player[i].num);
            for(int m=0;m<count[i];m++)
            {
                printf(" and %d",player[chun[k++]].num);
            }
            putchar('\n');
            printf("and the game is %d,bate is %d, walk is %d, andalv is %lf\n\n",player[i].game,player[i].bate,player[i].walk,player[i].andalv);
        }
    }
    if(fclose(fp)){
        fprintf(stderr,"error in close the file");
        exit(EXIT_FAILURE);
    }
    return 0;

}
