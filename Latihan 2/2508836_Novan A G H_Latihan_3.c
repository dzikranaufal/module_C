#include <stdio.h>

typedef struct
{
    int x, y;
} Titik;

int cekSikuSiku(Titik *A, Titik *B, Titik *C)
{
    int AB = ((B->x - A->x) * (B->x - A->x)) + ((B->y - A->y)*(B->y - A->y));
    int BC = ((C->x - B->x) * (C->x - B->x)) + ((C->y - B->y)*(C->y - B->y));
    int AC = ((C->x - A->x) * (C->x - A->x)) + ((C->y - A->y)*(C->y - A->y));
    int status = 0;
    if (AB > BC && AB > AC)
    {
        if (AB == BC + AC)
        {
            status = 1;
        }
    }
    else if (BC > AC)
    {
        if (BC == AB + AC)
        {
            status = 1;
        }
    }
    else
    {
        if (AC == AB + BC)
        {
            status = 1;
        }
    }

    return status;
}

int main()
{
    Titik A, B, C;
    printf("Titik A (x y): ");
    scanf("%d %d", &A.x, &A.y);
    printf("Titik B (x y): ");
    scanf("%d %d", &B.x, &B.y);
    printf("Titik C (x y): ");
    scanf("%d %d", &C.x, &C.y);

    if (cekSikuSiku(&A, &B, &C))
    {
        printf("Segitiga Tersebut adalah segitiga siku-siku.\n");
    }
    else
    {
        printf("Segitiga Tersebut bukan segitiga siku-siku.\n");
    }

    return 0;
}