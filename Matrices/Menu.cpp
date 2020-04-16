#include<iostream>
using namespace std;
class Diagonal
{
int *A;
int n;
public:
Diagonal(int n)
{
this->n=n;
A=new int[n];
}
void create(){
int x;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cin>>x;
if(i==j){
A[i-1]=x;}
}}}
void set(int i,int j,int x)
{
if(i==j)
A[i-1]=x;
}
int get(int i,int j)
{
if(i==j)
return A[i-1];
else
return 0;
}
void display()
{
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
if(i==j)
cout<<A[i-1]<<" ";
else
cout<<"0 ";
}
cout<<endl;
}}
~Diagonal(){
delete []A;
}
};
int main() {
int n;
cout<<"Enter the dimension of matrix:";
cin>>n;
Diagonal dia(n);
int x;
cout<<"Enter the elements of Diagonal Matrix:";
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cin>>x;
dia.set(i,j,x); }}
int p,q;
cout<<"Enter the index of element to be retrieved: \n";
cin>>p>>q;
cout<<"\n"<<dia.get(p,q);
cout<<endl;
cout<<"Matrix elemnts are: \n";
dia.display();
}
