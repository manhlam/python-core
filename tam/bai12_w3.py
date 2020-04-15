#Write a Python program to print the calendar of a given month and year.
import calendar
y = int(input("Nhap vao nam: "))
m = int(input("Nhap vao thang: "))
print(calendar.month(y, m))

