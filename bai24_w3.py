#Write a Python program to test whether a passed letter is a vowel or not

def am_tiet(char):
    cac_nguyen_am = "ueoai"
    return char in cac_nguyen_am
print(am_tiet("c"))
print(am_tiet("o"))
print(am_tiet("i"))
