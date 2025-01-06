# Write a Python program to get a single string from two given strings, separated by a space 
# and swap the first two characters of each string.
# Sample String : 'abc', 'xyz'
# Expected Result : 'xyc abz'

str_1 = input()
str_2 = input()

str_final = str_2 + " " + str_1
print(str_final)