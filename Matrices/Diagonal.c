//Diagonal Matrix C
#include <stdio.h>
struct Matrix
//Array to store diagonal elememts
{
int A[10];
int n;
};
void set(struct Matrix *m,int i,int j,int x)
{
if(i==j)
//If indices are equal, set an element at that particular index.
m->A[i-1]=x;
}
int Get(struct Matrix m,int i,int j)
{
if(i==j)
return m.A[i-1];
else
return 0;
}
void Display(struct Matrix m)
{
int i,j;
for(i=0;i<m.n;i++)
{
for(j=0;j<m.n;j++)
{
if(i==j)
printf("%d ",m.A[i]);
else
printf("0 ");
}
printf("\n");
}
}
int main(){
struct Matrix m;
m.n = 4;
set(&m,1,1,5);
set(&m,2,2,8);
set(&m,3,3,9);
set(&m,4,4,12);
Display(m);}
