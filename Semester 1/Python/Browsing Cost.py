minutes_browsed=int(input('Please enter the minutes browsed: '))
hours=minutes_browsed/60
if hours>7:
    print("Error\nCannot browse for more than 7 hours")
elif hours<1:
    bill=minutes_browsed
    print('Total bill is', bill)
elif 1<hours<2:
    bill=50+(minutes_browsed-60)
    print('Total bill is ',bill)
elif 2<hours<3:
    bill=100+(minutes_browsed-120)
    print('Total bill is ', bill)
elif 3<hours<4:
    bill=150+(minutes_browsed-180)
    print('Total bill is ', bill)
elif 4<hours<5:
    bill=200+(minutes_browsed-240)
    print('Total bill is ', bill)
elif 5<hours<6:
    bill=200+(minutes_browsed-300)
    print('Total bill is ', bill)
elif 6<hours<7:
    bill=250+(minutes_browsed-360)
    print('Total bill is', bill)



elif hours==1:
    print('Total bill is ', 50)
elif hours==2:
    print('Total bill is ', 100)
elif hours==3:
    print('Total bill is ', 150)
elif hours==4:
    print('Total bill is ', 200)
elif hours==5:
    print('Total bill is ', 200)
elif hours==6:
    print('Total bill is ', 250)
elif hours==7:
    print('Total bill is ', 300)