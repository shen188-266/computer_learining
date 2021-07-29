#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int total[100];
int roll_dice(int dice,int sides,int sets);
int roll_count=0;
int rollem(int sides);
int main(void)
{
   int dice,roll;
   int sides,sets;
   int status;

   srand((unsigned int) time(0));
   printf("Enter the number of sets,q to stop.\n");
   while (scanf("%d",&sets)==1&&sets>0)
          {printf("how many sides and how many dice?\n");
          if((status =scanf("%d %d",&sides,&dice))!=2)
          {
          if (status == EOF)
            break;
           else
           {
               printf("you should have enterd two integer.");
               printf("let's begin again.\n");
               while (getchar()!='\n');
                 continue;
           }
          }
          roll=roll_dice(dice,sides,sets);
          printf("you have rolled %d sets using %d %d-sides dice.\n",sets,dice,sides);
        for(int i=0;i<sets;i++)
            printf("%4d",total[i]);
         printf("Enter the number of sets,q to stop.\n");
          }
 printf("the rollem() function was called %d times.\n",roll_count);
 printf("good fortune to you!\n");
 return 0;
           }

int roll_dice(int dice,int sides,int sets){
int d;
if(sides<2)
    {
        printf("need at least 2 sides.\n");
        return -2;
    }
if (dice<1)
{
    printf("need at least 1 die.\n");
    return -1;
}
for(int i=0;i<sets;i++)
for (d=0;d<dice;d++)
    total[i]+=rollem(sides);
putchar('\n');
return total;
}

int rollem(int sides)
{
    int roll;
    roll=rand()%sides+1;
    ++roll_count;
    return roll;
}
