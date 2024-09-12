import re
pan = input()
if len(pan) != 10:
    print("Invalid Input")
else:
    if re.match("^[A-Z]{5}[0-9]{4}[A-Z]$",pan):
        print("valid")
    else:
        print("invalid")