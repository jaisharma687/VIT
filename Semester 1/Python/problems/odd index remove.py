# Write a Python program to remove the characters which have odd index values of a given 
# string.

str_inp = input()
str_new = ""
for char in str_inp:
    if str_inp.index(char) in range(0,len(str_inp),2):
        str_new += char
print(str_new)