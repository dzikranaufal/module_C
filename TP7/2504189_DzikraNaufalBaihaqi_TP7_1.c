#include "2504189_DzikraNaufalBaihaqi_TP7_1.h"

int main(){
    Queue q;
    // inisialisasi queue biar siap dipake (kosong dulu)
    init(&q);
    
    int n;
    // input jumlah pelanggan (dibatesin max 10)
    printf("Masukkan jumlah pelanggan (max. 10): ");
    scanf("%d", &n);
    // masukin data pelanggan ke queue
    inputQueue(&q, n);
    // nampilin isi queue (waktu tiap pelanggan)
    display(q);
    // nampilin total / akumulasi waktu tunggu
    showWaitingTime(&q);
}