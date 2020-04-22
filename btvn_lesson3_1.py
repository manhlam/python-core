#Bài 01: Viết chương trình thay thế tất cả các ký tự giống ký tự đầu tiên của một Chuỗi thành $

s = input("Nhap chuoi: ")
for i in s:
    if i == s[0]:
        print(s.replace(i, '$'))
        break