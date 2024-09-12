integers=input('Enter the integers: ').split(',')
integ=[int(i) for i in integers]
x=0
y=0
for i in integ:
    if i>=0:
        x=x+1
    elif i<0:
        y=y+1
percentage_positive=(x/len(integ))*100
precentage_negative=(y/len(integ))*100
print('Percentage of positive: ',format(percentage_positive,'.3f'))
print('Percentage of negative: ',format(precentage_negative,'.3f'))