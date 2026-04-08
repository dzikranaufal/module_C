#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "2.h"
int main()
{
    Kalimat stack;
    init(&stack);
    char kalimat[MAX];
    printf("Masukkan Kalimat : ");
    scanf(" %[^\n]", kalimat);
    int len = strlen(kalimat);
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (kalimat[i] != ' ')
        {
            push(&stack, kalimat[i]);
            counter++;
        }
        else
        {
            for (int j = 0; j < counter; j++)
            {
                printf("%c", pop(&stack));
            }
            counter = 0;
            printf(" ");
        }
    }
    for (int j = 0; j < counter; j++)
    {
        printf("%c", pop(&stack));
    }
}