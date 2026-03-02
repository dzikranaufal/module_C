#include "header.h"

int main(){
    
    Node* mhs = NULL;

    addFirst(&mhs, "2504189", "Dzikra", "Komputer", 20);
    addLast(&mhs, "2505558", "Fuad", "Pendidikan", 12);
    
    printList(mhs);

    addMiddleAfter(&mhs,"2504189", "2504675", "sigit", "Komputer", 20);
    
    printList(mhs);
    return 0; 
}