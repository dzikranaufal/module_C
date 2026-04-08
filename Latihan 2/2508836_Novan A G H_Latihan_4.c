#include <stdio.h>
typedef struct
{
    char Kota[20];
    char kodePos[10];
} Alamat;

typedef struct
{
    char nama[20];
    char jabatan[20];
    Alamat alamat;
} Pegawai;

void tampilPegawai(Pegawai *pegawai, int n)
{
    printf("\n========== Data Pegawai ==========\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nama\t\t: %s\n", (pegawai + i)->nama);
        printf("Jabatan\t\t: %s\n", (pegawai + i)->jabatan);
        printf("Kota\t\t: %s\n", (pegawai + i)->alamat.Kota);
        printf("Kode Pos\t: %s\n", (pegawai + i)->alamat.kodePos);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Masukkan jumlah pegawai: ");
    scanf("%d", &n);
    Pegawai pegawai[n];
    for (int i = 0; i < n; i++)
    {
        printf("Masukkan data pegawai ke-%d:\n", i + 1);
        printf("Nama: ");
        scanf(" %[^\n]", pegawai[i].nama);
        printf("Jabatan: ");
        scanf(" %[^\n]", pegawai[i].jabatan);
        printf("Kota: ");
        scanf(" %[^\n]", pegawai[i].alamat.Kota);
        printf("Kode Pos: ");
        scanf("%s", pegawai[i].alamat.kodePos);
    }
    tampilPegawai(pegawai, n);

    return 0;
}

