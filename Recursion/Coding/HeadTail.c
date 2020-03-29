#include <stdio.h>
//Head Recursion
void fun1(int n)
{
if(n>0)
{
fun1(n-1);
printf("%d ",n);
}}
//Tail Recursion
void fun2(int n)
{
if(n>0)
{
printf("%d ",n);
fun2(n-1);
}}
int main() {
int x=5;
fun1(x);
fun2(x);
return 0;
}
