#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Buku {
    int isbn;
    char judul[100];
    char pengarang[100];
    int tahunTerbit;
    struct Buku* prev;
    struct Buku* next;
} Buku;

Buku* head = NULL;
Buku* tail = NULL;
int nextISBN = 1000;

Buku* createNode(int isbn, char* judul, char* pengarang, int tahunTerbit) {
    Buku* newNode = (Buku*)malloc(sizeof(Buku));
    newNode->isbn = isbn;
    strcpy(newNode->judul, judul);
    strcpy(newNode->pengarang, pengarang);
    newNode->tahunTerbit = tahunTerbit;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void tambahBuku() {
    char judul[100], pengarang[100];
    int tahunTerbit;
    
    printf("Judul: ");
    getchar();
    fgets(judul, sizeof(judul), stdin);
    judul[strcspn(judul, "\n")] = 0;
    
    printf("Pengarang: ");
    fgets(pengarang, sizeof(pengarang), stdin);
    pengarang[strcspn(pengarang, "\n")] = 0;
    
    printf("Tahun Terbit: ");
    scanf("%d", &tahunTerbit);
    
    Buku* newNode = createNode(nextISBN++, judul, pengarang, tahunTerbit);
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    
    if (tahunTerbit < head->tahunTerbit) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    
    if (tahunTerbit >= tail->tahunTerbit) {
        if (tahunTerbit == tail->tahunTerbit) {
            Buku* current = tail;
            while (current->prev != NULL && current->prev->tahunTerbit == tahunTerbit)
                current = current->prev;
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) current->next->prev = newNode;
            current->next = newNode;
            if (newNode->next == NULL) tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        return;
    }
    
    Buku* current = head;
    while (current != NULL && current->tahunTerbit <= tahunTerbit) {
        if (current->tahunTerbit == tahunTerbit) {
            while (current->next != NULL && current->next->tahunTerbit == tahunTerbit)
                current = current->next;
            break;
        }
        current = current->next;
    }
    
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev) current->prev->next = newNode;
    current->prev = newNode;
    if (newNode->prev == NULL) head = newNode;
}

void updateBukuByISBN() {
    int isbn, tahunBaru;
    char judulBaru[100], pengarangBaru[100];
    printf("Masukkan ISBN: ");
    scanf("%d", &isbn);
    
    Buku* current = head;
    while (current != NULL && current->isbn != isbn)
        current = current->next;
    
    if (current == NULL) {
        printf("Buku dengan ISBN %d tidak ditemukan\n", isbn);
        return;
    }
    
    printf("Judul baru: ");
    getchar();
    fgets(judulBaru, sizeof(judulBaru), stdin);
    judulBaru[strcspn(judulBaru, "\n")] = 0;
    
    printf("Pengarang baru: ");
    fgets(pengarangBaru, sizeof(pengarangBaru), stdin);
    pengarangBaru[strcspn(pengarangBaru, "\n")] = 0;
    
    printf("Tahun terbit baru: ");
    scanf("%d", &tahunBaru);
    
    strcpy(current->judul, judulBaru);
    strcpy(current->pengarang, pengarangBaru);
    current->tahunTerbit = tahunBaru;
}

void hapusBukuAwal() {
    if (head == NULL) {
        printf("Tidak ada buku untuk dihapus\n");
        return;
    }
    
    Buku* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    else tail = NULL;
    free(temp);
}

void hapusBukuAkhir() {
    if (head == NULL) {
        printf("Tidak ada buku untuk dihapus\n");
        return;
    }
    
    Buku* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = NULL;
    else head = NULL;
    free(temp);
}

void hapusBukuByISBN() {
    int isbn;
    printf("Masukkan ISBN: ");
    scanf("%d", &isbn);
    
    if (head == NULL) {
        printf("Tidak ada buku untuk dihapus\n");
        return;
    }
    
    Buku* current = head;
    while (current != NULL && current->isbn != isbn)
        current = current->next;
    
    if (current == NULL) {
        printf("Buku dengan ISBN %d tidak ditemukan\n", isbn);
        return;
    }
    
    if (current->prev) current->prev->next = current->next;
    else head = current->next;
    
    if (current->next) current->next->prev = current->prev;
    else tail = current->prev;
    
    free(current);
}

void tampilkanSemuaBuku() {
    if (head == NULL) {
        printf("Tidak ada buku dalam perpustakaan\n");
        return;
    }
    
    Buku* current = head;
    while (current != NULL) {
        printf("[%d] %d - %s\n", current->isbn, current->tahunTerbit, current->judul);
        current = current->next;
    }
}

int main() {
    int pilihan;
    
    do {
        printf("\n=== SISTEM MANAJEMEN PERPUSTAKAAN ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Update Buku by ISBN\n");
        printf("3. Hapus Buku Awal\n");
        printf("4. Hapus Buku Akhir\n");
        printf("5. Hapus Buku by ISBN\n");
        printf("6. Tampilkan Semua Buku\n");
        printf("7. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        if (pilihan == 1) tambahBuku();
        else if (pilihan == 2) updateBukuByISBN();
        else if (pilihan == 3) hapusBukuAwal();
        else if (pilihan == 4) hapusBukuAkhir();
        else if (pilihan == 5) hapusBukuByISBN();
        else if (pilihan == 6) tampilkanSemuaBuku();
        else if (pilihan == 7) printf("Terima kasih\n");
        else printf("Pilihan tidak valid\n");
        
    } while (pilihan != 7);
    
    return 0;
}