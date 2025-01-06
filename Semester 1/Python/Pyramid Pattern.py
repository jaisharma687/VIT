a=int(input())
num=a*2
for i in range(0, num, 2):
    print(' '*(num+1-i//2), end='')
    for j in range(0,i+1):
        print('*',end='')
    print()
