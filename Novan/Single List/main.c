#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    Node *head = NULL;

    insertAtFront(&head, "2508836", "Aufaa", "Pendidikan Ilmu Komputer", 20);
    insertAtFront(&head, "2508840", "Rina", "Pendidikan Ilmu Komputer", 19);

    insertAtEnd(&head, "2508837", "Mike", "Ilmu Komputer", 22);
    insertAtEnd(&head, "2508841", "Dedi", "Ilmu Komputer", 20);

    insertMiddleBefore(&head, "2508837", "2508838", "Zahid", "Sistem Informasi", 21);
    insertMiddleBefore(&head, "2508836", "2508842", "Nina", "Sistem Informasi", 21);

    insertMiddleAfter(&head, "2508836", "2508839", "Novan", "Teknik Informatika", 23);
    insertMiddleAfter(&head, "2508837", "2508843", "Rio", "Teknik Informatika", 22);

    updateNode(head, "2508840", "Rina Updated", "Pendidikan Ilmu Komputer", 20);

    deleteAtFront(&head);
    printfList(head);

    deleteAtEnd(&head);
    printList(head);

    deleteMiddleNode(&head, "2508838");
    printList(head);


    return 0;
}