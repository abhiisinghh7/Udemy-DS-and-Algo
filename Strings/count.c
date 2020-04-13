int main(){
char A[]= "Jaldi kaam karo";
int i, vcount=0, ccount=0, blank=0;
for(i=0;A[i]!='\0';i++)
{if(A[i] == 'a'||A[i] == 'e'||A[i] == 'i'||A[i] == 'o'||A[i] == 'u'||A[i] == 'A'||A[i] == 'E'||A[i] == 'I'||A[i] == 'O'||A[i] == 'U')
{vcount ++;}
else if(A[i] == ' ' && A[i] != ' '){blank ++;}
else
{ccount++;}}
printf("Total Vowels = %d",vcount);
printf("Total Consonants = %d",ccount);
return 0;}
