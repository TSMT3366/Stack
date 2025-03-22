#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

#define MAX_SIZE 6

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack (Stack *st)
{
    st->top = -1;
}

int isEmpty (Stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull (Stack *st)
{
    if (st->top == MAX_SIZE - 1)
    {
        return 1;
    }
    return 0;
}

void push (Stack *st, int value)
{
    if (isFull(st))
    {
        printf("Stack is full, so can not be push value!\n");
    }
    else
    {
        st->top++;
        st->data[st->top] = value;
    }
}

int pop (Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty, so can not pop!\n");
        return -1;
    }
    else
    {
        int result = st->data[st->top];
        st->top--;
        return result;
    }
}

int peek (Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty, so can not peek!\n");
        return -1;
    }
    else
    {
        return st->data[st->top];
    }
}

void printfStack (Stack *st)
{
    printf ("Stack element(s):    \n");
    if (isEmpty(st))
    {
        printf ("EMPTY!!!\n");
    }
    else
    {
        int i;
        for (i=st->top; i>=0; i--)
        {
            printf("%d ", st->data[i]);
        }
        printf("\n");
    }
}

int main()
{
    Stack st;
    initStack(&st);

    push(&st, 6);
    push(&st, 7);
    push(&st, 5);
    push(&st, 4);
    push(&st, 8);
    push(&st, 9);

    printfStack(&st);

    push(&st, 10);
    printfStack(&st);

    pop(&st);
    printfStack(&st);

    int topValue = peek(&st);
    printf("Value top = %d\n", topValue);
    printfStack(&st);
    return 0;
}
