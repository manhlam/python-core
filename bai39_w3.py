#Write a Python program to compute the future value of a specified principal amount,
# rate of interest, and a number of years

tien_von = float(input("Nhap so tien von cua ban: "))
he_so_lai = float(input("Nhap he so lai: "))
tgian = float(input("Nhap so nam ban muon gui ngan hang: "))

tong_tien = tien_von * (1 + he_so_lai) ** tgian
print(round(tong_tien, 2))