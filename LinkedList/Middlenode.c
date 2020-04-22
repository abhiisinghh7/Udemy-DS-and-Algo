#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL, *last=NULL;

void create(int A[], int n)
{
    struct Node *t;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int Length(struct Node *p)
{
int len=0;
while(p)
{
len++;
p=p->next;
}
return len;
}
 void findMiddle1(struct Node *p)
{
    int i, x;
    //x=Length(p)/2;
    x=ceil(Length(p)/2);
    for(i=0;i<x-1;i++)
        p=p->next;
    printf("%d ",p->data);
}
void Idisplay(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}
int middle(struct Node *p)
    {
    struct Node *q=p;
    while(q->next!=NULL)
    {
     p=p->next;
     q=q->next;
     if(q->next!=NULL)
    q=q->next;
    }
    return p->data;
    }
    int main()
{
   int A[]={1,2,3,4};
   create(A, 4);
   Idisplay(first);
   printf("\nMiddle node is %d", middle(first));
   printf("\n");
   Idisplay(first);
 int B[]={5,152,252,352,452};
    create(B,5);
    Idisplay(first);
    printf("\nMiddle node is");
    findMiddle1(first);
    return 0; return 0;
}
