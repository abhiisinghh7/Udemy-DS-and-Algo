    #include <stdio.h>
    #include <stdlib.h>
    struct Node
    {
    struct Node *LChild,*RChild;
    int data;
    }*root=NULL;
    int *Insert(int key)/**Return-Type changed to int from void; Check comments at return statements for more info*/
    {
    struct Node *t=root,*p=NULL,*r=NULL;
    if(t==NULL)
    {
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->LChild=p->RChild=NULL;
    root=p;
    return 0;/**Changed from 'return;' to 'return 0;', since the function had return-type as void and it can't contain return*/
    }
    while(t)
    {
    r=t;
    if(key<t->data)
    t=t->LChild;
    else if(key>t->data)
    t=t->RChild;
    else
    return 0;/**Changed from 'return;' to 'return 0;', since the function had return-type as void and it can't contain return*/
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->LChild=p->RChild=NULL;
    if(key<r->data)
    r->LChild=p;
    else
    r->RChild=p;
    return 0;/**Added this statement because the return-type is changed to int instead of void*/
    }
    void Inorder(struct Node *p)
    {
    if(p)
    {
    Inorder(p->LChild);
    printf("%d ",p->data);
    Inorder(p->RChild);
    }
    }
    struct Node * Search(int key)
    {
    struct Node*t=root;
    while(t)
    {
    if(key==t->data)
    return t;
    else if(key<t->data)
    t=t->LChild;
    else if(key>t->data)
    t=t->RChild;
    }
    return NULL;
    };
    struct Node *RInsert(struct Node *p,int key)
    {
    struct Node *t=NULL;
    if(p==NULL)
    {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    t->LChild=t->RChild=NULL;
    return t;
    }
    if(key < p->data)
    p->LChild=RInsert(p->LChild,key);
    else if(key > p->data)
    p->RChild=RInsert(p->RChild,key);
    return p;
    }
    int Height(struct Node *p)
    {
    int x,y;
    if(p==NULL)return 0;
    x=Height(p->LChild);
    y=Height(p->RChild);
    return x>y?x+1:y+1;
    }
    struct Node *InPre(struct Node *p)
    {
    while(p && p->RChild!=NULL)
    p=p->RChild;
    return p;
    }
    struct Node *InSucc(struct Node *p)
    {
    while(p && p->LChild!=NULL)
    p=p->LChild;
    return p;
    }
    struct Node * Delete(struct Node *p,int key)
    {
    struct Node *q;
    if(p==NULL)
    return NULL;
    if(p->LChild==NULL && p->RChild==NULL)
    {
    if(p==root)
    root=NULL;
    free(p);
    return NULL;
    }
    if(key < p->data)
    p->LChild=Delete(p->LChild,key);
    else if(key > p->data)
    p->RChild=Delete(p->RChild,key);
    else
    {
    if(Height(p->LChild)>Height(p->RChild))
    {
    q=InPre(p->LChild);
    p->data=q->data;
    p->LChild=Delete(p->LChild,q->data);
    }
    else
    {
    q=InSucc(p->RChild);
    p->data=q->data;
    p->RChild=Delete(p->RChild,q->data);
    }
    }
    return p;
    }
    struct stack
    {
    int size;
    int top;
    struct Node**S;
    };
    void create(struct stack *st,int n)
    {
    st->size=n;
    st->top=-1;
    st->S=(struct Node **)malloc((st->size*sizeof(struct Node *)));
    }
    void push(struct stack *st,struct Node *x)
    {
    if(st->top==st->size-1)
    return;
    else
    {
    st->top++;
    st->S[st->top]=x;
    }
    }
    struct Node* pop(struct stack *st)
    {
    struct Node* x=0;
    if(st->top==-1)
    return NULL;/**Changed from 'return -1;' to 'return NULL' since the return-type is of 'struct Node*' */
    else
    {
    x=st->S[st->top];
    st->top--;
    }
    return x;
    }
    struct Node * stackTop(struct stack st)
    {
    if(st.top==-1)
    return NULL;
    else
    return st.S[st.top];
    }
    int isEmpty(struct stack st)
    {
    if(st.top==-1)
    return 1;
    return 0;
    }
    int isFull(struct stack st)
    {
    if(st.top==st.size-1)
    return 1;
    return 0;
    }
    void Create_tree_from_preorder(int Pre[],int n)
    {
    struct stack st;
    create(&st,100);
    int i=0;
    struct Node *t,*p,*q;
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=Pre[i++];
    root->LChild=root->RChild=NULL;
    p=root;
    while(i<n)
    {
    if(Pre[i]<p->data)
    {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=Pre[i++];
    t->LChild=t->RChild=NULL;
    p->LChild=t;
    push(&st,p);
    p=t;
    }
    else
    {
    if(Pre[i]>p->data && Pre[i]<stackTop(st)->data)
    {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=Pre[i++];
    t->LChild=t->RChild=NULL;
    p->RChild=t;
    p=t;
    }
    else
    {
    p=pop(&st);
    if(isEmpty(st))
    {
    q=(struct Node *)malloc(sizeof(struct Node));
    q->data=1000;
    q->LChild=q->RChild=NULL;
    push(&st,q);
    }
    }
    }
    }
    }
    void Create_tree_from_postorder(int post[],int n)
    {
    struct stack st;
    create(&st,100);
    int i=n-1;
    struct Node *p,*q,*t;
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=post[i--];
    root->LChild=root->RChild=NULL;
    p=root;
    while(i>-1)
    {
    if(post[i]>p->data)
    {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=post[i--];
    t->LChild=t->RChild=NULL;
    p->RChild=t;
    push(&st,p);
    p=t;
    }
    else
    {
    if(post[i]<p->data && post[i]>stackTop(st)->data)
    {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=post[i--];
    t->LChild=t->RChild=NULL;
    p->LChild=t;
    p=t;
    }
    else
    {
    p=pop(&st);
    if(isEmpty(st))
    {
    q=(struct Node *)malloc(sizeof(struct Node));
    q->data=-10;
    q->LChild=q->RChild=NULL;
    push(&st,q);}
    }
    }}}
    int main()
    {
    int pre[]={30,20,10,15,25,40,50,45};
    int post[]={4,5,2,6,7,3,1};
    Create_tree_from_postorder(post,7);
    Inorder(root);

    return 0;
    }
