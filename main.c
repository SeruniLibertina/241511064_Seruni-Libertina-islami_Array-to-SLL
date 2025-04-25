#include "kota.h"

int main(void) {
    int pil;
    char namaKota[MAX_STR], namaOrang[MAX_STR];

    do {
        puts("\n=== MENU ===");
        puts("1. Tambah Kota");
        puts("2. Tambah Nama pada Kota");
        puts("3. Hapus Kota");
        puts("4. Tampilkan Semua");
        puts("5. Tampilkan Nama per Kota");
        puts("0. Keluar");
        printf("Pilihan: ");  scanf("%d", &pil); getchar();

        switch (pil) {
        case 1:
            printf("Nama kota: ");
            fgets(namaKota, sizeof namaKota, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            tambahKota(namaKota);
            break;
        case 2:
            printf("Nama kota: ");
            fgets(namaKota, sizeof namaKota, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            printf("Nama orang: ");
            fgets(namaOrang, sizeof namaOrang, stdin);
            namaOrang[strcspn(namaOrang, "\n")] = 0;
            tambahNama(namaKota, namaOrang);
            break;
        case 3:
            printf("Kota yang dihapus: ");
            fgets(namaKota, sizeof namaKota, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            hapusKota(namaKota);
            break;
        case 4: tampilkanSemua();               break;
        case 5:
            printf("Nama kota: ");
            fgets(namaKota, sizeof namaKota, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            tampilkanPerKota(namaKota);
            break;
        case 0: puts("Bye!");                   break;
        default: puts("Pilihan tidak valid.");
        }
    } while (pil != 0);

    return 0;
}
