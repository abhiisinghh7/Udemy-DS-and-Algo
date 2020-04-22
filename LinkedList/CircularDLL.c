#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;
void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=first;
    first->prev=first;
    last=first;
    for(i=1;i<n;i++)
    {
       t=(struct node *)malloc(sizeof(struct node));
       t->data=A[i];
       t->next=last->next;
       t->prev=last;
       last->next=t;
       last=t;
    }
}
int Count(struct node *p){
p = first;
int t=1;
do{
t++;
p = p->next;
}while(p->next != first);
        return t;
            }
void display(struct node *p)
{
    do
    {
        printf("%d  ",p->data);
        p=p->next;
    }while(p!=first);
}
int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    printf("\n Count = %d",Count(first));
}


