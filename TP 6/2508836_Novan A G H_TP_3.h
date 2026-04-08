#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef struct 
{
    int data[MAX];
    int top;
}Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    return (s->top == -1);
}

int isFULL(Stack *s){
    return (s->top == MAX-1);
}

void push(Stack *s, int value){
    if (isFULL(s))
    {
        printf("Error : Stack Penuh!! \n");
        return;
    }
    s->data[++s->top] = value;
}

char pop(Stack *s){
    if (isEmpty(s))
    {
        printf("Error : Stack Kosong!!\n");
        return 0;
    }
    return s->data[s->top--];
}
