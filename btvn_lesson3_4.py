'''Bài 04: Viết chương trình sinh ra một chuỗi từ 2 ký tự đầu và 2 ký tự cuối trong chuỗi được nhập vào,
        nếu độ dài chuỗi nhỏ hơn 2 thì in ra chuỗi rỗng.'''
s = input("Nhap chuoi: ")
if len(s) < 2:
    print("")
elif len(s) == 2:
    print("Chuoi moi duoc sinh ra la: " + s[:])
else:
    print("Chuoi moi duoc sinh ra la: "+ s[:2] + s[-2:])