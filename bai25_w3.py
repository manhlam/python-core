#Write a Python program to check whether a specified value is contained in a group of values

def danh_sach(group_data, n):
    for x in group_data:
        if n == x :
            return True
    return False

print(danh_sach([1,2,3,4,5,6,7,7,8,9], 14))
print(danh_sach([1,2,3,4,5,6,7,7,8,9], 9))