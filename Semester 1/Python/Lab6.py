math=float(input('Please enter the marks in Mathematics: '))
phy=float(input('Please enter the marks in Physics: '))
chem=float(input('Please enter the marks in Chemistry: '))

avg=(math+phy+chem)/3
if avg<10:
    print('Commit suicide')
elif 10<avg<20:
    print("Don't tell your family")
elif 20<avg<30: