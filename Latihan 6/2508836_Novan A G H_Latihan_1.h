#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

typedef struct
{
    char stack[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return (s->top == -1);
}

int isFull(Stack *s)
{
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, char data)
{
    if (isFull(s))
    {
        printf("ERROR : STACK PENUH!!\n");
        return;
    }
    s->stack[++s->top] = data;
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->stack[s->top--];
    }
    return '\0';
}