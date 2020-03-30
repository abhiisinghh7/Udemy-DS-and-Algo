//Combination Formula
#include <stdio.h>
int fact(int n)
{
if(n==0)return 1;
return fact(n-1)*n;
}
int nCr(int n,int r)
//Using iterative Factorial method
{
int num,den;
num=fact(n);
den=fact(r)*fact(n-r);
return num/den;
}
int NCR(int n,int r)
//Using Pascal's Triangle
{
if(n==r || r==0)
return 1;
return NCR(n-1,r-1)+NCR(n-1,r);
}
int main()
{
printf("%d \n",NCR(8,3));
return 0;
}
