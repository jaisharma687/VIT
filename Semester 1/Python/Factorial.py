num=int(input('Please enter the number for factorial: '))
a=1
if num<0:
    print('Factorial not possible')
else:    
    for i in range(num,0,-1):
            print(a)
            a=a*i
    print('The factorial of ',num ,' is ', a)
