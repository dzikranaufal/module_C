#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define max 10

typedef struct{
    int head;
    int tail;
    char title[max][20];
} Queue;

void init(Queue *q){q->head = q->tail = -1;}
bool isFull(Queue q){return ((q.tail + 1) % max == q.head);}
bool isEmpty(Queue q){return (q.head == -1);}
void enqueue(Queue *q, char data[]){ if(isFull(*q)) return;
    if(isFull(*q)) return;
    if(isEmpty(*q)) q->head = 0;
    else q->tail = (q->tail + 1) % max;
    strcpy(q->title[q->tail], data);
}
void dequeue(Queue *q){
    if(isEmpty(*q))return;
    if(q->head == q->tail) q->head = q->tail = -1;
    else q->head = (q->head + 1) % max;
}
char* peek(Queue *q){ return q->title[q->head];}

#endif
