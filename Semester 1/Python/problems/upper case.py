#  Write a Python function to convert a given string to all uppercase if it contains at least 2 
# uppercase characters in the first 4 characters.

str_inp = input()
str_inp_first4 = ""
for i in range(4):
    str_inp_first4 += str_inp[i]
# print(str_inp_first4)
counter = 0
for char in str_inp_first4:
    if char.isupper():
        counter += 1
    else:
        counter += 0
if counter > 1:
    print(str_inp.upper())
else:
    print(str_inp)
