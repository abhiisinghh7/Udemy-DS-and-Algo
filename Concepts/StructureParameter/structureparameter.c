#include<stdio.h>
struct Rectangle
{
int length,breadth;
};
void changelength(struct Rectangle *p,int l){
p -> length = l; }
struct test
{
int A[5];
int n;};
int area(struct Rectangle r1){
//If we pass by reference as &r it doesn't work in C
r1.length++;
//Now actual length will be modified
return r1.length*r1.breadth;
}
void fun(struct test t){
t.A[0]=11;
t.A[2]=9;
}
int main(){
struct Rectangle r={10,5};
changelength(&r,20);
printf("%d",area(r));
struct test t={{2,4,6,8,20},5};
fun(t);
}
