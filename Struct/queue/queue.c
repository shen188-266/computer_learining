/**fri指向第一个的前一个位置，la指向最后一个位置
*满了就崩溃了，所以没有isFull（）；
*/
#include <stdio.h>
#include <stdlib.h>
typedef int Element;
typedef struct node
{
    Element element;
    struct node *next;
}Node,*QNode;
typedef struct queue
{
    int length;
    QNode fri;
    QNode la;
}*Queue;
int isEmpty(Queue queues)
{
    return (queues->fri==queues->la);
}
int enQueue(Queue queues,Element e)
{
    QNode newE=(QNode)malloc(sizeof(Node));
    if(newE!=NULL)
    {
        queues->la->next=newE;
        newE->element=e;
        newE->next=NULL;
        queues->la=newE;
        queues->length++;
        return 1;
    }
    return 0;
}
int deQueue(Queue queues)
{
    if(isEmpty(queues))
        exit(1);

    QNode p;
    p=queues->fri->next;
    if(p!=queues->la)
    {
        queues->fri->next=p->next;
    }
    else if(p==queues->la)
    {
        queues->la=queues->fri;
    }
    free(p);
    queues->length--;
    return 1;
}
Queue createQueue()
{
    Queue queues=(Queue)malloc(sizeof(struct queue));
    queues->fri=(QNode)malloc(sizeof(Node));
    queues->la=queues->fri;
    queues->length=0;
    return queues;
}
int queueLength(Queue queues)
{
    return queues->length;
}
void printQueue(Queue queues)
{
    QNode p=queues->fri->next;
    while(p!=NULL)
    {
        printf("%d  ",p->element);
        p=p->next;
    }
    printf("\n");
}


int main(void)
{
    Queue queues=createQueue();
    if(isEmpty(queues))
        printf("it is empty!\n");
    for(int i=0;i<10;i++)
    {
        enQueue(queues,i);
    }
    printQueue(queues);
    printf("the length is: %d",queueLength(queues));
    return 0;
}
