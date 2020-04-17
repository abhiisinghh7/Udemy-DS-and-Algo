//Polynomial Representation
#include <stdio.h>
#include<stdlib.h>
struct Term
{
int coeff;
int exp;
};
struct Poly
//Array of terms or a pointer and dynamically create an Array of terms
{
int n;
struct Term *t;
};
void create(struct Poly *p)
{
int i;
printf("Number of non-zero terms?");
scanf("%d",&p->n);
p->t=(struct Term*)malloc(p->n*sizeof(struct Term));
printf("Enter terms Coefficient and Exponents\n");
for(i=0;i<p->n;i++)
scanf("%d %d",&p->t[i].coeff,&p->t[i].exp);
}
void display(struct Poly p)
{
int i;
for(i=0;i<p.n;i++)
printf("[%d(x^%d)]+",p.t[i].coeff,p.t[i].exp);
printf("\n");
}
int main()
{
struct Poly p;
create(&p);
display(p);
int x,y=0,res=0;
printf("Enter the value of x for the polynomial expression.\n");
scanf("%d",&x);
for(int i=0;i<(p.n);i++){
y = p.t[i].coeff*pow(x,p.t[i].exp);
res = res + y;}
printf("Result=%d",res);
return 0;
}
