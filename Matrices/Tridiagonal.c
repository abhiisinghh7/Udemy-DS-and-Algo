#include <stdio.h>
#include <stdlib.h>
struct matrix {
int *a;
int n; };
void set(struct matrix *m,int i,int j,int x)
{ if(i-j==1)
{ m->a[i-2]=x; }
else if(i-j==0)
{ m->a[(m->n-1)+(i-1)]=x; }
else if(i-j==-1)
{m->a[(m->n-1)+(m->n)+(i-1)]=x; }
else
{ }}
void get(struct matrix m,int i,int j) {
if(i-j==1)
{
printf("%d",m.a[i-2]);
}
else if(i-j==0)
{
printf("%d",m.a[(m.n-1)+(i-1)]);
}
else if(i-j==-1)
{
printf("%d", m.a[(m.n-1)+(m.n)+(i-1)]);
}
else
{
printf("0");
}}
void display(struct matrix m) {
int i,j;
for(i=0;i<m.n;i++) // i & j should start from 1
{
for(j=0;j<m.n;j++)
{
if(i-j==1)
{
printf("%d ",m.a[i-2]);
}
else if(i-j==0)
{
printf("%d ",m.a[(m.n-1)+(i-1)]);
}
else if(i-j==-1)
{
printf("%d ",m.a[(m.n-1)+(m.n)+(i-1)]);
}
else
{
printf("0 ");
}}
printf("\n");
}}
int main()
{
struct matrix m;
int i,j,x;
printf("ENTER THE SIZE OF MATRIX\n");
scanf("%d",&m.n);
m.a=(int *)malloc( 3*(m.n)-1*sizeof(int));
printf("enter all elements");
for(i=1;i<=m.n;i++) {
for(j=1;j<=m.n;j++) {
scanf("%d",&x);
set(&m,i,j,x);
}}
printf("ELEMENTS ARE\n");
display(m);
return 0; }

