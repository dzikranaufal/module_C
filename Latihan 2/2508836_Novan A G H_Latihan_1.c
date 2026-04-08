#include <stdio.h>

typedef struct {
    char judul[100];
    int tahun_terbit;
} Buku;

void cetakBuku(Buku *b, int n) {
    printf("\nDaftar Buku\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d. %s (%d)\n", i + 1, b[i].judul, b[i].tahun_terbit);
    }
}
int main() {
    int n;
    printf("Masukkan jumlah buku: ");
    scanf("%d", &n);
    Buku buku[n];
    for (int i = 0; i < n; i++) {
        printf("Masukkan judul buku ke-%d: ", i + 1);
        scanf(" %[^\n]", buku[i].judul);
        printf("Masukkan tahun terbit buku ke-%d: ", i + 1);
        scanf("%d", &buku[i].tahun_terbit);
    }
    cetakBuku(buku, n);
    return 0;
}

