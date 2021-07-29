#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ERRORHAPPPEN -101010
typedef struct node
{
    int elements[MAXSIZE];
    int fri;
    int la;
}*Queue;
int isEmpty(Queue queue)
{
    return queue->fri==queue->la;
}
int isFull(Queue queue)
{
    return (queue->la+1)%MAXSIZE==queue->fri%MAXSIZE;
}
int queueLength(Queue queue)
{
    return queue->la - queue->fri;
}
int enQueue(Queue queue,int e)
{
    if(!isFull(queue))
    {
        queue->la++;
        queue->elements[queue->la%MAXSIZE]=e;
        return 1;
    }
    return 0;
}
int deQueue(Queue queue,int e)
{
    if(!isEmpty(queue))
    {
        queue->fri++;
        return queue->elements[queue->fri%MAXSIZE];
    }
    return ERRORHAPPPEN;
}
Queue creatQueue()
{
    Queue queue=(Queue)malloc(sizeof(struct node));
    queue->fri=0;
    queue->la=0;
    return queue;
}
void printAll(Queue queue)
{
    int i=queue->fri + 1;
    while(i<=queue->la)
    {
        printf("%d  ",queue->elements[i%MAXSIZE]);
        i++;
    }
    printf("\n");
}

int main(void)
{
    Queue queue=creatQueue();
    if(isEmpty(queue))
        printf("isEmpty\n");
    for(int i=0;i<5;i++)
    {
        enQueue(queue,i);
    }
    printAll(queue);
    if(isFull(queue))
    printf("isfull\n");
    deQueue(queue,0);
    enQueue(queue,3);
    printAll(queue);
    printf("the length is %d",queueLength(queue));
    return 0;
}
