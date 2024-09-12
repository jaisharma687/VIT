# num=int(input('Please enter the number: '))
for num in range(2,21):
    if(num==15):
        continue
    for i in range(1,11):
        print(num,'x',i,'=',num*i)
    print('\n-----------------------\n')