#include "header.h"

int main() {
    Node *antrian = NULL;
    
    //--------------------------------------------------------------------nomor 1

    insertAwal(&antrian, 1, "Ryan", "Demam");
    insertAkhir(&antrian, 2, "Reybano", "Batuk");
    insertAkhir(&antrian, 3, "Akbar", "Flu");
    
    printList(antrian);
    
    //--------------------------------------------------------------------nomor 2
    
    insertAwal(&antrian, 0, "Radit", "Sesak Napas");
    insertTengahSebelum(&antrian, 3, 4, "Sasa", "Sakit Kepala");
    
    printList(antrian);
    
    //--------------------------------------------------------------------nomor 3

    update(&antrian, 1, "Ryan", "Tipes");
    insertTengahSesudah(&antrian, 4, 5, "Aura", "Maag");
    deleteAwal(&antrian);
    deleteAkhir(&antrian);
    
    printList(antrian);
    
    //--------------------------------------------------------------------nomor 4

    update(&antrian, 4, "Sasha", "Sakit Kepala");
    update(&antrian, 2, "Reybano", "Radang Tenggorokan");
    insertAkhir(&antrian, 6, "Galuh", "Luka Bakar");
    deleteTengah(&antrian, 5);
    
    printList(antrian);
    
    freeList(&antrian);
    
    return 0;
}