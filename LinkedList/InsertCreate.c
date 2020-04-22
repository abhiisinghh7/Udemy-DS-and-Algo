//Insert and create a Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*first=NULL,*last=NULL;
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
void Display(struct Node *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}
void Insert(struct Node *p,struct Node *q,int index,int x)
{
struct Node *t;
int i;
t=(struct Node *)malloc(sizeof(struct Node));
t->data=x;
if(index == 0)
{
t->next=first;
first=t;
}
else
{
for(i=0;i<index-1;i++)
p=p->next;
t->next=p->next;
p->next=t;
}
}
void Insertlast(struct Node *p,struct Node *q,int x){
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->data=x;
t->next=NULL;
if(first==NULL){
first=t;
last=t;}
else{
last->next=t;
last=t;
}
}
int main()
{
Insertlast(first,last,20);
Insert(first,last,0,15);
Insert(first,last,0,8);
Insert(first,last,0,9);
Insert(first,last,1,10);
//Insertlast(first,last,20);
Display(first);
return 0;
}
