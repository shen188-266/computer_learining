
void printAsSecond(Head L1,Head L2)
{
    int i;
    Head p=L2->next;
    for(i=L2->next->item.a;p->next!=NULL;i=p->item.a)
    {
        printf("%d  ",getItem(i,L1)->item.a);
        p=p->next;
    }
    printf("\n");
}





//²âÊÔ
int main(void)
{
   Head L1=createList();
   Head L2=createList();
   int b;
    for(int i=10;i>0;i--)
    {
        b=i;
        Item it;
        it.a=b;
        addHead(it,L1);
    }
    printf("the L2 is: ");
   printList(L1);
   printf("the L2 is: ");
   for(int i=10;i>0;i=i-2)
    {
        b=i;
        Item it;
        it.a=b;
        addHead(it,L2);
    }
    printList(L2);
    printf("the L1 As L2 is :");
    printAsSecond(L1,L2);
    return 0;
}
