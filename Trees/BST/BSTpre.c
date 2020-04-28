#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;

struct Stack
{
 int size;
 int top;
 struct Node **S;
};
void stackcreate(struct Stack *st,int size)
{
 st->size=size;
 st->top=-1;
 st->S=(struct Node**)malloc(st->size*sizeof(struct Node*));
}

void push(struct Stack *st,struct Node *x)
{
 if(st->top==st->size-1)
 printf("Stack overflow\n");
 else
 {
 st->top++;
 st->S[st->top]=x;
 }
}
struct Node * pop(struct Stack *st)
{
 struct Node * x=NULL;

 if(st->top==-1)
 printf("Stack Underflow\n");
 else
 {
 x=st->S[st->top--];
 }
 return x;
}

int isEmpty(struct Stack st)
{
 if(st.top==-1)
 return 1;
 return 0;
}

struct Node *stackTop(struct Stack st)
{
 if(!isEmpty(st))
      return st.S[st.top];
 return NULL;
}

void createpre(int pre[],int n)
{
struct Stack stk;
stackcreate(&stk,50);
struct Node*t,*p,*q;
int i=0;
root=(struct Node *)malloc(sizeof(struct Node ));
root->data=pre[i++];
root->lchild=root->rchild=NULL;
p=root;
while(i<n)
{
if(pre[i]<p->data)
{
t=(struct Node *)malloc(sizeof(struct Node ));
t->data=pre[i++];
t->lchild=t->rchild=NULL;
p->lchild=t;
push(&stk,p);
p=t;}
else {
if((pre[i]>p->data&&pre[i]<stackTop(stk)->data))
{
t=(struct Node *)malloc(sizeof(struct Node ));
t->data=pre[i++];
t->lchild=t->rchild=NULL;
p->rchild=t;
p=t; }
else {
p=pop(&stk);
if (isEmpty(stk)) {
q=(struct Node *)malloc(sizeof(struct Node ));
q->data=9999;
q->rchild=q->lchild=NULL;
push(&stk,q); }
}
}}}
void Inorder(struct Node *p)
{
     if(p)
     {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
       }
}

int main()
{
    int pre[]={30,20,10,25,40,35,45,42,43};
    createpre(pre,9);
    Inorder(root);

    return 0;
}
