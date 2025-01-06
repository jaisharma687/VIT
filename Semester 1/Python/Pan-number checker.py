pan=input('Please enter a pan-number')
alpha1=pan[0:5]
numeric=pan[5:9]
if len(pan)==10:
    if alpha1.isalpha()==True and numeric.isalpha()==True and pan[-1].isalpha()==True:
        print('The pan-number is valid')
    else:
        print('Invalid pan-number')
else:
    print('Invalid pan-number')