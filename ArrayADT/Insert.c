//Inserting and Appending in a Array
#include<stdio.h>
struct Array
{
int A[10];
int size;
int length;
};
void Display(struct Array arr)
{
int i;
printf("\nElements are\n");
for(i=0;i<arr.length;i++)
printf("%d ",arr.A[i]);
}
void Append(struct Array *arr,int x) {
//Adding element at the end
if(arr->length<arr->size)
//To check free space is available
arr->A[arr->length++]=x;
}
void Insert(struct Array *arr,int index,int x)
{
int i;
if(index>=0 && index <=arr->length)
//If Index i s valid or not
{
for(i=arr->length;i>index;i--)
//Shifting elments of the Array
arr->A[i]=arr->A[i-1];
arr->A[index]=x;
arr->length++;
}
}
int main()
{
struct Array arr1={{2,3,4,5,6},10,5};
Append(&arr1,15);
Insert(&arr1,2,20);
Display(arr1);
return 0;
}
