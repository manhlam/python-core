#coding = utf-8

#Nhap tu ban phim vao 1 so va kiem tra am hay duong?
'''
Bien Boolean gom 2 gia tri True hoac False
Cac phep toan cua Boolean
        not x  => phu dinh cua x. True neu x False va nguoc lai.
        x and y => Kiem tra dk dong thoi. True neu ca 2 x va y deu True, va False trong TH con lai.
        x or y => Phep toan Hoac kiem tra 1 trong 2 dieu kien dung. Nhan gia tri False neu ca x va y deu False
                   va False voi truong hop con lai.

'''
# a = True # => 1
# b = False # => 0
# c = False
# # print(a and b)
# # print(a or b)
# # print(not a)
# # print(not b)
# # print(b and c)
# # print(b or c)
# print(a + 9)
# print(b + 9)
# print("not a is ", not a )
# print("not b is ", not b )
# print("a or b is ", a or b)
# print("a and b is ", a and b)
# print(not 1)
# print(not 0)

'''
Cac phep toan so sanh: 
         phep toan                                   y nghia
         ==                                     gia tri bang nhau. True neu 2 ben bang nhau
         !=                                     so sanh khac. True neu 2 ben khac nhau
         >                                      True neu ben trai lon hon ben phai
         >=
         <                                      True neu ben trai nho hon ben phai
         <=                                     
'''
# x = 2000
# y = 3000
# print(x == y)
# print(x < y)
# print(x > y)
# print(x != y)
# print(x >= y)
# print(x <= y)

'''Conditional Statement - Cau lenh re nhanh.
    + if bieu_thuc_dieu_kien:
           Cac cau lenh se duoc thuc thi neu bieu thuc dieu kien co gia tri True
    + if bieu_thuc_dk:
           Cac cau lenh se duoc thuc thi neu bieu thuc dieu kien co gia tri True
      else : 
           cau lenh can chay neu bieu thuc dk False
    + if bieu_thuc_dk1: 
           Cau lenh can chay bieu thuc dk1 True
       elif bieu_thuc_dk2:
           Cau lenh can chay neu bieu thuc dk2 dung
        elif bieu_thuc_dk n: 
            .....
        else: 
            chay khi cac bieu thuc dieu kien tren sai. 
'''
# n = int(input())
# if n < 0:
#     print('n = {} la so am'. format(n))
# elif n > 0:
#     print('n = {} la so duong'. format(n))
# else:
#     print('n = {}'.format(n))

# x = int(input("Nhap vao x = "))
# y = int(input("Nhap vao y = "))
# if x > 0 and y > 0:
#     print("Tong x + y = ", x + y)
# elif x < 0 and y < 0:
#     print("Tich x * y = ", x * y)
# else:
#  if x < y:
#     print (x)
#  else:
#     print(y)
#       #print(a) ìf a < b else print(b)

'''
Gan gia tri
'''
# a = 10 #Gan gia tri
# # a = 2 * a + 6 #Cap nhạt gia tri moi cua a
# # print(a)
# a %= 2
# print (a)

'''Loop - Vong lap: Co 2 dang for va while 
'''
# for i in range(0, 10, ):
#     print(i)

#Nhap vao 2 so nguyen a va b,  in ra cac so nam giua a va b tren cung 1 dong, thoe chieu tang dan.
# a = int(input())
# b = int(input())
# if a < b:
#     for i in range(a + 1, b):
#         print(i, end=" ")
# else:
#     for i in range(b + 1, a):
#         print(i, end=" ")

# a, b = int(input( )), int(input( )) #cho phep nhap nhieu gia tri
# if a > b:
#     a, b = b, a #Dao vi tri
# for i  in range(a, b+1):
#     print(i, end = " ")

# if a < b:
#     step = 1
# else:
#     step = -1
# for i in range(a, b+1, step):
#     print(i, end=" ")

#Tinh giai thua cua n
# n = int(input())
# result = 1
# for i in range(1, n + 1):
#     result *= i
# print(result)

#Ma tran 8 hinh chu nhat
# a, b = int(input( )), int(input( ))
# for i in range(a):
#     for j in range(b):
#         print("*", end = " ")
#     print()

# n = int(input())
# i = 0
# sum_n = 0
# while(i <= n):
#     sum_n +=i
#     i += 1
# print("Tong gia tri tu 1 den {} la {}". format(n, sum_n))

#Break - Continue
for i in range(10,100):
    if i % 2 == 0 or i % 3 == 0 or i % 5 == 0:
        continue
    print(i, end = " ")








