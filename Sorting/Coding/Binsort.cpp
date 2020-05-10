#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
void Insert(node** x,int y)
{
    node** p=x;
    node* z=*p;
    while(z && z->next)
    {
        z=z->next;
    }
    node* t=new node;
    if(!z)
    *x=t;
    else
        z->next=t;
    t->data=y;
    t->next=NULL;
}
int Delete(node** x)
{
    node* t=*x;
    int d=t->data;
    *x=t->next;
    delete t;
    return d;
}
int main()
{
    int A[]={6,3,9,10,15,6,8,12,3,6};
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    node** bins;
    int m=A[0];
    for(int i=1;i<10;i++)
    {
        if(A[i]>m)
            m=A[i];
    }
    bins=new node*[m+1];
    for(int i=0;i<=m;i++)
        bins[i]=NULL;
    for(int i=0;i<10;i++)
    {
        Insert(&bins[A[i]],A[i]);
    }
    int i=0,j=0;
    for(i=0;i<=m;i++)
    {
        while(bins[i]!=NULL)
        {
            A[j++]=Delete(&bins[i]);
        }
    }
    cout<<endl;
for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    return 0;
}
