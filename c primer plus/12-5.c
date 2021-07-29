#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
void jiangxu(int * er,int n);
int main(void)
{
    int i=0;
    int roll[SIZE];
    int count[10]={0};
    srand((unsigned int)time(0));
    while(i<SIZE)
        {
            roll[i]=rand()%10+1;
            count[roll[i]-1]++;
            i++;
        }
    /*jiangxu(roll,SIZE);
    for(int i=0;i<SIZE;i++)
        {
            printf("%5d",roll[i]);
            if(i%10==9)
                putchar('\n');
        }*/
    for(i=0;i<10;i++)
        printf("the number of %d is:%d.\n",i+1,count[i]);
        return 0;
    }
/*void jiangxu(int * er,int n){
int temp;
int i,j;
for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(er[i]<er[j])
                {temp=er[i];
                er[i]=er[j];
                er[j]=temp;}
        }
    }
}
*/
