#include<stdio.h>
/*int main(){
int A[5]={2,3,4,5,6};
int B[5]={2,3};
int C[]={8,9,10};
int D[5]={0};
printf("%d ",A[3]);
printf(" %d",B[3]);
for(int i=0;i<5;i++){
printf(" A[%d]: %d ",i,A[i]);
printf("\n");
printf("Address of A[%d]: %d",i,&A[i]);}
return 0;}
*/
int main( ) {
unsigned int x[4][3] ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
printf("%u,%u, %u", x+3, *(x+3),*(x+2)+3); }
