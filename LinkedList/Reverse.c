//Reverse a Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
void Display(struct Node *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}
void create(int A[],int n)
{
int i;
struct Node *t,*last;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++)
{
t=(struct Node*)malloc(sizeof(struct Node));
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
}}
void Reverse1(struct Node *p)
//Copy elements in Array, by reversing the elements
{
int *A,i=0;
struct Node *q=p;
A=(int *)malloc(sizeof(int)*5);
while(q!=NULL)
//Copy from LL to Array
{
A[i]=q->data;
q=q->next;
i++;
}
q=p;
i--;
while(q!=NULL)
//Copy from Array back to LL in a reverse manner
{
q->data=A[i];
q=q->next;
i--;
}}
void Reverse2(struct Node *p)
//Using Sliding pointers, q-> node to be modified, p-> next node, r-> previous node
{
struct Node *q=NULL,*r=NULL;
while(p!=NULL)
{
r=q;
q=p;
p=p->next;
q->next=r;//Reverse the link
}
first=q;
}
void Reverse3(struct Node *q,struct Node *p)
//Using Recursion
{
if(p!= NULL)
{
Reverse3(p,p->next);
//At returning time, links will be reversed
p->next=q;
}
else
first=q;
}
int main()
{int A[]={10,20,40,50,60};
create(A,5);
Display(first);
printf("\n");
Reverse1(first);
Display(first);
printf("\n");
Reverse2(first);
Display(first);
printf("\n");
Reverse3(NULL,first);
Display(first);
return 0;
}
