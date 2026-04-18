def cek_status(sampah, telat):
    if sampah == "ya" and telat == "ya":
        return "Usir"
    elif sampah == "ya" or telat == "ya":
        return "SP1"
    else:
        return "Aman"

def statusKamar(nama, status, sampah, telat):
    if status == "Usir":
        print(f"{nama} diusir dari kosan!")
        return "KOSONG"
    elif status == "SP1":
        if sampah == "ya" and telat == "tidak":
            print(f"{nama} dapet Surat Peringatan 1. Bersihin kamar woy!")
        elif sampah == "tidak" and telat == "ya":
            print(f"{nama} dapet Surat Peringatan 1. Segera bayar!")
        else: 
            print(f"{nama} dapet Surat Peringatan 1. Bersihin kamar & segera bayar!")
        return nama
    else:
        print(f"{nama} anak baik, pertahankan!")
        return nama

print("=== RAZIA KOS-KOSAN BULAN INI ===")

kamar = ["", "", ""]

for i in range(1, 4):
    if i == 1:  
        nama = "Jokowi"
    elif i == 2:
        nama = "Bahlil"
    else:
        nama = "Prabowo"

    print(f"Mengetuk Kamar {i} (Penghuni: {nama})")
    
    sampah = input("Banyak tumpukan sampah? (ya/tidak): ")
    telat = input("Apakah telat bayar kost? (ya/tidak): ")

    status = cek_status(sampah, telat)
    hasil = statusKamar(nama, status, sampah, telat)

    kamar[i-1] = hasil

    print() 

print("=== STATUS KAMAR KOSAN TERBARU ===")
for i in range(3):
    print(f"Kamar {i+1}: {kamar[i]}")