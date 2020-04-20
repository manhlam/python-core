#Nhap vao 3 so  a, b ,c bat ki.
#Giai va bien luan ptb2 ca nghiem phuc

from math import sqrt
from math import fabs #Tu thu vien math import module fabs - tri tuyet doi

print("Giai va bien luan phuong trinh bac 2.")
a = float(input("\nNhap vao a = "))
b = float(input("\nNhap vao b = "))
c = float(input("\nNhap vao c = "))
print("\nPhuong trinh co dang: {} * x**2 + {} * x +{} = 0".format(a,b,c)) #in ra phuong trinh bac 2.

if a == 0: #Dieu kien a = 0:
    if b == 0: #Dieu kien b = 0
        if c == 0:
            print("\nPhuong trinh da cho vo so nghiem.")
        else:
            print("\nPhuong trinh da cho vo nghiem.")
    else:
        if c == 0:
            print("\nPhuong trinh da cho vo so nghiem.")
        else:
            print("\nPhuong trinh co nghiem duy nhat: x = {}".format(-c/b))
else:
    if b == 0: #Dieu kien b != 0
        if c == 0:
            print("\nPhuong trinh da cho co nghiem x = 0.")
        else:  #Do a* x ** 2 + c = 0 => x**2 = -c/a ton tai nghiem complex
            if a * c < 0:
                print("\nPhuong trinh da cho co nghiem: x = {}".format(sqrt(-c/a)))
            else: #a * c > 0
                print("\nPhuong trinh da cho co nghiem x = {}".format(complex(0, sqrt(c/a))))
    else:
        if c == 0:
            print("\nPhuon trinh co hai nghiem la: ")
            print("\nx1 = 0")
            print("\nx2 = {}".format(-b/a))
        else:
            delta = b ** 2 - 4 * a * c
            if delta > 0:
                print("\nPhuong trinh co hai nghiem: ")
                print("\nx1 = {}".format((-b + sqrt(delta))/ (2 * a)))
                print("\nx2 = {}".format((-b - sqrt(delta)) / (2 * a)))
            elif delta == 0:
                print("\nPhuong trinh da cho co nghiem kep; x = {}".format(-b/2*a))
            else :
                print("\nPhuong trinh da cho co 2 nghiem phuc phan biet: ")
                print("\nx1 = {}".format(complex(-b/2*a , sqrt(fabs(delta)) / 2*a)))
                print("\nx2 = {}".format(complex(-b/2*a , -sqrt(fabs(delta)) / 2*a)))






