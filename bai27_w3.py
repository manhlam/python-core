#Write a Python program to concatenate all elements in a list into a string and return it.

def concentrate_list_data(list):
    result = ''
    for element in list:
        result += str(element)
    return result

print(concentrate_list_data([2,5,8,3,7,5,2,8,9]))

