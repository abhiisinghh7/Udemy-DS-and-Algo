void fun1(int n)
//Printing done in calling time
{
if(n > 0)
{printf("%d",n);
fun1(n-1);}
}
void fun2(int n)
//Printing done in returning time
{
if(n > 0)
{fun2(n-1);
printf("%d",n);
}
}
void main(){
int x=5;
fun1(x);;
fun2(x);}
