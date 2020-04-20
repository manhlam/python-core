# # Lập chương trình thực hiện các công việc sau:
#     Nhập 1 số nguyên dương n bất kì (n<1000). Yêu cầu kiểm tra dữ liệu đầu vào, nếu sai yêu cầu nhập lại.
#     Tính tổng các chữ số của số đó.
#     Hiển thị kết qủa ra màn hình

n = int(input("Nhap vao so nguyen n = "))
sum = 0

while n < 1000 :
    if n > 0 and n < 1000:
        print("\nSo ban nhap la phu hop.")
        for i in range(0, n + 1):
            sum += i
        print("Tong cac chu so tu 1 den {} la: {}".format(n, sum))
        break
    print("\nSo ban nhap khong hop le. Hay nhap lai! \nn = ")



