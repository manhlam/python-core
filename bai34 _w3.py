#Write a Python program to sum of three given integers. However, if two values are equal sum will be zero.

def sum(x, y, z):
    sum = x + y + z
    if x == y or y == z or x == z:
        return 0
    else:
        return sum

print(sum(1, 2, 3))
print(sum( 5, 3, 5))