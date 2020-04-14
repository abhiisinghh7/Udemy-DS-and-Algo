//Create a Hash table for all Alphabets
int main(){
char A[]= "finding";
int H[26]={0},i,j;
for(i=0;A[i]!='\0';i++){
//printf("%d \n",A[i]);
H[A[i]-97] += 1;
}
for(i=0;i<26;i++){
//printf("%d \n",H[i]);
if(H[i]>1){
printf("%c \n",i + 97);
printf("%d \n",H[i]);
}}}
