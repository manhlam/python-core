#Write a Python program to test whether a number is within 100 of 1000 or 2000.

def near_thousand(n):
    return (abs(100 - n) <= 100) and (abs(2000 - n) <= 100)
   # return (abs(100 - n) <= 100) or (abs(2000 - n) <= 100)
print(near_thousand(1001))
print(near_thousand(900))
print(near_thousand(1998))
print(near_thousand(2003))