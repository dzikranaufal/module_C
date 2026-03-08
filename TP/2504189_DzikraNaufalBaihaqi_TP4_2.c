#include "2504189_DzikraNaufalBaihaqi_TP4_2.h"

int main(){

    Node *head = NULL;
    int pilihan;

    do{

        printf("\n--- MENU KOPI WESKER ---\n");
        printf("1. Tambah Antrean Biasa (Belakang)\n");
        printf("2. Tambah Pelanggan VIP (Depan)\n");
        printf("3. Sisip EBELUM Nomor Tertentu\n");
        printf("4. Sisip SESUDAH Nomor Tertentu\n");
        printf("5. Hapus Nomor Antrean\n");
        printf("6. Update Data Pesanan\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d",&pilihan);
        getchar();

        int nomor,target;
        char nama[100];
        char pesanan[100];

        switch(pilihan){

        case 1:

            printf("Nomor Antrean: ");
            scanf("%d",&nomor);
            getchar();

            if(isExist(head,nomor)){
                printf("Nomor antrean sudah ada!\n");
                break;
            }

            printf("Nama Pelanggan: ");
            scanf(" %[^\n]",nama);

            printf("Pesanan: ");
            scanf(" %[^\n]",pesanan);

            insertLast(&head,nomor,nama,pesanan);

            printf("Pelanggan %s berhasil ditambahkan.\n",nama);

            printList(head);
        break;

        case 2:

            printf("Nomor Antrean: ");
            scanf("%d",&nomor);
            getchar();

            if(isExist(head,nomor)){
                printf("Nomor antrean sudah ada!\n");
                break;
            }

            printf("Nama Pelanggan: ");
            scanf(" %[^\n]",nama);

            printf("Pesanan: ");
            scanf(" %[^\n]",pesanan);

            insertFirst(&head,nomor,nama,pesanan);

            printf("Pelanggan %s (VIP) berhasil masuk di awal.\n",nama);

            printList(head);

        break;

        case 3:

            printf("Cari nomor antrean target: ");
            scanf("%d",&target);

            printf("Nomor baru: ");
            scanf("%d",&nomor);
            getchar();

            if(isExist(head,nomor)){
                printf("Nomor antrean sudah ada!\n");
                break;
            }

            printf("Nama: ");
            scanf(" %[^\n]",nama);

            printf("Pesanan: ");
            scanf(" %[^\n]",pesanan);

            insertBefore(&head,target,nomor,nama,pesanan);

            printList(head);

        break;

        case 4:

            printf("Cari nomor antrean target: ");
            scanf("%d",&target);

            printf("Nomor baru: ");
            scanf("%d",&nomor);
            getchar();

            if(isExist(head,nomor)){
                printf("Nomor antrean sudah ada!\n");
                break;
            }

            printf("Nama: ");
            scanf(" %[^\n]",nama);

            printf("Pesanan: ");
            scanf(" %[^\n]",pesanan);

            insertAfter(&head,target,nomor,nama,pesanan);

            printList(head);

        break;

        case 5:

            printf("Masukkan nomor antrean yang ingin dihapus: ");
            scanf("%d",&nomor);

            deleteByNumber(&head,nomor);

            printf("Antrean nomor %d berhasil dihapus/dibatalkan.\n",nomor);

            printList(head);

        break;

        case 6:

            printf("Nomor antrean yang diupdate: ");
            scanf("%d",&nomor);
            getchar();

            printf("Pesanan Baru: ");
            scanf(" %[^\n]",pesanan);

            updatePesanan(head,nomor,pesanan);

            printf("Pesanan nomor %d berhasil diperbarui.\n",nomor);

            printList(head);

        break;

        case 0:
            printf("dadah");
        break;
        }

    }while(pilihan != 0);

}