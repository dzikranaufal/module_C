Program Latihan2
Main
Deklarasi:
    nama : string
    skor : float

Algoritma:
    OUTPUT "Nama Atlet: "
    INPUT nama
    OUTPUT "Skor Lari (detik): "
    INPUT skor
    cekSkor(nama, skor)


PROCEDURE cekSkor(nama : string, skor : float)
    OUTPUT ""
    OUTPUT "--- Hasil Evaluasi ---"
    IF skor <= 12.0 THEN
        OUTPUT "Atlet atas nama ", nama, " dinyatakan LOLOS seleksi"
    ELSE
        OUTPUT "Atlet atas nama ", nama, " dinyatakan TIDAK LOLOS seleksi"