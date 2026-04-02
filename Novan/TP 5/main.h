#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Song
{
    int id;
    char title[40];
    char mood[15];
    int duration;
    struct Song *next;
    struct Song *prev;
} Song;

int song_id = 1;

Song *createSong(char title[40], char mood[15], int duration, int is_edit)
{
    Song *newSong = (Song *)malloc(sizeof(Song));
    if (is_edit)
    {
        newSong->id = is_edit;
    }
    else
    {
        newSong->id = song_id++;
    }
    strcpy(newSong->title, title);
    strcpy(newSong->mood, mood);
    newSong->duration = duration;
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

int priority(char mood[15])
{
    if (strcmp(mood, "Energetic") == 0)
        return 3;
    else if (strcmp(mood, "Chill") == 0)
        return 2;
    else
        return 1;
}

void addSong(Song **head, char title[40], char mood[15], int duration, int is_edit)
{

    Song *newSong = createSong(title, mood, duration, is_edit);

    if (*head == NULL)
    {
        *head = newSong;
    }
    else
    {
        Song *temp = *head;
        Song *prev = NULL;
        while (temp != NULL && (priority(temp->mood) > priority(newSong->mood) || (strcmp(temp->mood, newSong->mood) == 0 && temp->duration >= newSong->duration)))
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        {
            temp->prev = newSong;
            newSong->next = temp;
            *head = newSong;
        }
        else if (temp == NULL)
        {
            prev->next = newSong;
            newSong->prev = prev;
        }
        else
        {
            newSong->prev = temp->prev;
            temp->prev->next = newSong;
            temp->prev = newSong;
            newSong->next = temp;
        }
    }
}

void showForward(Song *head)
{
    if (head == NULL)
    {
        printf("List Kosong\n");
    }
    else
    {
        Song *temp = head;
        printf("=== Playlist (Forward)===\n");
        while (temp != NULL)
        {
            printf("[%d] %-20s | %-15s | %d s\n", temp->id, temp->title, temp->mood, temp->duration);
            temp = temp->next;
        }
        printf("\n");
    }
}

void showBackward(Song *head)
{
    if (head == NULL)
    {
        printf("List Kosong\n");
    }
    else
    {

        Song *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("=== Playlist (Backward)===\n");
        while (temp != NULL)
        {
            printf("[%d] %-20s | %-15s | %d s\n", temp->id, temp->title, temp->mood, temp->duration);
            temp = temp->prev;
        }
        printf("\n");
    }
}

void updateTitle(Song **head, int target)
{
    char title[40];
    Song *temp = *head;
    while (temp != NULL && temp->id != target)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("ID tidak ditemukan !\n");
    }
    else
    {
        printf("Judul baru : ");
        scanf(" %[^\n]", title);
        strcpy(temp->title, title);
        printf("Judul berhasil di Update!\n");
    }
}

void updateDuration(Song **head, int target)
{
    Song *temp = *head;
    while (temp != NULL && temp->id != target)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("ID tidak ditemukan !\n");
    }
    else
    {
        int duration;

        printf("Durasi baru : ");
        scanf("%d", &duration);
        int old_id = temp->id;
        char old_title[40], old_mood[15];
        strcpy(old_title, temp->title);
        strcpy(old_mood, temp->mood);
        if (temp->prev == NULL && temp->next == NULL)
        {
            *head = NULL;
        }
        else if (temp->prev == NULL)
        {
            *head = temp->next;
            temp->next->prev = NULL;
        }
        else if (temp->next == NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
        addSong(head, old_title, old_mood, duration, old_id);
        printf("Durasi berhasil di Update!\n");
    }
}

void deleteFirst(Song **head)
{
    if (*head == NULL)
    {
        printf("List Kosong\n");
    }
    else
    {
        Song *temp = *head;
        if (temp->next == NULL)
        {
            *head = NULL;
        }
        else
        {
            *head = temp->next;
            temp->next->prev = NULL;
        }
        free(temp);
        printf("Data berhasil dihapus!!\n");
    }
}

void deleteLast(Song **head)
{
    if (*head == NULL)
    {
        printf("List Kosong\n");
    }
    else
    {
        Song *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->prev == NULL)
        {
            *head = NULL;
        }
        else
        {
            temp->prev->next = NULL;
        }
        free(temp);
        printf("Data berhasil dihapus!!\n");
    }
}

void deleteBy(Song **head, char title[40])
{
    Song *temp = *head;
    while (temp != NULL && strcmp(temp->title, title) != 0)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Lagu tidak ditemukan !\n");
        return;
    }
    else if (temp->prev == NULL && temp->next == NULL)
    {
        *head = NULL;
    }
    else if (temp->prev == NULL)
    {
        *head = temp->next;
        temp->next->prev = NULL;
    }
    else if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Lagu %s berhasil dihapus!!\n", title);
}