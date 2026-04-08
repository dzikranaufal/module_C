#include <stdio.h>
#include <stdlib.h>


int main() {
    int jumlah_peserta;
    printf("Masukkan Jumlah Peserta : ");
    scanf("%d", &jumlah_peserta);
    int skor_peserta[jumlah_peserta], total_skor = 0;

    for (int i = 0; i < jumlah_peserta; i++) {
        printf("Masukkan Skor Peserta ke-%d: ", i + 1);
        scanf("%d", &skor_peserta[i]);
        total_skor += skor_peserta[i];
    }
    printf("\nDaftar Skor Peserta:\n");
    for (int i = 0; i < jumlah_peserta; i++) {
        printf("Skor Peserta ke-%d: %d\n", i + 1, skor_peserta[i]);
    }
    printf("\nTotal Skor Semua Peserta: %d\n", total_skor);
    
    return 0;
}