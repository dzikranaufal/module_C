#include "queue.h"

int main(){
    Queue q;
    create(&q);

    insertQueue(&q,20);
    insertQueue(&q,10);
    insertQueue(&q,20);
    insertQueue(&q,30);
    insertQueue(&q,40);

    display(&q);

    deleteQueue(&q);
    deleteQueue(&q);

    printf("\n");

    insertQueue(&q, 200);

    display(&q);
}