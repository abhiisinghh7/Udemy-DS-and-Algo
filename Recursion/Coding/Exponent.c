//Exponent/Power Function
//Power -> (m^n)
int power(int m,int n)
{
if(n==0)
return 1;
return power(m,n-1)*m;
}
int power1(int m,int n)
{
if(n==0)
return 1;
if(n%2==0)
return power1(m*m,n/2);
//If power is even
return m * power1(m*m,(n-1)/2);
//If power is odd
}
int main()
{
int r=power1(9,3);
printf("%d ",r);
int p=power(9,3);
printf("%d ",p);
return 0;
}

