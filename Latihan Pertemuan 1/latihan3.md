Program Latihan3.c
Deklarasi:
    array : array[4][3] char
    i : integer
    j : integer

Algoritma:
FOR i = 0 TO 2
    FOR j = 0 TO 3
        OUTPUT "Masukkan Baris[", i + 1, "] Kolom[", j + 1, "]: "
        INPUT array[i][j]

OUTPUT ""
OUTPUT "Isi Array :"

FOR i = 0 TO 2
    FOR j = 0 TO 3
        OUTPUT array[i][j], " "
    OUTPUT ""      // pindah baris



