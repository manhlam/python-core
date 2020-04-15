#Write a Python program to accept a filename from the user and print the extension of that.

filename = input("Input filename : ")
filename_extension = filename.split(".")
print ("Extention is : " + repr(filename_extension[-1]))


#Input filename : bai7_w3.py
#Extention is : 'py'