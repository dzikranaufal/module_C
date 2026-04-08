#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3.h"

int main()
{
    Stack stack;
    init(&stack);
    char kata[MAX];
    printf("Masukkan kata : ");
    scanf("%s", kata);
    for (int i = 0; i < strlen(kata); i++)
    {
        push(&stack, kata[i]);
    }
    char palindrom[MAX];
    for (int i = 0; i < strlen(kata); i++)
    {
        palindrom[i] = pop(&stack);
    }
    palindrom[strlen(kata)] = '\0';
    if (strcmp(kata, palindrom) == 0)
    {
        printf("Palindrom\n");
    }else{
        printf("Bukan Palindrom\n");
    }
    
    
    
}