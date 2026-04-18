#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 100

typedef struct{
    int head;
    int tail;
    char nama[max][50];
} Queue;

void init(Queue *q){
    q->head = q->tail = -1;
}

bool isEmpty(Queue q){
    return q.head == -1;
}

bool isFull(Queue q){
    return (q.tail + 1) % max == q.head;
}

void enqueue(Queue *q, char data[]){
    if(isFull(*q)) return;
    if(isEmpty(*q)) q->head = 0;
    q->tail = (q->tail + 1) % max;
    strcpy(q->nama[q->tail], data);
}

void dequeue(Queue *q){
    if(isEmpty(*q)) return;
    if(q->head == q->tail) q->head = q->tail = -1;
    else q->head = (q->head + 1) % max;
}

char* peek(Queue *q){
    return q->nama[q->head];
}

int size(Queue q){
    if(isEmpty(q)) return 0;
    if(q.tail >= q.head) return q.tail - q.head + 1;
    return max - q.head + q.tail + 1;
}

#endif /* E3F22189_2BA2_4B82_969A_89B138226BCA */
