#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "wordlist.h"

// Mengosongkan data dan memberi label 'a' sampai 'z'
void inisialisasi_wordlist(DaftarAbjad wl[]) {
    for (int i = 0; i < JUMLAH_ABJAD; i++) {
        wl[i].abjad = 'a' + i;
        wl[i].jumlah = 0;
    }
}

// Menambah kata baru atau menaikkan frekuensi jika kata sudah ada
void tambah_kata(DaftarAbjad wl[], const char *kata_baru) {
    if (kata_baru == NULL || kata_baru[0] == '\0') {
        return;
    }

    // Tentukan indeks abjad berdasarkan huruf pertama ('a' -> 0, 'b' -> 1, dst.)
    char huruf_awal = tolower((unsigned char)kata_baru[0]);
    if (huruf_awal < 'a' || huruf_awal > 'z') {
        return;
    }
    int idx = huruf_awal - 'a';

    // 1. Cari apakah kata sudah pernah dicatat di abjad tersebut
    for (int i = 0; i < wl[idx].jumlah; i++) {
        if (strcmp(wl[idx].daftar[i].kata, kata_baru) == 0) {
            wl[idx].daftar[i].frekuensi++;
            return; // Selesai, frekuensi bertambah
        }
    }

    // 2. Jika belum ada, masukkan sebagai kata baru
    if (wl[idx].jumlah < MAX_KATA_PER_ABJAD) {
        int pos = wl[idx].jumlah;
        
        strncpy(wl[idx].daftar[pos].kata, kata_baru, MAX_PANJANG_KATA - 1);
        wl[idx].daftar[pos].kata[MAX_PANJANG_KATA - 1] = '\0';
        wl[idx].daftar[pos].panjang = (int)strlen(wl[idx].daftar[pos].kata);
        wl[idx].daftar[pos].frekuensi = 1;
        
        wl[idx].jumlah++;
    } else {
        printf("Peringatan: Kapasitas abjad '%c' penuh!\n", huruf_awal);
    }
}

// Menghitung akumulasi seluruh kata unik dari abjad 'a' sampai 'z'
int hitung_total_unik(DaftarAbjad wl[]) {
    int total = 0;
    for (int i = 0; i < JUMLAH_ABJAD; i++) {
        total += wl[i].jumlah;
    }
    return total;
}