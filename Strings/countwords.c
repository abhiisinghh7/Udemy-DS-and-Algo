int main(){
char A[]= "Jaldi kaam karo";
int count=0, i;
for(i=0;A[i]!='\0';i++){
if(A[i] == ' ' && A[i-1] != ' '){
count++;}}
printf("Total Words = %d",count+1);
return 0;}
