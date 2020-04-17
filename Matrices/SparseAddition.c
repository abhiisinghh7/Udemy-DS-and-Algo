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
printf("Enter the Dimensions");
scanf("%d %d",&s->m,&s->n);
printf("Number of non-zero Elements");
scanf("%d",&s->num);
s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
printf("Enter the row, column of the non-zero Elements");
for(i=0;i<s->num;i++)
scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
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
}}
struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
struct Sparse *sum; //Sparse matrix created inside heap
int i,j,k;
i=j=k=0;
if(s1->n != s2->n && s1->m != s2->m)
return NULL;
sum=(struct Sparse *)malloc(sizeof(struct Sparse)); //Object of Sparse Matrix created
sum->ele=(struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));
//Dynamically defined size of array for storing elements
while(i<s1->num && j<s2->num)
{
if(s1->ele[i].i<s2->ele[j].i)
//If s1 row number is smaller
sum->ele[k++]=s1->ele[i++];
else if(s1->ele[i].i>s2->ele[j].i)
//If s2 row number is smaller
sum->ele[k++]=s2->ele[j++];
else
//Now row number is equal
{
if(s1->ele[i].j<s2->ele[j].j)
sum->ele[k++]=s1->ele[i++];
else if(s1->ele[i].j>s2->ele[j].j)
sum->ele[k++]=s2->ele[j++];
else
//Both the row and column number is matching
{
sum->ele[k]=s1->ele[i];
sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;
}
}
}
for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
for(;j<s2->num;j++)sum->ele[k++]=s2->ele[j];
sum->m=s1->m;
sum->n=s1->n;
sum->num=k;return sum;
}
int main()
{
struct Sparse s1,s2,*s3;
printf("First Matrix\n");
create(&s1);
display(s1);
printf("Second Matrix\n");
create(&s2);
display(s2);
s3=add(&s1,&s2);
printf("Sum Matrix\n");
display(*s3);
return 0;
}
