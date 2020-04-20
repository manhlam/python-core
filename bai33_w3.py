#Write a Python program to sum of two given integers.
# However, if the sum is between 15 to 20 it will return 20.

# x = int(input("Nhap vao so nguyen x = "))
# y = int(input("Nhap vao so nguyen y = "))
# sum = x + y
# if sum >= 15 and sum <= 20:
#     print("sum = 20")
# else:
#     print(sum)


def sum(x, y):

    sum = x + y
    if sum in range(15,20):
        return 20
    else:
        return sum
print(sum(2,5))
print(sum(10, 7))