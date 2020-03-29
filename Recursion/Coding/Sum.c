//Sum of N natural numbers
//Sum(n)=Sum(n+1)+n
int sum(int n)
//TC= O(n)
//SC= O(n)
{
if(n==0)
return 0;
return sum(n-1)+n;
}
int Isum(int n)
//TC = O(n)
{
int s=0,i;
for(i=1;i<=n;i++)
s=s+i;
return s;
}
int main()
{
int r=sum(5);
int p=sum(5);
printf("%d ",r);
printf("%d ",p);
return 0;
}
