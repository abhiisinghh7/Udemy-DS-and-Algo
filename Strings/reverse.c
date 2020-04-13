int main(){
char A[]= "Python";
char B[8];
int i,j,temp;
for(i=0;A[i]!='\0';i++){ }
i = i-1;
for(j=0;j<i;i--,j++){
temp = A[i];
A[i]= A[j];
A[j]= temp;
}
printf("A = %s", A);
printf("B = %s", B);}
