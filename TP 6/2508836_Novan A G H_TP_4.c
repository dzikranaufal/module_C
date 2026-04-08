#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4.h"

int main(){
    Stack list;
    init(&list);
    int jumlah;
    printf("Jumlah Data : ");
    scanf("%d", &jumlah);
    int input;
    printf("Data ASCII : ");
    for (int i = 0; i < jumlah; i++)
    {
        scanf("%d", &input);
        push(&list, input);
    }
    printf("Data ASCII : ");
    for (int i = 0; i < jumlah; i++)
    {
        printf("%c ", (char)pop(&list));
    }
    
    
}