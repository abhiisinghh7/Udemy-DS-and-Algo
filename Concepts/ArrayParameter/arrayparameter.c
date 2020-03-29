//Sample PR
void fun(int A[],int n){
int i;
for(i=0;i<n;i++){
printf("%d",A[i]);
}}
int * funn(int n){
int *p;
p=(int *)malloc(n*sizeof(int));
return(p);
}
int main(){
int *B;
B = funn(5);
int A[5]={1,2,3,4,5};
fun(A,5);
}
