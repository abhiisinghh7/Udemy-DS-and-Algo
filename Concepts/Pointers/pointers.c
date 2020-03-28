//Pointers can access Heap memory
//Used for parameter passing
#include<stdlib.h>
int main(){
int a=10;
int *q,*p;
q=&a;
printf("%d",a);
printf("%d",q);
p=(int *)malloc(5*sizeof(int));}
//In C++ p=new int[5];
