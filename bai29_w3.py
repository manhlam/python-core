#Write a Python program to print out a set containing all the colors from color_list_1
# which are not present in color_list_2.

color_list_1 = set(["white", "Black", "Red"])
color_list_2 = set(["Red", "Blue", "Pink"])

print(color_list_1.difference(color_list_2))

