//Parenthesis Matching
#include <stdio.h>
#include <stdlib.h>
struct Node
{
char data;
struct Node *next;
}*top=NULL;
void push(char x)
{
struct Node *t;
t=(struct Node*)malloc(sizeof(struct Node));
if(t==NULL)
printf("stack is full\n");
else
{
t->data=x;
t->next=top;
top=t;
}
}
char pop()
{
struct Node *t;
char x=-1;
if(top==NULL)
printf("Stack is Empty\n");
else
{
t=top;
top=top->next;x=t->data;
free(t);
}
return x;
}
void Display()
{
struct Node *p;
p=top;
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
printf("\n");
}
int isBalanced(char *exp)
{
int i;
for(i=0;exp[i]!='\0';i++)
{
if(exp[i]=='(')
push(exp[i]);
else if(exp[i]==')')
{
if(top==NULL)
return 0;
pop();
}
}
if(top==NULL)
return 1;
else
return 0;
}
     int isBalanced2(char *exp2)
    {
        int i;
        for(i=0;exp2[i]!='\0';i++)
        {
            if(exp2[i]=='{' || exp2[i]=='(' || exp2[i]=='[')
                push(exp2[i]);
            else if(exp2[i]=='}' || exp2[i]==')' || exp2[i]==']')
            {
                if(top==NULL)
                {
                    printf("Stack is Empty\n");
                    return 0;
                }
                else if((exp2[i]+top->data)/2 == 40 | (exp2[i]+top->data)/2 == 92 | (exp2[i]+top->data)/2 == 124)
                {
                    pop();
                }
            }
        }
        if(top==NULL)
        {
            printf("Stack is Balanced\n");
            return 1;
        }
        else
        {
            printf("Stack is Unbalanced \n");
            return 0;
        }
    }


        int main()
{
char *exp="((a+b)*(c-d))";
int x=isBalanced(exp);
if(x==1)
printf("Parenthesis is matching \n");
else
printf("Parenthesis error \n");
char *exp2="{((a+b]*[c-d])/e}";
x = isBalanced2(exp2);
if(x==1)
printf("Parenthesis is matching \n");
else
printf("Parenthesis error \n");
return 0;

}
