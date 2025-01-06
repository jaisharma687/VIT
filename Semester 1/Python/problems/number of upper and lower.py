# Write a Python function that accepts a string and calculate the number of upper-case letters 
# and lower-case letters.
# Input Format:
# A string 
# Output Format:
# Number of upper-case letters
# Number of lower-case letters

str_input = input("enter the string: ")
uc = 0
lc = 0
for i in str_input:
    if i.isupper():
        uc += 1
        lc += 0
    if i.islower():
        lc += 1
        uc += 0
    else:
        uc += 0
        lc += 0
print(uc)
print(lc)