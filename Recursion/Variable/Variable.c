//Static Variables in Recursion
#include <stdio.h>
int fun1(int n)
{
static int x=0;
if(n>0)
{
x++;
return fun1(n-1)+x;
}
return 0;}
//Global Variabels in Recursion
int x=0;
int fun2(int n)
{
if(n>0)
{x++;
return fun2(n-1)+x;
}
return 0;}
int main() {
int r;
r=fun1(5);
printf("%d\n",r);
r=fun1(5);
printf("%d\n",r);
r=fun2(5);
printf("%d\n",r);
r=fun2(5);
printf("%d\n",r);
return 0;
}
