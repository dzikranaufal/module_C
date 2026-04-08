#include <stdio.h>
#include <string.h>

int main()
{
    char kata[50];
    printf("Masukkan kata : ");
    scanf("%s", kata);
    int panjang = strlen(kata);
    if (panjang < 3)
    {
        printf("Jumlah Karakter tidak boleh kurang dari 3");
    }
    else if (panjang > 15)
    {
        printf("Jumlah Karakter tidak boleh lebih dari 15");
    }
    else
    {
        char kata_baru[panjang+1];
        for (int i = 0; i < panjang; i++)
        {
            if (kata[i] == 'a' || kata[i] == 'A')
            {
                kata_baru[i] = '1';
            }
            else if (kata[i] == 'e' || kata[i] == 'E')
            {
                kata_baru[i] = '2';
            }
            else if (kata[i] == 'i' || kata[i] == 'I')
            {
                kata_baru[i] = '3';
            }
            else if (kata[i] == 'o' || kata[i] == 'O')
            {
                kata_baru[i] = '4';
            }
            else if (kata[i] == 'u' || kata[i] == 'U')
            {
                kata_baru[i] = '5';
            }
            else
            {
                kata_baru[i] = kata[i];
            }
        }
        kata_baru[panjang] = '\0';
        printf("Dari %s, menjadi %s", kata, kata_baru);
    }


    return 0;
}