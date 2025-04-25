#ifndef KOTA_H
#define KOTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 10
#define MAX_STR  50

typedef struct tNama {
    char nm[MAX_STR];
    struct tNama *next;
} NodeNama;

typedef struct {
    char kota[MAX_STR];
    NodeNama *head;
} ElemenKota;

extern ElemenKota A[MAX_KOTA];
extern int nKota;

void  tambahKota(const char *namaKota);
void  tambahNama(const char *namaKota, const char *nama);
void  hapusKota (const char *namaKota);
void  tampilkanSemua(void);
void  tampilkanPerKota(const char *namaKota);
int   cariKota(const char *namaKota);

#endif
