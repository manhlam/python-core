#Write a Python program to add two objects if both objects are an integer type.

def add_number(a, b):
    if not ( isinstance(a, int) and isinstance(b, int)):
        raise TypeError("Inputs must be intergers.")
    return a + b

print(add_number(1, 5))
print(add_number(10, 20))
