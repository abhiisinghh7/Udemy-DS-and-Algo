#include <iostream>
using namespace std;
class Node
{
public:
Node *lchild,*rchild;
int data;
};
class tree
{
Node *root;
public:
Node* retroot(){return root;}
tree(){root=NULL;}
void treecreate();
void preorder(Node *);
void po(Node *);
void preiter(Node *);
void initer(Node *);
void poiter(Node *);
};
class Stack
{
int top;
Node *p[7];
int flag[7]={0};
public:
void push(Node *);
void setFlag(int v){flag[top]=v;}
int getFlag(){return flag[top];}
Node *pop();
Stack(){top=-1;}
int isemp(){if(top==-1) return 1; return 0;}
};
void Stack::push(Node *q)
{++top;
p[top]=q;
}
Node* Stack::pop()
{
if(top==-1)
return NULL;
else
{
Node *q=p[top];--top;
return q;
}
}
void tree::poiter(Node *t)
{
Stack s;
int f;
while(t || !s.isemp())
{
if(t)
{
s.push(t);
s.setFlag(0);
t=t->lchild;
}
else
{
f=s.getFlag();
t=s.pop();
if(f==0)
{
s.push(t);
s.setFlag(1);
t=t->rchild;
}
else
{
cout<<"\n"<<t->data<<"\n";
t=NULL;
}
}
}
}
void tree::preiter(Node* r)
{
Stack s;
while(r!=NULL || !s.isemp())
{
if(r!=NULL)
{
cout<<"\n"<<r->data<<"\n";
s.push(r);
r=r->lchild;
}
else
{
r=s.pop();
r=r->rchild;
}
}
}
void tree::initer(Node* r)
{
Stack s;
while(r!=NULL || !s.isemp())
{
if(r!=NULL)
{
// cout<<"\n"<<r->data<<"\n";
s.push(r);
r=r->lchild;
}
else
{
r=s.pop();
cout<<"\n"<<r->data<<"\n";
r=r->rchild;
}
}
}
void tree::po(Node *p)
{
if(p)
{
po(p->lchild);
po(p->rchild);
cout<<p->data<<endl;
}
}
class Queue
{
int f;
int r;
int s;
Node **q;
public:
Queue(int x){s=x;f=r=0;q=new Node*[s];}
void enque(Node*);
Node *deq();
int isempty();
~Queue(){delete []q;}
};
void Queue::enque(Node *x)
{
if((r+1)%s==f)
{
cout<<"\nQueue is Full\n";
}
else{
r=(r+1)%s;
q[r]=x;}
}
Node* Queue::deq()
{
if(f==r)
{
cout<<"\nQueue Empty\n";
return NULL;
}
else
{
Node* x;
f=(f+1)%s;
x=q[f];
return x;}
}
int Queue::isempty()
{
if(r==f)
return 1;
return 0;
}
void tree::treecreate()
{
Queue q(7);
Node *t,*p;
int x;
cout<<"\nEnter value of root node\n";
cin>>x;
t=new Node;
t->data=x;
root=t;
t->lchild=t->rchild=NULL;
q.enque(root);
while(!q.isempty())
{
p=q.deq();
cout<<"\nEnter left child of "<<p->data<<endl;
cin>>x;
if(x!=-1)
{
t=new Node;
t->data=x;
t->lchild=t->rchild=NULL;
p->lchild=t;
q.enque(t);
}
cout<<"\nEnter right child of "<<p->data<<endl;
cin>>x;
if(x!=-1)
{
t=new Node;
t->data=x;
t->lchild=t->rchild=NULL;
p->rchild=t;
q.enque(t);
}
}}
void tree::preorder(Node *p)
{
if(p)
{
cout<<p->data<<"\n";
preorder((p->lchild));
preorder(p->rchild);
}
}
int main()
{
tree t;
t.treecreate();
cout<<"PreOrder"<<endl;
t.preorder(t.retroot());
cout<<"Iterative InOrder"<<endl;
t.initer(t.retroot());
cout<<"Iterative PostOrder"<<endl;
t.poiter(t.retroot());
cout<<"PostOrder"<<endl;
t.po(t.retroot());
return 0;
}
