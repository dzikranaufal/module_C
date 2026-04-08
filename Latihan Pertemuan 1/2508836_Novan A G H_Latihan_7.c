#include <stdio.h>

void cekSkor(char nama[], float skor) {
    printf("\n--- Hasil Evaluasi ---\n");
    if (skor <= 12.0)
    {
        printf("Atlet atas nama %s dinyatakan LOLOS seleksi\n", nama);
    }else{
        printf("Atlet atas nama %s dinyatakan TIDAK LOLOS seleksi\n", nama);
    }

}
int main() {
    char nama[50];
    float skor;
    printf("Nama Atlet: ");
    scanf(" %[^\n]", nama);
    printf("Skor Lari (detik): ");
    scanf(" %f", &skor);
    cekSkor(nama, skor);
    
    
    return 0;
}