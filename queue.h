#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>
#define max 5

typedef struct{
    int data[max];
    int head;
    int tail;
}Queue;

void create(Queue *Q){
    Q->head = -1;
    Q->tail = -1;
}

bool isEmpty(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q){
    return ((Q.tail + 1) % max == Q.head);
}

void insertQueue(Queue *Q, int data){
    if(isFull(*Q)){
        printf("penuh mas\n");
        return;
    }

    if(isEmpty(*Q)){
        Q->head = 0;
        Q->tail = 0;
    }else{
        Q->tail = (Q->tail + 1) % max;
    }

    Q->data[Q->tail] = data;
}

void deleteQueue(Queue *Q){
    if(isEmpty(*Q)){
        printf("kosong mas");
        return;
    }

    if(Q->head == Q->tail){
        Q->head = Q->tail = -1;
    }else{
        Q->head = (Q->head + 1) % max;
    }
}

void display(Queue *Q){
    if(isEmpty(*Q)){
        printf("kosong\n");
        return;
    }

    int i = Q->head;
    while(i != Q->head){
        printf("%d ", Q->data[i]);
        i = (i + 1) % max;
    }
    printf("%d ", Q->data);
}

#endif
