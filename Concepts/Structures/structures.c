//Collection of Disimilar Data items under one name
#include<stdio.h>
struct Rectangle
{
int length,breadth;
};
struct card{
int face,shape,color;
};
struct student
{int roll;
char name[25];
char dept[10];
char address[50];
};
struct complex
{
int real;
int imag;
};
int main(){
struct card deck[52];
printf("Face value of 1st card is %d",deck[0].face);
deck[0].face=1;
deck[0].color=0;
deck[0].shape=0;
struct Rectangle r={10,5};
//r occupies 4 bytes
r.length=15;
r.breadth=10;
printf("Area of Rectangle is %d",r.length*r.breadth);
}
