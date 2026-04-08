#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct
{
    char data[MAX][50];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return (s->top == -1);
}
int isFull(Stack *s)
{
    return (s->top == MAX - 1);
}

void push(Stack *s, char value[])
{
    if (isFull(s))
    {
        printf("Error : Stack FULL !!\n");
    }
    else
    {
        strcpy(s->data[++s->top], value);
        printf("Lagu %s ditambahkan ke playlist\n", value);
    }
}

char *pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Error : Stack Empty !!\n");
        return NULL;
    }
    else
    {
        return (s->data[s->top--]);
    }
}

void tampilPlaylist(Stack *s)
{
    printf("\n=== Tampil Playlist ===\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d. %s\n", s->top - i + 1, s->data[i]);
    }
    printf("\n");
}