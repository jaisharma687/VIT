n=int(input('Please enter the number: '))
k=1
for i in range(0,n):
    for j in range(0,i+1):
        print(k, end=' ')
        k=k+1
    print()