#ifndef DC824D53_B006_4DD5_81EE_78EAE1969396
#define DC824D53_B006_4DD5_81EE_78EAE1969396
#ifndef header_h
#define header_h

#define max 10

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    int head;                  
    int tail;                 
    char name[max][20];        
    double total[max];        
}Queue;

// inisialisasi queue jadi kosong
void init(Queue *q){ q->head=q->tail=-1;}
// cek penuh: kalo next tail kena head berarti full
bool isFull(Queue q){return ((q.tail + 1) % max == q.head);}
// cek kosong: head & tail masih -1
bool isEmpty(Queue q){return (q.head == -1 && q.tail == -1);}
// nambah data ke queue (enqueue)
void enqueue(Queue *q, char name[], double total){
    // kalo penuh ga bisa masuk
    if(isFull(*q)) return;
    // kalo kosong, head = tail di 0
    if(isEmpty(*q)) q->head = q->tail = 0;
    // kalo ga, tail maju (circular)
    else q->tail = (q->tail + 1) % max;
    // simpen data ke posisi tail
    strcpy(q->name[q->tail], name);
    q->total[q->tail] = total;
}
// hapus data depan (dequeue)
void dequeue(Queue *q){
    // kalo kosong ga ada yg dihapus
    if(isEmpty(*q)) return;
    // kalo cuma 1 data, reset lagi ke kosong
    if(q->head == q->tail) q->head = q->tail = -1;
    // kalo lebih, head maju (circular)
    else q->head = (q->head + 1) % max;
}
// nampilin semua isi queue dari head ke tail
void display(Queue q){
    // kalo kosong ga ada yg ditampilin
    if(isEmpty(q)) return;
    int i = q.head;
    // looping dari head sampe tail
    while(1){
        printf("Nama: %s - Total: %.0lf\n", q.name[i], q.total[i]); 
        // stop kalo udah nyampe tail
        if(i == q.tail) break;
        // maju index (circular)
        i = (i + 1) % max;
    }
    printf("\n");
}
#endif


#endif /* DC824D53_B006_4DD5_81EE_78EAE1969396 */
