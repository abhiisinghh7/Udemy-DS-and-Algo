    #include <iostream>
    using namespace std;
    struct binarynode
    {
    int data;
    binarynode *lchild=NULL;
    binarynode *rchild=NULL;
    };
    struct stack1
    {
    binarynode* data;
    stack1 *next;
    }*top=NULL;
    binarynode* create()
    { int x;
    binarynode *newnode;
    newnode=new binarynode();
    cout<<"enter data"<<endl;
    cin>>x;
    if(x==-1)
    {
    return NULL;
    }
    newnode->data=x;
    cout<<"please enter the left child of"<<" "<<x<<endl;
    newnode->lchild=create();
    cout<<"please enter the right child of"<<" "<<x<<endl;
    newnode->rchild=create();
    return newnode;
    }
    void push(binarynode *x)
    {
    stack1 *s;
    s=new stack1;
    if(s==NULL)
    {
    cout<<"stack is full";
    }
    else{
    s->data=x;
    s->next=top;
    top=s;
    }
    }
    binarynode * pop()
    {
    binarynode *r=NULL;
    stack1 *temp=top;
    if(top==NULL)
    {
    cout<<"stack is empty";
    }
    else{
    r=top->data;
    top=top->next;
    free(temp);
    }
    return r;
    }
    void preorder1(binarynode *t)
    {
    if(t)
    {
    cout<<t->data<<" ";
    preorder1(t->lchild);
    preorder1(t->rchild);
    }
    }
    void iterativepreorder1(binarynode *r)
    {
    int x;
    while(r!=NULL||top!=NULL)
    {
    if(r!=NULL)
    {
    cout<<r->data<<",";
    x=r->data;
    push(r);
    r=r->lchild;
    }
    else{
    r=pop();
    r=r->rchild;
    }
    }
    }
    int main()
    {
    binarynode *root=NULL;
    root=create();
    preorder1(root);
    cout<<endl;
    iterativepreorder1(root);
    return 0;
    }
