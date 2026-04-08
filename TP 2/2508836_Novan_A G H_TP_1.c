#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Buku
{
    int id;
    char ISBN[20];
    char judul[50];
    char kategori[20];
    struct Buku *NextAlamat;
} element;

element *head = NULL;
int id = 0;

element *createBuku(char ISBN[], char judul[], char kategori[])
{
    element *bukuBaru = (element *)malloc(sizeof(element));
    bukuBaru->id = ++id;
    strcpy(bukuBaru->ISBN, ISBN);
    strcpy(bukuBaru->judul, judul);
    strcpy(bukuBaru->kategori, kategori);
    bukuBaru->NextAlamat = NULL;
    return bukuBaru;
}

int cekISBN(char ISBN[])
{
    element *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->ISBN, ISBN) == 0)
        {
            return 1;
        }
        temp = temp->NextAlamat;
    }
    return 0;
}

void tambahDataBuku()
{
    char ISBN[20], judul[50], kategori[20];
    printf("Masukkan ISBN: ");
    scanf("%s", ISBN);
    printf("Masukkan Judul: ");
    scanf(" %[^\n]", judul);
    printf("Masukkan Kategori: ");
    scanf("%s", kategori);
    if (cekISBN(ISBN))
    {
        printf("Buku dengan ISBN '%s' sudah ada! Data tidak boleh duplikat.\n", ISBN);
        return;
    }
    element *bukuBaru = createBuku(ISBN, judul, kategori);
    if (head == NULL)
    {
        head = bukuBaru;
    }
    else
    {
        element *temp = head;
        while (temp->NextAlamat != NULL)
        {
            temp = temp->NextAlamat;
        }
        temp->NextAlamat = bukuBaru;
    }
    printf("\nBuku berhasil ditambahkan!\n");
    printf("ID Buku : %d\n", bukuBaru->id);
}

void tampilDataBukuKategori()
{
    char kategori[20];
    printf("Masukkan kategori yang ingin ditampilkan: ");
    scanf("%s", kategori);
    printf("\n=== DAFTAR SEMUA BUKU BERDASARKAN KATEGORI ===\n");
    printf("%-15s %-30s %-15s\n", "ISBN", "Judul", "Kategori");
    printf("===============================================================\n");
    element *temp = head;
    int found = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->kategori, kategori) == 0)
        {
            printf("%-5d %-15s %-30s %-15s\n", temp->id, temp->ISBN, temp->judul, temp->kategori);
            found = 1;
        }
        temp = temp->NextAlamat;
    }
    if (!found)
    {
        printf("Tidak ada buku dengan kategori '%s' ditemukan.\n", kategori);
    }
}

void tampilDataBuku()
{
    printf("\n=== Menu Tampilkan Data ===\n");
    printf("1. Tampilkan Semua Buku\n");
    printf("2. Tampilkan Buku Berdasarkan Kategori\n");
    printf("Pilih opsi (1-2): ");
    int opsi;
    scanf("%d", &opsi);

    if (opsi == 2)
    {
        tampilDataBukuKategori();
    }
    else
    {
        element *temp = head;
        int index = 0;
        printf("\n=== DAFTAR SEMUA BUKU ===\n");
        printf("%-5s %-15s %-30s %-15s\n", "Index", "ISBN", "Judul", "Kategori");
        printf("===============================================================\n");
        while (temp != NULL)
        {
            printf("%-5d %-15s %-30s %-15s\n", index, temp->ISBN, temp->judul, temp->kategori);
            temp = temp->NextAlamat;
            index++;
        }
    }
}

void editDataBuku()
{
    char ISBN[20], judul[50], kategori[20];
    printf("Masukkan ISBN buku yang ingin diedit: ");
    scanf("%s", ISBN);
    element *temp = head;
    while (temp != NULL && strcmp(temp->ISBN, ISBN) != 0)
    {
        temp = temp->NextAlamat;
    }
    if (temp != NULL)
    {
        printf("\n=== Data Buku Ditemukan ===\n");
        printf("ISBN: %s\n", temp->ISBN);
        printf("Judul: %s\n", temp->judul);
        printf("Kategori: %s\n", temp->kategori);
        printf("\n=== Masukkan Data Baru ===\n");

        printf("Masukkan ISBN baru: ");
        scanf("%s", ISBN);
        printf("Masukkan Judul baru: ");
        scanf(" %[^\n]", judul);
        printf("Masukkan Kategori baru: ");
        scanf("%s", kategori);
        strcpy(temp->ISBN, ISBN);
        strcpy(temp->judul, judul);
        strcpy(temp->kategori, kategori);
        printf("\nBuku berhasil diupdate!\n");
    }
    else
    {
        printf("Buku dengan ISBN '%s' tidak ditemukan!\n", ISBN);
    }
}

void hapusDataBuku()
{
    printf("\n=== Menu Hapus Data ===\n");
    printf("\n--- Data Sebelum Penghapusan ---\n");
    element *temp = head;
    int index = 0;
    printf("\n=== DAFTAR SEMUA BUKU ===\n");
    printf("%-5s %-15s %-30s %-15s\n", "Index", "ISBN", "Judul", "Kategori");
    printf("===============================================================\n");
    while (temp != NULL)
    {
        printf("%-5d %-15s %-30s %-15s\n", index, temp->ISBN, temp->judul, temp->kategori);
        temp = temp->NextAlamat;
        index++;
    }

    char ISBN[20];
    printf("Masukkan ISBN buku yang ingin dihapus: ");
    scanf("%s", ISBN);
    temp = head;
    element *node_sebelumnya = NULL;
    while (temp != NULL && strcmp(temp->ISBN, ISBN) != 0)
    {
        node_sebelumnya = temp;
        temp = temp->NextAlamat;
    }
    if (temp != NULL)
    {
        printf("\n=== Detail Buku ===\n");
        printf("ISBN: %s\n", temp->ISBN);
        printf("Judul: %s\n", temp->judul);
        printf("Kategori: %s\n", temp->kategori);
        printf("\nApakah Anda yakin ingin menghapus buku ini? (y/n): ");
        char konfirmasi;
        scanf(" %c", &konfirmasi);
        if (konfirmasi == 'y' || konfirmasi == 'Y')
        {
            if (node_sebelumnya == NULL)
            {
                head = temp->NextAlamat;
            }
            else
            {
                node_sebelumnya->NextAlamat = temp->NextAlamat;
            }
            free(temp);
            printf("Buku berhasil dihapus!\n");

            printf("\n--- Data Setelah Penghapusan ---\n");
            element *temp = head;
            int index = 0;
            printf("\n=== DAFTAR SEMUA BUKU ===\n");
            printf("%-5s %-15s %-30s %-15s\n", "Index", "ISBN", "Judul", "Kategori");
            printf("===============================================================\n");
            while (temp != NULL)
            {
                printf("%-5d %-15s %-30s %-15s\n", index, temp->ISBN, temp->judul, temp->kategori);
                temp = temp->NextAlamat;
                index++;
            }
        }
        else
        {
            printf("Penghapusan dibatalkan.\n");
        }
    }
    else
    {
        printf("Buku dengan ISBN '%s' tidak ditemukan!\n", ISBN);
        return;
    }
}

int main()
{
    int pilihan;
    do
    {
        printf("\n=== PROGRAM MANAJEMEN BUKU ===\n");

        printf("1. Tambah Data Buku\n");
        printf("2. Tampilkan Data Buku\n");
        printf("3. Edit Data Buku\n");
        printf("4. Hapus Data Buku\n");
        printf("5. Keluar\n");
        printf("===============================================================\n");
        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahDataBuku();
            break;
        case 2:
            tampilDataBuku();
            break;
        case 3:
            editDataBuku();
            break;
        case 4:
            hapusDataBuku();
            break;
        case 5:
            printf("Terima kasih!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);

    return 0;
}