#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int value)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("ERROR : Stack Overflow! Stack sudah penuh.\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    printf("PUSH : %d berhasil dimasukkan ke stack. TOP = %d\n", value, s->top);
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("ERROR : Stack Underflow! Stack kosong.\n");
        return -1;
    }

    int removedValue = s->data[s->top];
    s->top--;
    printf("POP : %d berhasil dikeluarkan dari stack.\n", removedValue);
    return removedValue;
}

int isEmpty(Stack *s)
{

    return (s->top == -1);
}

int isFull(Stack *s)
{
    return (s->top == MAX_SIZE - 1);
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("[INFO] Stack Kosong, tidak ada elemen.\n");
        return -1;
    }
    return s->data[s->top];
}

void displayStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack : [ Kosong ]\n");
        return;
    }
    printf("Stack (TOP -> BOTTOM) : ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("[%d] ", s->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack myStack;
    initStack(&myStack);

    printf("=== DEMO OPERASI STACK ===\n\n");

    // --- Cek stack kosong ---
    printf("IsEmpty? %s\n", isEmpty(&myStack) ? "YA" : "TIDAK");
    displayStack(&myStack);

    printf("\n--- Melakukan PUSH ---\n");
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);
    displayStack(&myStack);

    // --- Cek stack penuh ---
    printf("\nIsFull? %s\n", isFull(&myStack) ? "YA" : "TIDAK");

    // --- PUSH saat penuh (test overflow) ---
    printf("\n--- Test Stack Overflow ---\n");
    push(&myStack, 99);

    // --- Lihat elemen teratas ---
    printf("\nPeek (elemen teratas): %d\n", peek(&myStack));

    // --- Melakukan POP ---
    printf("\n--- Melakukan POP ---\n");
    pop(&myStack);
    pop(&myStack);
    displayStack(&myStack);

    // --- POP semua elemen ---
    printf("\n--- POP semua elemen ---\n");
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);

    // --- Test Stack Underflow ---
    printf("\nIsEmpty? %s\n", isEmpty(&myStack) ? "YA" : "TIDAK");

    return 0;
}