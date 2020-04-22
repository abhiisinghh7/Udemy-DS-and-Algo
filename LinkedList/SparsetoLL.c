#include <stdio.h>
#include <stdlib.h>
struct node
{
int col;
int value;
struct node *next;
};
void create()
{
int m,n;
printf("enter the value of row and column \n");
scanf("%d %d",&m,&n);
struct node *a[m],*last;
for(int i=0;i<m;i++)
{
a[i]=NULL;
}
for(int i=0;i<m;i++)
{
last=NULL;
int nz,c,v;
printf("Enter the number of non zero elememts in the row %d \n",i);
scanf("%d",&nz);
for(int j=0;j<nz;j++)
{
printf("enter the column no \n");
scanf("%d",&c);
printf("Enter the Value \n");
scanf("%d",&v);
if(a[i]==NULL)
{
a[i]=(struct node *)malloc(sizeof(struct node));
a[i]->col=c;
a[i]->value=v;
a[i]->next=NULL;
last=a[i];
}
else{
last->next=(struct node *)malloc(sizeof(struct node));
last=last->next;
last->col=c;
last->value=v;
last->next=NULL;
}}}
printf("The Matrix is: ");
printf("\n");
struct node *p;
for(int i=0;i<m;i++)
{
p=a[i];
for(int j=0;j<n;j++)
{
if(p && j==p->col)
{
printf("%d ",p->value);
p=p->next;
}
else
printf("0 ");
}printf("\n");}
}
int main()
{
create();
return 0;
}


