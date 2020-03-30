#include<stdio.h>
#include<stdlib.h>
struct array{
int *A;
//Make Array inside heap and make this point to that
int size;
int length;
};
void Display(struct array arr){
printf("\nElements are\n");
for(int i=0;i<arr.length;i++)
{printf("%d",arr.A[i]);}}
int main(){
struct array arr;
int n,i;
printf("Enter size of the Array");
scanf("%d",&arr.size);
arr.A=(int *)malloc(arr.size*sizeof(int));
arr.length=0;

printf("Enter number of numbers");
scanf("%d",&n);
printf("Enter all Elements");
for(i=0;i<n;i++)
{scanf("%d",&arr.A[i]);}
arr.length=n;
//This will read all elemnts and store them in an Array.
Display(arr);
return 0;}
