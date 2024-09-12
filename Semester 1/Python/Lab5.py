a=int(input('Please enter the first number: '))
b=int(input('Please enter the second number: '))
c=int(input('Please enter the third number: '))
if a>b and a>c:
    print(a,' is the largest')
elif b>a and b>c:
    print(b,' is the largest')
else:
    print(c,' is the largest')