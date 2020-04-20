#Kiem tra tam giac:
print("Nhap vao do dai 3 canh: ")
a = float(input("\nNhap vao a = "))
b = float(input("\nNhap vao b = "))
c = float(input("\nNhap vao c = "))

if a < 0 or b < 0 or c < 0:
    print("\nDo dai ban vua nhap khong hop le. Hay nhap lai!")
else:
    if a + b < c or b + c < a or a + c < b:
        print("\nDo dai 3 canh khong hinh thanh duoc tam giac.Hay nhap lai!")
    else:
        if a**2 + b**2 == c**2 or b**2 + c**2 == a**2 or a**2 + c**2 == b**2:
            print("\nTam giac vuong.")
        else:
            print("\nDo dai ban vua nhap la 3 canh cua tam giac")