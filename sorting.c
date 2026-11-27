#include <string.h>
#include "sorting.h"

// Fungsi pembantu untuk memeriksa apakah urutan dua kata perlu ditukar
// Return 1 jika posisi harus ditukar, return 0 jika sudah benar
static int harus_tukar(const Kata *a, const Kata *b) {
    // 1. Prioritas utama: frekuensi lebih besar ditaruh lebih dulu
    if (a->frekuensi < b->frekuensi) {
        return 1;
    }
    
    // 2. Jika frekuensi sama: urutkan secara alfabetis A ke Z
    // strcmp(a, b) > 0 artinya kata 'a' secara kamus berada setelah kata 'b'
    if (a->frekuensi == b->frekuensi) {
        if (strcmp(a->kata, b->kata) > 0) {
            return 1;
        }
    }

    return 0;
}

// Mengurutkan kata di seluruh abjad ('a' sampai 'z') menggunakan Bubble Sort
void urutkan_semua(DaftarAbjad wl[]) {
    for (int i = 0; i < JUMLAH_ABJAD; i++) {
        int n = wl[i].jumlah;
        
        // Lewati jika abjad kosong atau hanya berisi 1 kata
        if (n <= 1) {
            continue;
        }

        // Algoritma Bubble Sort
        for (int step = 0; step < n - 1; step++) {
            for (int j = 0; j < n - 1 - step; j++) {
                if (harus_tukar(&wl[i].daftar[j], &wl[i].daftar[j + 1])) {
                    // Tukar posisi kata
                    Kata temp = wl[i].daftar[j];
                    wl[i].daftar[j] = wl[i].daftar[j + 1];
                    wl[i].daftar[j + 1] = temp;
                }
            }
        }
    }
}