num=int(input('Please enter the number: '))
x=0
for i in range(2,num-1):
    if num%i!=0:
        x=0
        continue
    elif num%i==0:
        x=1
        print(num,'is a composite')
        break

if x==0:
        print('The number is a prime number')
