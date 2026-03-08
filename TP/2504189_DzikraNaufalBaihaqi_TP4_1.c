#include "2504189_DzikraNaufalBaihaqi_TP4_1.h"

int main(){

    Node *head = NULL;

    addLast(&head, 101, "Avatar 2", "10:00");
    addLast(&head, 102, "John Wick", "13:00");

    int choice;
    
    do{
        printf("\n=== MANAJEMEN BIOSKOP ===\n");
        printf("1. Tambah Film (Awal/Akhir/Tengah)\n");
        printf("2. Update Film\n");
        printf("3. Hapus Film(Awal/Akhir)\n");
        printf("4. Lihat Seluruh Jadwal\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            addData(&head);
            break;
        case 2:
            updateData(&head);
            break;
        case 3:
            deleteData(&head);
            break;
        case 4:
            printList(head);
            break;
        case 5:
            printf("dadah\n");
            break;
        default:
            printf("Menu tidak valid\n");
        }

    } while (choice != 5);

}