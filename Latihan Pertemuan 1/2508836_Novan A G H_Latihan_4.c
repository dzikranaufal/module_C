#include <stdio.h>

int main()
{
    int data[2][2][2];
    char nama_ruangan[][20] = {"Ruang Tamu", "Kamar Tidur"};
    char nama_waktu[][20] = {"Pagi", "Malam"};
    int total_lampu_menyala = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                printf("HARI %d, %s, %s (0/1): ",
                       i + 1,
                       nama_ruangan[j],
                       nama_waktu[k]);
                scanf("%d", &data[i][j][k]);
                if (data[i][j][k] == 1)
                {
                    total_lampu_menyala++;
                }
                
            }
        }
    }

    printf("\n\n--- Laporan Riwayat Lampu ---\n");
    for (int i = 0; i < 2; i++)
    {
        printf("HARI %d\n", i + 1);
        for (int j = 0; j < 2; j++)
        {
            printf("%s: [Pagi : %s] [Malam : %s]\n",
                   nama_ruangan[j],
                   data[i][j][0] == 1 ? "NYALA" : "MATI",
                   data[i][j][1] == 1 ? "NYALA" : "MATI");
        }
    }
    printf("Total lampu menyala selama 2 hari: %d kali\n", total_lampu_menyala);

    return 0;
}