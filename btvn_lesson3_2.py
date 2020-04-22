'''
Bài 02: Viết chương trình để xóa bỏ ký tự thứ m trong chuỗi không rỗng, với m là số không âm, nhập từ bàn phím.
'''
s = input("Nhap chuoi: ")
m = int(input("Nhap m = "))
while True:
    if s == "" or m < 0 or m > len(s):
        print("Gia tri ban nhap khong hop le. Hay nhap lai.")
        s = input("Nhap chuoi: ")
        m = int(input("Nhap m = "))
        break
print(s.replace(s[m], ""))