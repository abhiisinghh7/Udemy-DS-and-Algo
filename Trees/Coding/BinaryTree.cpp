#include<iostream>
#include<stdio.h>
#include "Queuecpp.h"
using namespace std;
class Tree
{
Node *root;
//Now Node is private
public:
Tree(){root=NULL;}
void CreateTree();
void Preorder(){Preorder(root);}
void Preorder(Node *p);
void Postorder(){Postorder(root);}
void Postorder(Node *p);
void Inorder(){Inorder(root);}
void Inorder(Node *p);
void Levelorder(){Levelorder(root);}
void Levelorder(Node *p);
int Height(){return Height(root);}
int Height(Node *root);
};
void Tree::CreateTree()
{
Node *p,*t=NULL;
int x;
Queue q(100);
printf("Enter root value \n");
scanf("%d",&x);
root=new Node;
root->data=x;
root->lchild=root->rchild=NULL;q.enqueue(root);
while(!q.isEmpty())
{
p=q.dequeue();
printf("Enter left child of %d\n ",p->data);
scanf("%d",&x);
if(x!=-1)
{
t=new Node;
t->data=x;
t->lchild=t->rchild=NULL;
p->lchild=t;
q.enqueue(t);
}
printf("Enter right child of %d\n ",p->data);
scanf("%d",&x);
if(x!=-1)
{
t=new Node;
t->data=x;
t->lchild=t->rchild=NULL;
p->rchild=t;
q.enqueue(t);
}
}
}
void Tree::Preorder(struct Node *p)
{
if(p)
{
printf("%d ",p->data);
Preorder(p->lchild);
Preorder(p->rchild);
}
}
void Tree::Inorder(struct Node *p){
if(p)
{
Inorder(p->lchild);
printf("%d ",p->data);
Inorder(p->rchild);}}
void Tree::Postorder(struct Node *p)
{
if(p)
{
Postorder(p->lchild);
Postorder(p->rchild);
printf("%d ",p->data);
}
}
void Tree::Levelorder(struct Node *p)
{
Queue q(100);
printf("%d ",root->data);
q.enqueue(root);
while(!q.isEmpty())
{
root=q.dequeue();
if(root->lchild)
{
printf("%d ",root->lchild->data);
q.enqueue(root->lchild);
}
if(root->rchild)
{
printf("%d ",root->rchild->data);
q.enqueue(root->rchild);}
}}
int Tree::Height(struct Node *root)
{
int x=0,y=0;
if(root==NULL)
return 0;
x=Height(root->lchild);
y=Height(root->rchild);
if(x>y)
return x+1;
else
return y+1;
}
int main() {
Tree t;
t.CreateTree();
cout<<"Preorder ";
t.Preorder();
cout<<endl;
cout<<"Inorder ";
t.Inorder();
cout<<endl;
cout<<"Postorder ";
t.Postorder();
cout<<endl;
cout<<"Height ";
printf("%d",t.Height());
return 0;
}
