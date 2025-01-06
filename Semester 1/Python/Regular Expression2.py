import re
reg_number=input('Please enter your reg number ')
if re.match('^[0-9]{2}[A-Z]{3}[0-9]{4}$', reg_number):
    print('Matched')
else:
    print('Not Matched')