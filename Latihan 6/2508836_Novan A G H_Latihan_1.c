#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "1.h"


int main()
{
    Stack kurung;
    initStack(&kurung);
    char ekspresi[MAX_SIZE];
    printf("Masukkan ekspresi : ");
    scanf("%s", ekspresi);

    int len = strlen(ekspresi);
    for (int i = 0; i < len; i++)
    {
        char c = ekspresi[i];
        if (c == '(')
        {
            push(&kurung, c);
        }
        else if (c == ')')
        {
            if (isEmpty(&kurung))
            {
                printf("Kurung Tidak Seimbang\n");
                return 0;
            }
            pop(&kurung);
        }
    }
    if (isEmpty(&kurung))
    {
        printf("Kurung Seimbang\n");
    }
    else
    {
        printf("Kurung tidak Seimbang\n");
    }
}
