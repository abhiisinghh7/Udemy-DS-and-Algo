//Taylor Series Horner’s Rule
//Total multiplications for 'n' terms= O(n)
//Multiplactions done at calling time itself
double e(int x, int n)
{
static double s;
if(n==0)
return s;
s=1+x*s/n;
return e(x,n-1);
}
int main()
{
printf("%lf \n",e(4,10));
return 0;
}
