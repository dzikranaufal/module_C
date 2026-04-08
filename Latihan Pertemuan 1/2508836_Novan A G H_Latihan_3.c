#include <stdio.h>

int main() {
    char array[4][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Masukkan Baris[%d] Kolom[%d]: ", i + 1, j + 1);
            scanf(" %c", &array[i][j]);
        }
    }
    printf("\nIsi Array :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}