#Write a Python program to calculate number of days between two dates.
from datetime import date
first_date = date(2020, 4, 3)
last_date = date(2021, 4, 14)
d = last_date - first_date
print(d.days)