n=int(input('Please enter the number of times for * to print: '))
for i in range(1,n+1):
    print(' '*(n-i),"*"*i)
for j in range(n, 0, -1):
    print(' '*(n-j+1),"*"*(j-1))