#include <stdio.h>
#include <stdlib.h>
void main(){
int *A, n, ch, x, i ,j;
printf("Enter Dimensions");
scanf("%d",&n);
A= (int *)malloc(n*sizeof(int));
//Creating Array of required size
do {
printf("1. Create");
printf("2. Get");
printf("3. Set");
printf("4. Display");
scanf("%d",&ch);
//Display Menu
switch(ch)
{
case 1: for(i=0;i<=n;i++){
        scanf("%d",&A[i-1]);}
        printf("Entered.");
        break;
case 2: printf("Enter Indices");
        scanf("%d %d",&i,&j);
        if(i==j)
        {printf("%d",A[i-1]);}
        else
        {printf("0");}
        printf("Get executed.");
        break;
case 3: printf("Enter Row, Column and Element");
        scanf("%d %d %d",&i,&j,&x);
        if(i==j){
        A[i-1]= x;}
        printf("Set executed.");
        break;
case 4: for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
        if(i==j)
        printf("%d",A[i-1]);
        else
        printf("0");}
        printf("\n");
        }
        printf("Value Displayed.");
        break;
}
}while(ch<5);
}
/*
void create(int A[],int n) {}
int get(int X[], int i, int j) {}
void set(int X[], int i, int j, int x){}
void display(int A[],int n){}
*/
