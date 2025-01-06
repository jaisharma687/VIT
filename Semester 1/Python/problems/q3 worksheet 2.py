# Write a Python program to get a string made of the first 2 and the last 2 chars from a given a 
# string. If the string length is less than 2, return instead of the empty string.
# Sample String : 'w3resource'
# Expected Result : 'w3ce'
# Sample String : 'w3'
# Expected Result : 'w3w3'
# Sample String : ' w'
# Expected Result : Empty String

string_inp = input()
if 0 <= len(string_inp) < 2:
    print("Empty String")
else:
    for char in string_inp:
        str_1 = ""
        str_2 = ""
        n = len(string_inp)
        for i in range(0,2):
            str_1 += string_inp[i]
        for j in range(n-2,n):
            str_2 += string_inp[j]
        str = str_1 + str_2
print(str)