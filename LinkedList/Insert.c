//Inserting in a Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*first=NULL;
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
}
}
void Display(struct Node *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}}
/*void Insert(int pos, int key){
struct Node *t, *p;
t->data=key;
if(pos==0)
{
t->next=first;
first = t;
}
else if(pos>0){
p=first;
for(int i=0;i<pos-1 && p!=NULL;i++){
p=p->next;}
t->next=p->next;
p->next=t;}}*/
void InsertLL(struct Node *p,int index,int x)
//TC=O(n)
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
int main()
{
int A[]={10,20,30,40,50};
create(A,5);
Display(first);
printf("\n After Insertion \n");
//Insert(0,5);
InsertLL(first,0,5);
Display(first);
return 0;
}
