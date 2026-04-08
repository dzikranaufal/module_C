Program Latihan2
Main
Deklarasi:
    jumlahBuku : integer
    judulBuku : array [jumlahBuku] string
    tahunTerbit : array [jumlahBuku] integer
    i : integer
Algoritma:
    INPUT jumlahBuku

    FOR i = 0 TO jumlahBuku - 1
        OUTPUT "Judul buku ke-", i + 1, ": "
        INPUT judulBuku[i]

        OUTPUT "Tahun terbit : "
        INPUT tahunTerbit[i]

    daftarBuku(jumlahBuku, judulBuku, tahunTerbit)

PROCEDURE Daftar Buku(jumlahBuku : integer, judulBuku : array string, tahunTerbit : array integer)
    OUTPUT "Daftar Buku Perpustakaan:"
    FOR i = 0 TO jumlahBuku - 1
        OUTPUT "Buku No.", i + 1
        OUTPUT "Judul : ", judulBuku[i]
        OUTPUT "Terbit: ", tahunTerbit[i]