def hitung_total(paket, jumlah):
    if paket == "1":
        harga = 15000
    elif paket == "2":
        harga = 25000
    elif paket == "3":
        harga = 50000
    else:
        return 0
    
    return harga * jumlah


while True:
    print("=== Menu Warung Digital ===")
    print("1. Paket Hemat (Rp15.000)")
    print("2. Paket Kenyang (Rp25.000)")
    print("3. Paket Sultan (Rp50.000)")
    print("Ketik 'selesai' untuk keluar")

    paket = input("Pilih paket (1/2/3): ")

    if paket == "selesai":
        break

    jumlah = int(input("Masukkan jumlah pesanan: "))

    total = hitung_total(paket, jumlah)

    print(f"Total awal: Rp{total}")

    if total > 200000:
        total = total * 0.8
    elif total > 100000:
        total = total * 0.9

    print(f"Total yang harus dibayar setelah diskon: Rp{total}")