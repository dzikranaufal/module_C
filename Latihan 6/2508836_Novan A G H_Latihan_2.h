#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct
{
    char data[MAX];
    int top;
} Kalimat;

void init(Kalimat *k)
{
    k->top = -1;
}

int isEmpty(Kalimat *k)
{
    return (k->top == -1);
}

int isFULL(Kalimat *k)
{
    return (k->top == MAX - 1);
}

void push(Kalimat *k, char data)
{
    if (isFULL(k))
    {
        printf("Stack Penuhh!!\n");
        return;
    }
    k->data[++k->top] = data;
}

char pop(Kalimat *k)
{
    if (isEmpty(k))
    {
        printf("Stack Kosong !!\n");
        return '\0';
    }
    return k->data[k->top--];
}