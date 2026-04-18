#include "2504189_DzikraNaufalBaihaqi_TP7_2.h"

int main(){
    Queue kasir1, kasir2;
    // inisialisasi dua queue (kasir 1 & kasir 2)
    init(&kasir1);
    init(&kasir2);

    int choice;
    char name[20];
    double total;
    // tampilan menu awal
    printf("1. Tambah Pelanggan\n");
    printf("2. Tampilkan Semua Antrean\n");
    printf("0. Keluar\n");
    // loop menu selama belum pilih keluar
    do{
        printf("Pilih menu: ");
        scanf("%d", &choice);
        // menu tambah pelanggan
        if(choice == 1){
            printf("\nMasukkan nama: ");
            scanf(" %[^\n]", name);
            printf("Masukan total belanja: ");
            scanf("%lf", &total);
            // cek kasir 1 penuh
            if(isFull(kasir1)){
                // kalo kasir 2 juga penuh
                if(isFull(kasir2)){
                    printf("Kedua kasir penuh!\n\n");
                } 
                // kalo kasir 1 penuh tapi kasir 2 masih ada
                else {
                    printf("Kasir 1 penuh. %s masuk ke Kasir 2\n\n", name);
                    enqueue(&kasir2, name, total);
                }
            }
            // kalo kasir 1 masih ada tempat
            else{
                printf("%s masuk ke Kasir 1\n\n", name);
                enqueue(&kasir1, name, total);
            }
        // menu tampilin semua antrean
        }else if(choice == 2){
            // kalo kasir 2 kosong, berarti cuma kasir 1 aja
            if(isEmpty(kasir2)){
                printf("Daftar Antrian Kasir 1:\n");
                display(kasir1);
            }
            // kalo dua-duanya ada isi
            else{
                printf("Daftar Antrian Kasir 1:\n");
                display(kasir1);
                printf("Daftar Antrian Kasir 2:\n");
                display(kasir2);
            }
        // keluar program
        }else if(choice == 0){
            return 0;
        // input ga valid
        }else{
            printf("tidak valid");
        }
    }while(choice != 0);
}