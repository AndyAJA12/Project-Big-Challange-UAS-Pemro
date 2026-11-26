#ifndef WORDLIST_H
#define WORDLIST_H

/*
 * ============================================================
 * ATURAN URUT FINAL (sesuai jawaban dosen):
 * 1. Frekuensi menurun (terbesar ke terkecil).
 * 2. Jika frekuensi sama, urut alfabetis A ke Z (strcmp < 0).
 *    Catatan: Aturan "lebih panjang dulu" TIDAK dipakai.
 * 3. Opsi 1: Data diurutkan SEBELUM ditulis ke file binari.
 *
 * KESEPAKATAN TIM:
 * - Nama file binari: hasil10.bin (pakai NAMA_FILE_BIN)
 * - Karakter '\0' TIDAK ditulis ke file binari (tulis sebanyak 'panjang').
 * - Saat membaca di binread, tambahkan '\0' manual di akhir kata.
 * - Tanda hubung ('-') dipecah menggunakan strtok di cleaner.
 * ============================================================
 */

#define JUMLAH_ABJAD 26
#define MAX_PANJANG_KATA 50
#define MAX_KATA_PER_ABJAD 5000
#define NAMA_FILE_BIN "hasil10.bin"

// Struct untuk satu kata unik
typedef struct {
    char kata[MAX_PANJANG_KATA];
    int panjang;
    int frekuensi;
} Kata;

// Struct untuk kumpulan kata per abjad (indeks 0 = 'a', ..., 25 = 'z')
typedef struct {
    char abjad;
    int jumlah;
    Kata daftar[MAX_KATA_PER_ABJAD];
} DaftarAbjad;

// Prototipe fungsi modul wordlist (A3)
void inisialisasi_wordlist(DaftarAbjad wl[]);
void tambah_kata(DaftarAbjad wl[], const char *kata_baru);
int hitung_total_unik(DaftarAbjad wl[]);

#endif