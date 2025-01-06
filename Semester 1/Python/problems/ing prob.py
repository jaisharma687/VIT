# Write a Python program to add 'ing' at the end of a given string (length should be at least 3). 
# If the given string already ends with 'ing' then add 'ly' instead. If the string length of the given 
# string is less than 3, leave it unchanged..

str_inp = input()
n = len(str_inp)
if n < 3:
    print(str_inp)
else:
    last_3str = ""
    for j in range(n-3,n):
        last_3str += str_inp[j]
    if last_3str == "ing":
        print(f"{str_inp}ly")
    else:
        print(f"{str_inp}ing")



