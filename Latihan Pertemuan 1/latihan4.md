Program Latihan4
Deklarasi:
    data : array [2][2][2] of integer
    nama_ruangan : array [2] of string
    nama_waktu : array [2] of string
    i : integer
    j : integer
    k : integer
    total_lampu_menyala : integer
Algoritma:
    SET nama_ruangan[0] = "Ruang Tamu"
    SET nama_ruangan[1] = "Kamar Tidur"
    SET nama_waktu[0] = "Pagi"
    SET nama_waktu[1] = "Malam"
    SET total_lampu_menyala = 0      

    FOR i = 0 TO 1
        FOR j = 0 TO 1
            FOR k = 0 TO 1
                OUTPUT "HARI ", i + 1, ", ", nama_ruangan[j], ", ", nama_waktu[k], " (0/1): "
                INPUT data[i][j][k]

                IF data[i][j][k] = 1 THEN
                    total_lampu_menyala = total_lampu_menyala + 1
                    
    OUTPUT "--- Laporan Riwayat Lampu ---"
    FOR i = 0 TO 1
        OUTPUT "HARI ", i + 1
        FOR j = 0 TO 1
            OUTPUT nama_ruangan[j], ": "
            OUTPUT "[Pagi : "
            IF data[i][j][0] = 1 THEN
                OUTPUT "NYALA"
            ELSE
                OUTPUT "MATI"
            OUTPUT "] [Malam : "
            IF data[i][j][1] = 1 THEN
                OUTPUT "NYALA"
            ELSE
                OUTPUT "MATI"
            OUTPUT "]"

    OUTPUT "Total lampu menyala selama 2 hari: ", total_lampu_menyala, " kali"