#include "2504189_DzikraNaufalBaihaqi_Latihan7_2.h"

int main(){
    Queue q;
    init(&q);

    int n, k;
    char temp[50];

    printf("Input jumlah pemain: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Pemain %d: ", i+1);
        scanf(" %[^\n]", temp);
        enqueue(&q, temp);
    }

    printf("Berapa kali operan sebelum kepanasan: ");
    scanf("%d", &k);

    int i = q.head;
    while(1){
        printf("%s ikutan main\n", q.nama[i]);
        if(i == q.tail) break;
        i = (i + 1) % max;
    }

    printf("=== Permainan Dimulai ===\n");

    int ronde = 1;

    while(size(q) > 1){
        for(int j = 0; j < k; j++){
            char name[50];
            strcpy(name, peek(&q));
            dequeue(&q);
            enqueue(&q, name);
        }

        printf("Putaran %d: %s kepanasan dan tereliminasi!\n", ronde, peek(&q));
        dequeue(&q);

        ronde++;
    }

    printf("=== Hasil Akhir ===\n");
    printf("Pemenang Permainan: %s!\n", peek(&q));

    return 0;
}