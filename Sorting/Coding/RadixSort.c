#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
int data;
struct node* next;
};
void insert(int x,struct node **t)
{
struct node *p= (struct node *)malloc(sizeof(struct node));
struct node *temp;
p->data=x;
p->next=NULL;
if(*t==NULL)
{
(*t)=p;
}
else
{
temp=(*t);
while(temp->next)
{
temp=temp->next;
}
temp->next=p;
}
}
int delete(struct node **p)
{
struct node *t;
int x=(*p)->data;
t=*p;
(*p)=(*p)->next;
free(t);
return x;
}
int digitcount(int x)
{
int c=0;
while(x>0)
{
x=x/10;
c++;
}
return c;
}
int max(int a[],int n)
{
int max=a[0],i;
for(i=0;i<n;i++)
{
if(a[i]>max)
{
max=a[i];
}
}
return max;
}
void radixsort1(int A[],int n,int m,struct node **bins)
{
int i,j,k;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
int k=(A[j]/(int)pow(10,i))%10;
struct node *in=bins[k];
insert(A[j],&bins[k]);
}
k=j=0;
while(k<n)
{
while(bins[k])
{
A[j++]=delete(&bins[k]);
}
k++;
}
}
for(i=0;i<n;i++)
{
printf("%d ",A[i]);
}
}
int main()
{
int i;
int A[]={455,32,22,45,654,8,1,234,4};
struct node **bins;
bins=(struct node **)malloc(10*sizeof(struct node *));
for(i=0;i<10;i++)
{
bins[i]=NULL;
}
int Max=max(A,8);
int m=digitcount(Max);
radixsort1(A,8,m,bins);
return 0;
}
