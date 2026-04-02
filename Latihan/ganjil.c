#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char namaTask[100];
    char deadline[11];
    int prioritas;
    struct Task* prev;
    struct Task* next;
} Task;

Task* head = NULL;
Task* tail = NULL;
int nextID = 1;

Task* createNode(int id, char* namaTask, char* deadline, int prioritas) {
    Task* newNode = (Task*)malloc(sizeof(Task));
    newNode->id = id;
    strcpy(newNode->namaTask, namaTask);
    strcpy(newNode->deadline, deadline);
    newNode->prioritas = prioritas;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void tambahTask() {
    char namaTask[100], deadline[11];
    int prioritas;
    
    printf("Nama Task: ");
    getchar();
    fgets(namaTask, sizeof(namaTask), stdin);
    namaTask[strcspn(namaTask, "\n")] = 0;
    
    printf("Deadline (DD/MM/YYYY): ");
    fgets(deadline, sizeof(deadline), stdin);
    deadline[strcspn(deadline, "\n")] = 0;
    
    printf("Prioritas (1=Rendah, 2=Sedang, 3=Tinggi): ");
    scanf("%d", &prioritas);
    
    Task* newNode = createNode(nextID++, namaTask, deadline, prioritas);
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    
    if (prioritas > head->prioritas) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    
    if (prioritas <= tail->prioritas) {
        if (prioritas == tail->prioritas) {
            Task* current = tail;
            while (current->prev != NULL && current->prev->prioritas == prioritas)
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
    
    Task* current = head;
    while (current != NULL && current->prioritas >= prioritas) {
        if (current->prioritas == prioritas) {
            while (current->next != NULL && current->next->prioritas == prioritas)
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

void updateTaskByID() {
    int id, prioritasBaru;
    char namaBaru[100], deadlineBaru[11];
    printf("Masukkan ID Task: ");
    scanf("%d", &id);
    
    Task* current = head;
    while (current != NULL && current->id != id)
        current = current->next;
    
    if (current == NULL) {
        printf("Task dengan ID %d tidak ditemukan\n", id);
        return;
    }
    
    printf("Nama Task baru: ");
    getchar();
    fgets(namaBaru, sizeof(namaBaru), stdin);
    namaBaru[strcspn(namaBaru, "\n")] = 0;
    
    printf("Deadline baru (DD/MM/YYYY): ");
    fgets(deadlineBaru, sizeof(deadlineBaru), stdin);
    deadlineBaru[strcspn(deadlineBaru, "\n")] = 0;
    
    printf("Prioritas baru (1=Rendah, 2=Sedang, 3=Tinggi): ");
    scanf("%d", &prioritasBaru);
    
    strcpy(current->namaTask, namaBaru);
    strcpy(current->deadline, deadlineBaru);
    current->prioritas = prioritasBaru;
}

void hapusTaskAwal() {
    if (head == NULL) {
        printf("Tidak ada task untuk dihapus\n");
        return;
    }
    
    Task* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    else tail = NULL;
    free(temp);
}

void hapusTaskAkhir() {
    if (head == NULL) {
        printf("Tidak ada task untuk dihapus\n");
        return;
    }
    
    Task* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = NULL;
    else head = NULL;
    free(temp);
}

void hapusTaskByID() {
    int id;
    printf("Masukkan ID Task: ");
    scanf("%d", &id);
    
    if (head == NULL) {
        printf("Tidak ada task untuk dihapus\n");
        return;
    }
    
    Task* current = head;
    while (current != NULL && current->id != id)
        current = current->next;
    
    if (current == NULL) {
        printf("Task dengan ID %d tidak ditemukan\n", id);
        return;
    }
    
    if (current->prev) current->prev->next = current->next;
    else head = current->next;
    
    if (current->next) current->next->prev = current->prev;
    else tail = current->prev;
    
    free(current);
}

void tampilkanSemuaTask() {
    if (head == NULL) {
        printf("Tidak ada task dalam daftar\n");
        return;
    }
    
    Task* current = head;
    char* prioritasStr;
    
    while (current != NULL) {
        if (current->prioritas == 1) prioritasStr = "Rendah";
        else if (current->prioritas == 2) prioritasStr = "Sedang";
        else prioritasStr = "Tinggi";
        
        printf("[%d] %s – %s\n", current->id, current->namaTask, prioritasStr);
        current = current->next;
    }
}

int main() {
    int pilihan;
    
    do {
        printf("\n=== APLIKASI TO-DO LIST ===\n");
        printf("1. Tambah Task\n");
        printf("2. Update Task by ID\n");
        printf("3. Hapus Task Awal\n");
        printf("4. Hapus Task Akhir\n");
        printf("5. Hapus Task by ID\n");
        printf("6. Tampilkan Semua Task\n");
        printf("7. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        if (pilihan == 1) tambahTask();
        else if (pilihan == 2) updateTaskByID();
        else if (pilihan == 3) hapusTaskAwal();
        else if (pilihan == 4) hapusTaskAkhir();
        else if (pilihan == 5) hapusTaskByID();
        else if (pilihan == 6) tampilkanSemuaTask();
        else if (pilihan == 7) printf("Terima kasih\n");
        else printf("Pilihan tidak valid\n");
        
    } while (pilihan != 7);
    
    return 0;
}