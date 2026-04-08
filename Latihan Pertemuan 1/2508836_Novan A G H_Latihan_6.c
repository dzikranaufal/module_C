#include <stdio.h>

void daftarBuku(int jumlahBuku, char judulBuku[][50], int tahunTerbit[]) {
    printf("\nDaftar Buku Perpustakaan:\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("Buku No.%d\nJudul : %s\nTerbit: %d\n", i + 1, judulBuku[i], tahunTerbit[i]);
    }

}
int main() {
    int jumlahBuku;
    printf("Masukkan jumlah buku: ");
    scanf("%d", &jumlahBuku);
    char judulBuku[jumlahBuku][50];
    int tahunTerbit[jumlahBuku];

    for (int i = 0; i < jumlahBuku; i++)
    {
        printf("Judul buku ke-%d: ", i + 1);
        scanf(" %[^\n]", judulBuku[i]);
        printf("Tahun terbit : ");
        scanf(" %d", &tahunTerbit[i]);
    }
    daftarBuku(jumlahBuku, judulBuku, tahunTerbit);

    
    
    return 0;
}