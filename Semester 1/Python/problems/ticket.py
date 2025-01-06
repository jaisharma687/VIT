# Q.1 Suppose you have designed an application for an online ticket booking system and validated 
# the password entered by the user. Write pseudocode and program to validate the password based 
# on the following rules:

# Primary conditions for password validation:
# 1. Minimum 8 characters.
# 2. The alphabets must be between [a-z]
# 3. At least one alphabet should be of Upper Case [A-Z]
# 4. At least 1 number or digit between [0-9].
# 5. At least 1 character from [ _ or @ or $ ].

# Input Format:
# Password entered by the user

# Output Format:
# Valid password
# Invalid password

import re
password = input()
symbol = 0
len_count = 0
re_search = 0
if len(password) < 8:
    len_count += 0 
else:
    len_count += 1 
    for i in password:
        if i == "@" or i == "_" or i == "$":
            symbol += 1
        elif re.search("[a-zA-Z0,9]$",password) == True:
            re_search += 1

if len_count >= 1 and symbol >= 1 and re_search >= 1 :
    print("valid password")
else:
    print("invalid password")