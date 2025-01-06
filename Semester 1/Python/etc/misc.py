# x = 5
# for i in range(x):
#     x = x+1
#     print(x)
#     x += 1
    
import re

def emailValidity(email):
    pattern = r'^[a-zA-Z0-9.-]+@[a-zA-Z0-9-]+\.[a-z]{2,}$'
    return True if re.match(pattern,email) else False

emails = ['example@example.com', 'invalid-email', 'anotherexample@gmail.com']
for i in emails:
    if emailValidity(i):
        print(f"{i} passes validation")
    else:
        print(f"{i} does not pass validation")
