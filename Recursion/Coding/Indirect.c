//Indirect Recursion
#include <stdio.h>
void funB(int n);
//Function B is defined before it used as it is called in function A else error.
void funA(int n)
{
if(n>0)
{
printf("%d ",n);
funB(n-1);
}
}
void funB(int n)
{
if(n>1)
{
printf("%d ",n);
funA(n/2);
}
}
int main()
{
funA(20);
return 0;
}
