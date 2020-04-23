    #include <stdio.h>
    #include <stdlib.h>

    struct Node
    {
        int data;
        struct Node *next;
    }*top1 = NULL;

    struct Node *top2 = NULL;

    void push1(int x)
    {
        struct Node *t;

        t  = (struct Node *)malloc(sizeof(struct Node));

        if(t == NULL)
        {
            printf("stack full\n");
        }
        else
        {
            t->data = x;
            t->next = top1;
            top1 = t;
        }
    }

    int pop1()
    {
        struct Node *p;
        int i;
        int x= -1;
        if(top1 == NULL)
        {
            printf("stack is empty\n");
        }
        else
        {
            p = top1;
            top1 = top1->next;
            x = p->data;
            free(p);
        }
        return x;
    }


    void push2(int x)
    {
        struct Node *t;

    t  = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
    {
        printf("stack full\n");
    }
    else
    {
        t->data = x;
        t->next = top2;
        top2 = t;
    }
}

int pop2()
{
    struct Node *p;
    int i;
    int x= -1;
    if(top2 == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        p = top2;
        top2 = top2->next;
        x = p->data;
        free(p);
    }
    return x;
}

int isEmpty1()
{
    if(top1 == NULL)
    {
        return 1;
    }
    return 0;
}


int isEmpty2()
{
    if(top2 == NULL)
    {
        return 1;
    }
    return 0;
}


void enqueue(int data)
{
    push1(data);
}

int dequeue()
{
    int x = -1;
    if(isEmpty2())
    {
        if(isEmpty1())
        {
            printf("Queue is Empty\n");
            return x;
        }
        else{
            while(!isEmpty1())
            {
                push2(pop1());
            }
        }
    }

    return pop2();
}

void display1()
{
    struct Node *p = top1;

    while(p!=NULL)
    {
        printf("%d " , p->data);
        p = p->next;
    }

    printf("\n");
}

void display2()
{
    struct Node *p = top2;

    while(p!=NULL)
    {
        printf("%d " , p->data);
        p = p->next;
    }

    printf("\n");
}



int main()
{
    enqueue(6);
    enqueue(3);
    enqueue(9);
    enqueue(5);
    enqueue(4);
    enqueue(2);

    printf("\n");
    display1();

    printf("\n");
    printf("%d" , dequeue());
    printf("\n");
    printf("%d" , dequeue());
    printf("\n");
    printf("%d" , dequeue());
    printf("\n");
    printf("%d" , dequeue());
    printf("\n");
    printf("%d" , dequeue());
    printf("\n");
    printf("%d" , dequeue());




}
