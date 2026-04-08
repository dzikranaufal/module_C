Program Latihan1
Deklarasi:
    jumlah_peserta : integer
    i : integer
    total_skor : integer
    skor_peserta : array[jumlah_peserta] integer

Algoritma:
OUTPUT "Masukkan Jumlah Peserta:"
INPUT jumlah_peserta
SET total_skor = 0      

FOR i = 0 TO jumlah_peserta-1
    INPUT skor_peserta[i]
    total_skor = total_skor + skor_peserta[i]

OUTPUT "Daftar Skor Peserta:"
FOR i = 0 TO jumlah_peserta-1
    OUTPUT "Skor Peserta ke-", i+1, ":", skor_peserta[i]

OUTPUT "Total Skor Semua Peserta:", total_skor

