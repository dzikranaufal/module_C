#include "2504189_DzikraNaufalBaihaqi_Latihan7_1.h"

int main(){
    Queue q;
    init(&q);
    
    int n;
    char title[20];

    printf("Masukan jumlah lagu: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Masukkan lagu ke-%d: ", i+1);
        scanf(" %[^\n]", title);
        enqueue(&q, title);
    }

    int i = q.head;
    while(1){
        printf("Berhasil menambahkan: %s\n", q.title[i]);
        if(i == q.tail) break;
        i = (i + 1) % max;
    }

    printf("Memutar lagu: %s\n", peek(&q));
    dequeue(&q);

    if(!isEmpty(q)) printf("Lagu berikutnya: %s\n", peek(&q));
    


    return 0;
}