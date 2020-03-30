//Factorial of N
int fact(int n)
//Recursion
{
if(n==0)
return 1;
return fact(n-1)*n;
}
int Ifact(int n)
//Iterative Method
//TC=O(n)
{
int f=1,i;
for(i=1;i<=n;i++)
f=f*i;
return f;
}
int main()
{
int r=Ifact(5);
printf("%d ",r);
int p=Ifact(6);
printf("%d ",p);
return 0;
}
