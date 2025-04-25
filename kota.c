#include "kota.h"

ElemenKota A[MAX_KOTA];
int nKota = 0;

static void insertLast(NodeNama **head, const char *nama) {
    NodeNama *baru = (NodeNama *)malloc(sizeof(NodeNama));
    strcpy(baru->nm, nama);
    baru->next = NULL;

    if (*head == NULL)
        *head = baru;
    else {
        NodeNama *temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}

static void deleteAll(NodeNama *head) {
    while (head) {
        NodeNama *del = head;
        head = head->next;
        free(del);
    }
}

void tambahKota(const char *namaKota) {
    if (nKota >= MAX_KOTA) {
        puts("Kapasitas kota penuh!");
        return;
    }
    strcpy(A[nKota].kota, namaKota);
    A[nKota].head = NULL;
    nKota++;
}

void tambahNama(const char *namaKota, const char *nama) {
    int idx = cariKota(namaKota);
    if (idx == -1) {
        puts("Kota tidak ditemukan.");
        return;
    }
    insertLast(&A[idx].head, nama);
}

void hapusKota(const char *namaKota) {
    int idx = cariKota(namaKota);
    if (idx == -1) {
        puts("Kota tidak ditemukan.");
        return;
    }
    deleteAll(A[idx].head);
    for (int i = idx; i < nKota - 1; ++i)
        A[i] = A[i + 1];
    nKota--;
    puts("Kota & seluruh nama dihapus.");
}

void tampilkanSemua(void) {
    for (int i = 0; i < nKota; ++i) {
        printf("\nKota: %s\n", A[i].kota);
        for (NodeNama *p = A[i].head; p; p = p->next)
            printf(" - %s\n", p->nm);
    }
}

void tampilkanPerKota(const char *namaKota) {
    int idx = cariKota(namaKota);
    if (idx == -1) { puts("Kota tidak ditemukan."); return; }
    printf("\nKota: %s\n", A[idx].kota);
    for (NodeNama *p = A[idx].head; p; p = p->next)
        printf(" - %s\n", p->nm);
}

int cariKota(const char *namaKota) {
    for (int i = 0; i < nKota; ++i)
        if (strcmp(A[i].kota, namaKota) == 0) return i;
    return -1;
}
