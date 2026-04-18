#ifndef AA2A0F53_09C6_443E_A084_9AD9758AC7CE
#define AA2A0F53_09C6_443E_A084_9AD9758AC7CE
#ifndef header_h
#define header_h

#define max 10

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int head;
    int tail;
    float time[max];
} Queue;

//buat inisialisasi queue jadi start from -1
void init(Queue *q){q->head=q->tail=-1;}
//cek queue penuh jika nilai tail sekarang sama dengan head
bool isFull(Queue q){return ((q.tail + 1) % max == q.head);}
//cek queue kosong kalo queue masih psosisi di init atau index -1 
bool isEmpty(Queue q){return (q.head == -1 && q.tail == -1);}
//masukin data queue dengan param pointer ke q dan data yg dibutuhin
void enqueue(Queue *q, float time){
    //cek dulu kalo penuh berarti gabisa enqueue alias return
    if(isFull(*q)) return;
    //cek kalo queue masih kosong alias -1 berarti head = tail jadi 0
    if(isEmpty(*q)) q->head = q->tail = 0;
    //kalo engga nilai tail akan maju 1 index queue dan modulo max agar kembali ke 0 jika tail diujung
    else q->tail = (q->tail + 1) % max;
    //masukan data di param ke adt dengan index tail
    q->time[q->tail] = time;
}
//mengeluarkan data dari queue
void dequeue(Queue *q){
    //cek dulu kalo kosong queuenya mau hapus apa
    if(isEmpty(*q)) return;
    //kalo tail di head alias data cuma 1 berarti index jadi kosong kaya index init (-1)
    if(q->head == q->tail) q->head = q->tail = -1;
    //kalo engga, head maju 1 langkah dan daata sebelumnya dihapus
    else q->head = (q->head + 1) % max;
}
//prosedur input queue
void inputQueue(Queue *q, int n){
    // var lokal buat nampung jumlah barang sama waktu pelayanan
    int qty;
    float time;
    // loop buat tiap pelanggan
    for(int i = 0; i < n; i++){
        printf("Masukkan jumlah barang pelanggan ke-%d: ", i+1);
        scanf("%d", &qty);
        // hitung waktu: 1 barang = 30 detik -> jadi menit
        time = (qty * 30) / 60.0;
        // masukin waktu ke queue
        enqueue(q, time);
    }
}
//memunculkan queue 
void display(Queue q){
    //cek kalo queue kosong akan berhenti prosedurnya
    if(isEmpty(q)) return;
    int i = q.head;
    printf("\nData waktu layanan (menit): \n");
    //menggunakan while jika head berada ditengah index bukan di index 0
    while(1){
        printf("%.2f ", q.time[i]); 
        if(i == q.tail) break;
        i = (i + 1) % max;
    }
    printf("\n");
}
//memunculkan jumlah waktu dengan menjumlahkan durasi dari data i dengan data index i+1
void showWaitingTime(Queue *q){
    float total = 0;
    int client = 1;
    printf("Estimasi waktu tunggu:\n");
    while(!isEmpty(*q)){
        printf("pelanggan %d: %.2f menit\n", client, total);
        //total durasi dijumlahkan agar durasi selanjutnya bertambah dengan index i+1
        total += q->time[q->head];
        //setelah dialokasikan waktunya, data dequeue
        dequeue(q);
        client++;
    }
}


#endif 


#endif /* AA2A0F53_09C6_443E_A084_9AD9758AC7CE */
