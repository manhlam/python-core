#Tinh tong day so:
from math import factorial as fact

x = int(input("Nhap vao gia tri x = "))
n = int(input("Nhap vao gia tri n = "))

S1 = 0
S2 = 0
S3 = 0

for i in range(0, n + 1):
    S1 += x ** i
    S2 += (-x) ** i
    S3 += (x ** i) / fact(i)
    
print(S1)
print(S2)
print(S3)