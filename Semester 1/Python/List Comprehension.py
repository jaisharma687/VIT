x=input('Enter a number: ').split(',')
l=[int(i) for i in x]
print(type(l[1]))
print(sum(l))
avg=sum(l)/len(l)
print(avg)