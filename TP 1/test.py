# def fpb(a,b):
#     while b!=0:
#         r = a%b # 18%12 = 6
#         a = b # 12
#         b = r # 6
#     return a

# print(fpb(18, 12))

# for i in range(1, 6):
#     print(7*i)

# text = "UPI"
# k = 3
# result = ""
# for char in text:
#     angka = ord(char) - ord('A')  # Mengubah karakter menjadi angka (0-25)
#     enkripsi = (angka + k) % 26  # Melakukan enkripsi dengan pergeseran k
#     result += chr(enkripsi + ord('A'))  # Mengubah kembali angka menjadi karakter
# print(result)

# n = 60
# faktor = []
# for i in range(1, n+1):
#     if n % i == 0:
#         faktor.append(i)
# print(faktor)

a, n = 3, 7
print(pow(a, n))