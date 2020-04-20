#Write a Python program which will return true
# if the two given integer values are equal or their sum or difference is 5

def test_number_5(x, y):
    if (x == y) or (x + y) == 5 or (x - y) == 5:
        return True
    else:
        return False
    
print(test_number_5(2, 3))
print(test_number_5(8, 8))
print(test_number_5(7, 4))