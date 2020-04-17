//Sparse Matrix using C
#include <stdio.h>
#include<stdlib.h>
struct Element
{
int i; //Row number
int j; //Column Number
int x; //Value of the element
};
struct Sparse
{
int m; //Rows
int n; //Columns
int num; //Number of non-zero elements
struct Element *ele; //Dynamic size array of non-zero elements
};
void create(struct Sparse *s)
{
int i;
printf("Enter Dimensions");
scanf("%d %d",&s->m,&s->n);
printf("Number of non-zero elements");
scanf("%d",&s->num);
s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
//s->e = new Elements[s->num]; For C++
printf("Enter the non-zero Elements with respective row and column");
for(i=0;i<s->num;i++)
scanf("%d %d %d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
}
void display(struct Sparse s)
{
int i,j,k=0;
for(i=0;i<s.m;i++)
{
for(j=0;j<s.n;j++){
if(i==s.ele[k].i && j==s.ele[k].j)
printf("%d ",s.ele[k++].x);
else
printf("0 ");
}
printf("\n");
}
}
int main()
{
struct Sparse s;
create(&s);
printf("Sparse Matrix\n");
display(s);
return 0;
}
