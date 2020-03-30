//Tower of Hanoi
//Towers are A,B,C
#include <stdio.h>
//First move (n-1) discs and move the largest disc then move the rest of the discs.
void TOH(int n,int A,int B,int C)
{
if(n>0)
{
//Move from A to B using C as auxillary
TOH(n-1,A,C,B);
//Move from A to C directly
printf("Move from Tower (%d to %d)\n",A,C);
//Move from B to C using C as auxillary
TOH(n-1,B,A,C);
}
}
int main()
{
TOH(5,1,2,3);
return 0;
}
